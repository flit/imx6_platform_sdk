/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file menu.c
 * @brief Menu Framework for application UI.
 * @ingroup diag_utility
 */

#include <stdio.h>
#include <string.h>
#include "sdk.h"
#include "text_color.h"
#include "menu.h"

////////////////////////////////////////////////////////////////////////////////
// Private Menu Framework Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Specialized menu_key_find() return values.
//@{
static const int MenuKeyFindNone = -2;         //!< menu_key_find() did not find any menuitems with a matching key.
static const int MenuKeyFindMoreThanOne = -1;  //!< menu_key_find() found more than one menuitem with a matching key.
//@}

////////////////////////////////////////////////////////////////////////////////
// Private Menu Framework Utility Functions
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Returns the number of menuitems in the menu.
 *
 * Counts all menuitems including MENUITEM_GROUP menuitems which are not
 * selectable. The count does not include the terminating MENUITEM_NULL element.
 *
 * @param   menu A pointer to the menu structure holding the menuitems to be counted.
 * @return  Number of menuitems.
 */
int menu_get_size(const menu_t* menu)
{
	int menuitem_count = 0;

	const menuitem_t* menuitem = menu->menuitems;
	while ( menuitem->type != MENUITEM_NULL )
	{
		++menuitem_count;
		++menuitem;
	}

	return menuitem_count;
}

/*!
 * @brief Searches the menu for menuitems that start with the key parameter.
 *
 * @note Search is not case sensitive.
 *
 * @param   menu A pointer to the menu structure holding the menuitems to be searched.
 * @param   key A pointer to search string used to identify a menuitem.
 * @retval  Index of the only menuitem that starts with the key parameter.
 * @retval  MenuKeyFindNone(-2) if a matching menuitem was not found.
 * @return  MenuKeyFindMoreThanOne(-1) if more than one matching menuitem was found.
 *          Call menu_key_find_first() to get the first matching index.
 */
int menu_key_find(const menu_t* menu, const char* key)
{
	int menuitem_found = MenuKeyFindNone;
	int num_found = 0;
	int menu_size = menu_get_size(menu);
	int index = 0;

	for ( index = 0; index < menu_size; ++index )
	{
		// Only consider selectable menuitems
		if ( menu->menuitems[index].type != MENUITEM_FUNCTION &&
			 menu->menuitems[index].type != MENUITEM_SUBMENU )
			continue;

		// Search is not case sensitive.
		if ( strncasecmp(key, menu->menuitems[index].key, strlen(key)) == 0 )
		{
			if ( menuitem_found == MenuKeyFindNone )
				menuitem_found = index;

			++num_found;
		}
	}

	return num_found == 0 ? MenuKeyFindNone : num_found > 1 ? MenuKeyFindMoreThanOne : menuitem_found;

}

/*!
 * @brief Returns the index of the first menuitem that starts with the key parameter.
 *
 * @note Search is not case sensitive.
 * @note This function would typically be called after menu_find_key() returned MenuKeyFindMoreThanOne.
 *
 * @param   menu A pointer to the menu structure holding the menuitems to be searched.
 * @param   key A pointer to search string used to identify a menuitem.
 * @retval  Index of the first menuitem that starts with the key parameter.
 * @retval  MenuKeyFindNone(-2) if a matching menuitem was not found.
 */
int menu_key_find_first(const menu_t* menu, const char* key)
{
	int menuitem_found = MenuKeyFindNone;
	int menu_size = menu_get_size(menu);
	int index = 0;

	for ( index = 0; index < menu_size; ++index )
	{
		// Only consider selectable menuitems
		if ( menu->menuitems[index].type != MENUITEM_FUNCTION &&
			 menu->menuitems[index].type != MENUITEM_SUBMENU )
			continue;

		// Search is not case sensitive.
		if ( strncasecmp(key, menu->menuitems[index].key, strlen(key)) == 0 )
		{
			menuitem_found = index;
			break;
		}
	}

	return menuitem_found;

}

/*!
 * @brief Default "Show Menu" handler.
 *
 * @param   context Menu context. Ignored.
 * @param   param Function specific parameter. Ignored.
 * @return  MENU_SHOW.
 */
