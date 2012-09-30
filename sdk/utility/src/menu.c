#include <stdio.h>
#include <string.h>
//#include<ctype.h>
//#include "sdk.h"
#include "text_color.h"
#include "menu.h"

#define NONE_CHAR 0xFF
//static char* prompt = "@ ";

/*!
 * @file  extra.c
 * @brief menu(); function
 *
 * @ingroup diag_init
 */
menu_action_t menuitem_cmd_showmenu(const menu_context_t* const context, void* const param) { return MENU_SHOW; }
menu_action_t menuitem_cmd_exitmenu(const menu_context_t* const context, void* const param) { return MENU_EXIT; }

menu_action_t menu_present(const menu_t* const menu)
{
	menu_action_t ret_val = MENU_EXIT;
	static int depth = -1;
	char indent[INDENT_MAX+1];
	memset(indent, ' ', INDENT_MAX);

	++depth;

	int indent_idx = INDENT * depth + 2;
	if ( indent_idx > INDENT_MAX )
	{
		printf_color(TEXT_ATTRIB_BOLD, TEXT_COLOR_RED, "\nERROR: MENU depth is to large. Exiting menu_present().");
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
		int menu_idx = MENU_KEY_FIND_NONE;

		while (1) // getting user input to specify which menu_idx to run
		{
			// get a key press
			while ((key_pressed = fgetc(stdin)) == NONE_CHAR);

			if ( key_pressed == '\n' || key_pressed == '\r' )
			{
				// User hit ENTER_KEY

				// if previously MENU_KEY_FIND_MORE_THAN_ONE
				// then run 1st matching menuitem
				if ( menu_idx == MENU_KEY_FIND_MORE_THAN_ONE )
				{
					// we need to run menu_idx
					menu_idx = menu_key_find_first(menu, key);
					break;
				}
				else
				{
					printf_color(NULL, TEXT_COLOR_YELLOW, "\n%sInvalid key.\n", indent);
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
				// User hit something other than ENTER_KEY

				// Echo the key
				fputc(key_pressed, stdout);

				key[key_idx++] = key_pressed;

				menu_idx = menu_key_find(menu, key);
				
				if ( menu_idx == MENU_KEY_FIND_NONE )
				{
					printf_color(NULL, TEXT_COLOR_YELLOW, "\n%sInvalid key.\n", indent);
					menu_print_footer(indent, menu);

					// start over with user input
					while(key_idx > 0)
						key[--key_idx] = '\0';
					continue;
				}
				else if ( menu_idx == MENU_KEY_FIND_MORE_THAN_ONE )
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

		//
		// Execute the menu item.
		//
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

		//
		// Evaluate the response.
		//
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
				printf_color(NULL, TEXT_COLOR_YELLOW, "%s%sExiting menu.%s\n", indent);
			break;
		}

	} // while (1) - process menu items

	--depth;

	return ret_val;

} // void menu(void)

void menu_print(const char* const indent, const menu_t* const menu)
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
				printf("%s%s%s%s%s - %s\n", indent, TEXT_ATTRIB_BOLD, TEXT_COLOR_MAGENTA, menuitem->key, TEXT_ATTRIB_DEFAULT, menuitem->description);
			
				break;
			}

			case MENUITEM_GROUP:
			{
				if ( menuitem->description )
					printf("\n%s%s%s%s:%s\n", indent, TEXT_ATTRIB_BOLD, TEXT_COLOR_BLUE, menuitem->description, TEXT_ATTRIB_DEFAULT);
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

void menu_print_footer(const char* const indent, const menu_t* const menu)
{
	if ( menu->footer )
		printf("\n%s%s\n",  indent, menu->footer);
	else
		printf("\n");
}

const char* const menu_get_indent(const menu_context_t* const context)
{
	static char indent[INDENT_MAX+1];
	memset(indent, ' ', INDENT_MAX);
	if (context)
		indent[INDENT * context->depth + 2] = '\0';
	else
		indent[0] = '\0';

	return indent;
}

int menu_key_find(const menu_t* const menu, const char* const key)
{
	int menuitem_found = MENU_KEY_FIND_NONE;
	int num_found = 0;
	int menu_size = menu_get_size(menu);
	int index = 0;

	for ( index = 0; index < menu_size; ++index )
	{
		if ( menu->menuitems[index].type != MENUITEM_FUNCTION &&
			 menu->menuitems[index].type != MENUITEM_SUBMENU )
			continue;

		if ( strncasecmp(key, menu->menuitems[index].key, strlen(key)) == 0 )
		{
//printf("found index %d\n", index);
			if ( menuitem_found == MENU_KEY_FIND_NONE )
				menuitem_found = index;

			++num_found;
		}
	}

	return num_found == 0 ? MENU_KEY_FIND_NONE : num_found > 1 ? MENU_KEY_FIND_MORE_THAN_ONE : menuitem_found;

} // menu_key_find()

int menu_key_find_first(const menu_t* const menu, const char* const key)
{
	int menuitem_found = MENU_KEY_FIND_NONE;
	int menu_size = menu_get_size(menu);
	int index = 0;

	for ( index = 0; index < menu_size; ++index )
	{
		if ( menu->menuitems[index].type != MENUITEM_FUNCTION &&
			 menu->menuitems[index].type != MENUITEM_SUBMENU )
			continue;

		if ( strncasecmp(key, menu->menuitems[index].key, strlen(key)) == 0 )
		{
//printf("found index %d\n", index);
			menuitem_found = index;
			break;
		}
	}

	return menuitem_found;

} // menu_key_find_first()

//
// Returns a count of the menu's menuitems.
//
int menu_get_size(const menu_t* const menu)
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

//#define MAKE_MENU(header, menuitems, footer)  { header, menuitems, footer }
//#define MAKE_MENUITEM(key, desc, func, param) { MENUITEM_FUNCTION, key,  desc,            NULL,      func,                  param },
//#define MAKE_CMD_SHOWMENU()                   { MENUITEM_FUNCTION, "m",  "Display menu.", NULL,      menuitem_cmd_showmenu, NULL  },
//#define MAKE_CMD_EXITMENU()                   { MENUITEM_FUNCTION, "q",  "Exit menu.",    NULL,      menuitem_cmd_exitmenu, NULL  },
//#define MAKE_SUBMENU(key, desc, menu)         { MENUITEM_SUBMENU,  key,  desc,            menu,      NULL,                  NULL  },
//#define MAKE_GROUP(desc)                      { MENUITEM_GROUP,    NULL, desc,            NULL,      NULL,                  NULL  },
//#define MAKE_END_MENU()                       { MENUITEM_NULL,     NULL, NULL,            NULL,      NULL,                  NULL  }

void menu_make_menu(menu_t* const menu, const char* const header, const menuitem_t* const menuitems, const char* const footer)
{
	menu->header    = header;
	menu->menuitems = menuitems;
	menu->footer    = footer;
}

void menu_make_menuitem(menuitem_t* const menuitem, const char* const key, const char* const description, menu_function_t func, void* const func_param)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = key;
	menuitem->description = description;
	menuitem->submenu     = NULL;
	menuitem->func        = func;
	menuitem->param       = func_param;
}

void menu_make_cmd_showmenu(menuitem_t* const menuitem)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = "m";
	menuitem->description = "Display menu.";
	menuitem->submenu     = NULL;
	menuitem->func        = menuitem_cmd_showmenu;
	menuitem->param       = NULL;
}

void menu_make_cmd_exitmenu(menuitem_t* const menuitem)
{
	menuitem->type        = MENUITEM_FUNCTION;
	menuitem->key         = "q";
	menuitem->description = "Exit menu.";
	menuitem->submenu     = NULL;
	menuitem->func        = menuitem_cmd_exitmenu;
	menuitem->param       = NULL;
}

void menu_make_submenu(menuitem_t* const menuitem, const char* const key, const char* const description, const menu_t* const menu)
{
	menuitem->type        = MENUITEM_SUBMENU;
	menuitem->key         = key;
	menuitem->description = description;
	menuitem->submenu     = menu;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}

void menu_make_group(menuitem_t* const menuitem, const char* const description)
{
	menuitem->type        = MENUITEM_GROUP;
	menuitem->key         = NULL;
	menuitem->description = description;
	menuitem->submenu     = NULL;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}

void menu_make_end_menuitem(menuitem_t* const menuitem)
{
	menuitem->type        = MENUITEM_NULL;
	menuitem->key         = NULL;
	menuitem->description = NULL;
	menuitem->submenu     = NULL;
	menuitem->func        = NULL;
	menuitem->param       = NULL;
}