menu_action_t menuitem_cmd_showmenu(const menu_context_t* context, void* param) { return MENU_SHOW; }

/*!
 * @brief Default "Exit Menu" handler.
 *
 * @param   context Menu context. Ignored.
 * @param   param Function specific parameter. Ignored.
 * @return  MENU_EXIT.
 */
menu_action_t menuitem_cmd_exitmenu(const menu_context_t* context, void* param) { return MENU_EXIT; }

/*!
 * @brief Print the menu description (header), all of the menuitems, and instructions to the user (footer).
 *
 * @param   indent String used to align text for the current menu level.
 * @param   menu Pointer to the menu to print.
 */
void menu_print(const char* indent, const menu_t* menu)
{
	if ( menu->header )
		printf("\n%s%s\n\n",  indent, menu->header);

	const menuitem_t* menuitem = menu->menuitems;
	while ( menuitem->type != MENUITEM_NULL )
	{

		switch (menuitem->type)
		{
			case MENUITEM_SUBMENU:
			case MENUITEM_FUNCTION:
			{
				printf("%s%s%s%s%s - %s\n", indent, g_TextAttributeBold, g_TextColorMagenta, menuitem->key, g_TextAttributeDefault, menuitem->description);

				break;
			}

			case MENUITEM_GROUP:
			{
				if ( menuitem->description )
					printf("\n%s%s%s%s:%s\n", indent, g_TextAttributeBold, g_TextColorBlue, menuitem->description, g_TextAttributeDefault);
				else
					printf("\n");

				break;
			}

			case MENUITEM_NULL:
			default:
			{
				break;
			}

		} // switch(menuitem->type)

		++menuitem;

	} // while ( menuitem->type != MENUITEM_NULL )

	if ( menu->footer )
		printf("\n%s%s\n",  indent, menu->footer);

} // menu_print()

/*!
 * @brief Print instructional text to help user execute the menu.
 *
 * @param   indent String used to align text for the current menu level.
 * @param   menu Pointer to the menu struct that contains the footer member to print.
 * @return  MENU_EXIT.
 */
void menu_print_footer(const char* indent, const menu_t* menu)
{
	if ( menu->footer )
		printf("\n%s%s\n",  indent, menu->footer);
	else
		printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
// Public Menu API Implementations
////////////////////////////////////////////////////////////////////////////////
void menu_make_menu(menu_t* menu, const char* header, const menuitem_t* menuitems, const char* footer)
{
	menu->header    = header;
	menu->menuitems = menuitems;
	menu->footer    = footer;
}

void menu_make_menuitem(menuitem_t* menuitem, const char* key, const char* description, menu_function_t func, void* func_param)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = key;
	menuitem->description = description;
	menuitem->submenu     = NULL;
	menuitem->func        = func;
	menuitem->param       = func_param;
}

void menu_make_menuitem_showmenu(menuitem_t* menuitem)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = "m";
	menuitem->description = "Display menu.";
	menuitem->submenu     = NULL;
	menuitem->func        = menuitem_cmd_showmenu;
	menuitem->param       = NULL;
}

void menu_make_menuitem_exitmenu(menuitem_t* menuitem)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = "q";
	menuitem->description = "Exit menu.";
	menuitem->submenu     = NULL;
	menuitem->func        = menuitem_cmd_exitmenu;
	menuitem->param       = NULL;
}

void menu_make_menuitem_submenu(menuitem_t* menuitem, const char* key, const char* description, const menu_t* menu)
{
	menuitem->type        = MENUITEM_SUBMENU;
	menuitem->key         = key;
	menuitem->description = description;
	menuitem->submenu     = menu;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}

void menu_make_menuitem_group(menuitem_t* menuitem, const char* description)
{
	menuitem->type        = MENUITEM_GROUP;
	menuitem->key         = NULL;
	menuitem->description = description;
	menuitem->submenu     = NULL;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}

void menu_make_menuitem_end(menuitem_t* menuitem)
{
	menuitem->type        = MENUITEM_NULL;
	menuitem->key         = NULL;
	menuitem->description = NULL;
	menuitem->submenu     = NULL;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}

const char* const menu_get_indent(const menu_context_t* context)
{
	static char indent[INDENT_MAX+1];
	memset(indent, ' ', INDENT_MAX);
	if (context)
		indent[INDENT * context->depth + 2] = '\0';
	else
		indent[0] = '\0';

	return indent;
}

menu_action_t menu_present(const menu_t* menu)
{
	menu_action_t ret_val = MENU_EXIT;
	static int depth = -1;
	char indent[INDENT_MAX+1];
	memset(indent, ' ', INDENT_MAX);

	++depth;

	int indent_idx = INDENT * depth + 2;
	if ( indent_idx > INDENT_MAX )
	{
		printf_color(g_TextAttributeBold, g_TextColorRed, "\nERROR: MENU depth is to large. Exiting menu_present().");
		return MENU_EXIT;
	}
	indent[indent_idx] = '\0';

	menu_print(indent, menu);

	while (1) // processing menu selections
	{
		while (fgetc(stdin) != NONE_CHAR); // empty key buffer
		char key[KEY_MAX] = {'\0'};
		int key_idx = 0;
		char key_pressed = NONE_CHAR;
		int menu_idx = MenuKeyFindNone;

		while (1) // getting user input to specify which menu_idx to run
		{
			// get a key press
			while ((key_pressed = fgetc(stdin)) == NONE_CHAR);

			if ( key_pressed == '\n' || key_pressed == '\r' )
			{
				///
				/// User hit ENTER_KEY
				///

				// if previously MenuKeyFindMoreThanOne
				// then run 1st matching menuitem
				if ( menu_idx == MenuKeyFindMoreThanOne )
				{
					// we need to run menu_idx
					menu_idx = menu_key_find_first(menu, key);
					break;
				}
				else
				{
					printf_color(NULL, g_TextColorYellow, "\n%sInvalid key.\n", indent);
					menu_print_footer(indent, menu);

					// start over with user input
					key[key_idx] = '\0';
					while(key_idx > 0)
						key[--key_idx] = '\0';
					continue;
				}
			}
			else
			{
				///
				/// User hit something other than ENTER_KEY
				///

				// Echo the key
				fputc(key_pressed, stdout);

				key[key_idx++] = key_pressed;

				menu_idx = menu_key_find(menu, key);
				
				if ( menu_idx == MenuKeyFindNone )
				{
					printf_color(NULL, g_TextColorYellow, "\n%sInvalid key.\n", indent);
					menu_print_footer(indent, menu);

					// start over with user input
					while(key_idx > 0)
						key[--key_idx] = '\0';
					continue;
				}
				else if ( menu_idx == MenuKeyFindMoreThanOne )
				{
					// we need more input
					continue;
				}
				else
				{
					// we need to run menu_idx
					break;
				}
			
			} // user hit something other than ENTER_KEY

		} // while (1) - getting user input to specify which menu item to run
		
		printf("\n");

		///
		/// Execute the menu item.
		///
		const menuitem_t* menuitem = &menu->menuitems[menu_idx];

		if ( menuitem->type == MENUITEM_SUBMENU )
		{
			ret_val = menu_present(menuitem->submenu);
		}
		else if ( menuitem->type == MENUITEM_FUNCTION )
		{
			const menu_context_t context = { menu, depth };
			ret_val = (*menuitem->func)(&context, menuitem->param);
		}

		///
		/// Evaluate the response.
		///
		if ( ret_val == MENU_SHOW )
		{
			menu_print(indent, menu);
		}
		else if ( ret_val == MENU_CONTINUE )
		{
			menu_print_footer(indent, menu);
		}
		else if ( ret_val == MENU_CONTINUE_PRINT )
		{
			menu_print(indent, menu);
		}
		else if ( ret_val == MENU_BACK )
		{
			ret_val = MENU_CONTINUE_PRINT;
			break;
		}
		else if ( ret_val == MENU_EXIT )
		{
			if ( depth == 0 )
				printf_color(NULL, g_TextColorYellow, "%s%sExiting menu.%s\n", indent);
			break;
		}

	} // while (1) - process menu items

	--depth;

	return ret_val;

} // void menu(void)


