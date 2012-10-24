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
 * @file menu.h
 * @brief  Defines related to the Menu Framework and used by menu.c
 * @ingroup diag_utility
 */

#ifndef __MENU_H__
#define __MENU_H__

//! @addtogroup menu
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @name Menu Framework configuration values
//@{
#define INDENT 4         //!< Default number of spaces for each level of indent.
#define INDENT_MAX 120   //!< The maximum number of allowed for indent. Used for allocation purposes.
#define KEY_MAX 8        //!< The maximum number of characters allowed for a menu key. Used for allocation purposes.
//@}

//////////////////////////////////////////////////////////////////////////////////////////
// Types
//////////////////////////////////////////////////////////////////////////////////////////

// Forward type declarations.
typedef struct _menu_context menu_context_t;
typedef struct _menuitem menuitem_t;
typedef struct _menu menu_t;

//! @brief Available Menu Actions.
typedef enum _menu_actions
{
    MENU_SHOW,             //!< Print the menu header, all of the menuitems, and the menu footer.
    MENU_EXIT,             //!< Exit all levels of the menu.
    MENU_CONTINUE,         //!< Continue processing the menu loop. Default.
    MENU_CONTINUE_PRINT,   //!< Print the menu then continue processing the menu loop.
    MENU_BACK              //!< Exit current menu level and print the parent menu.
} menu_action_t;

/*!
 * @brief Menu Execution function definition. Called in response to a menuitem being selected by the user.
 *
 * @param   context Menu context that allows function to discern indent level among other things.
 * @param   param Function specific parameter passed down from the menu framework.
 * @return  How to proceed with menu processing.
 */
typedef menu_action_t (*menu_function_t) (const menu_context_t* context, void* param);

//! @brief Available MenuItem Types.
typedef enum _menuitem_types
{
    MENUITEM_GROUP,    //!< Describes a menu group and inserts a blank line in the menu before the optional description.
    MENUITEM_SUBMENU,  //!< Describes a selectable (by key) submenu with description.
    MENUITEM_FUNCTION, //!< Describes a "regular" selectable (by key) menuitem with description and executable function.
    MENUITEM_NULL      //!< Describes an end marker of a menu list.
} menuitem_type_t;

//! @brief MenuItem container to hold data needed to process each menu item.
struct _menuitem
{
    //! @brief The type of the menuitem;  #MENUITEM_GROUP, #MENUITEM_SUBMENU, #MENUITEM_FUNCTION, ...
    menuitem_type_t type;

    //! @brief The key typed in by the user to select a menuitem for execution.
    const char* key;

    //! @brief The text associated with the menuitem describing the function. Can be NULL.
    const char* description;

    //! @brief A pointer to the submenu's menuitems. Valid for #MENUITEM_SUBMENU menuitems. Ignored otherwise.
    const menu_t* submenu;

    //! @brief A pointer to the menu execution function. Valid for #MENUITEM_FUNCTION menuitems. Ignored otherwise.
    menu_function_t func;

    //! @brief A pointer to the function specific object passed to the execution function for #MENUITEM_FUNCTION menuitems. Ignored otherwise.
    void* param;
};

//! @brief Menu container to hold data needed to describe a menu or submenu.
struct _menu
{
    //! @brief Text introducing the menu and its purpose.
    const char* header;

    //! @brief A pointer to the list of menu items.
    const menuitem_t* menuitems;

    //! @brief Instructional text to help user execute the menu.
    const char* footer;

};

//! @brief Menu Context provided to execution functions.
struct _menu_context
{
    //! @brief Pointer to the menu containing the executing menu item.
    const menu_t* menu;

    //! @brief Depth of the current menu.
    int depth;
};

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Menu presentation
//@{
/*!
 * @brief Presents the menu UI and processes the user input.
 *
 * The menu description (header) is printed, followed by each of the menuitem key and
 * menuitem description. Instructions for the user (footer) are printed last. The
 * function then waits form user input. After each key press, the menu items keys are
 * compared to the input string. If the input string uniquely identifies a menuitem,
 * the function associated with that menitem is executed. If the input string does not
 * uniquely identify a menuitem, the function waits for more input or the Enter key.
 *
 * @param[in] menu A pointer to the menu structure to be presented and processed.
 * @return  How to proceed with menu processing.
 * @retval #MENU_SHOW Print the menu header, all of the menuitems, and the menu footer.
 * @retval #MENU_EXIT Exit all levels of the menu.
 * @retval #MENU_CONTINUE Continue processing the menu loop. Default.
 * @retval #MENU_CONTINUE_PRINT Print the menu then continue processing the menu loop.
 * @retval #MENU_BACK Exit current menu level and print the parent menu.
 */
menu_action_t menu_present(const menu_t* menu);

/*!
 * @brief Return a string used to align text for the current menu level.
 *
 * @param   context Menu context that allows function to discern indent level among other things.
 * @return  String of space characters used to align output text for the current menu level.
 */
const char* const menu_get_indent(const menu_context_t* context);
//@}

//! @name Menu construction
//!
//! These functions allow the caller to easily construct a menu at runtime.
//@{
/*!
 * @brief Initializes the passed in menu stuct with the menu elements.
 *
 * @param[in,out] menu Menu struct container for menu elements.
 * @param[in] header Description of the menu presented to the user before the list of menu items.
 * @param[in] menuitems Array of menu items representing grouping and selections of the menu.
 * @param[in] footer Instructions for the user presented after the list of menu items.
 */
void menu_make_menu(menu_t* menu, const char* header, const menuitem_t* menuitems, const char* footer);

/*!
 * @brief Initializes the passed in menuitem stuct with the menuitem elements.
 *
 * @param[in,out] menuitem Menuitem struct to be initialized.
 * @param[in] key String used to select the menuitem. Key is limited to #KEY_MAX characters.
 * @param[in] description String used to describe the action executed if selected.
 * @param[in] funct Function pointer that is executed if the menuitem is selected.
 * @param[in] param Object pointer that is passed to the executed function. Generally used to
 *                       pass the return the results of the function.
 */
void menu_make_menuitem(menuitem_t* menuitem, const char* key, const char* description, menu_function_t func, void* func_param);

/*!
 * @brief Initializes the passed in menuitem stuct to represent a "Show menu" menu item.
 *
 * This function creates a menuitem with key of "m" and a description of "Display menu."
 * When selected, the invoked function returns #MENU_SHOW.
 *
 * @param[in,out] menuitem Menuitem struct to be initialized.
 */
void menu_make_menuitem_showmenu(menuitem_t* menuitem);

/*!
 * @brief Initializes the passed in menuitem stuct to represent a "Exit menu" menu item.
 *
 * This function creates a menuitem with key of "q" and a description of "Exit menu."
 * When selected, the invoked function returns #MENU_EXIT.
 *
 * @param[in,out] menuitem Menuitem struct to be initialized.
 */
void menu_make_menuitem_exitmenu(menuitem_t* menuitem);

/*!
 * @brief Initializes the passed in menuitem stuct to represent a selectable submenu.
 *
 * This function creates a menuitem denoted by the key and description parameters.
 * When selected, the menu parameter will be presented by a recursive call to menu_present().
 *
 * @param[in,out] menuitem Menuitem struct to be initialized.
 * @param[in] key String used to select the submenu. Key is limited to #KEY_MAX characters.
 * @param[in] description String used to describe the submenu.
 * @param[in,out] menu Menu to be presented as a submenu when selected.
 */
void menu_make_menuitem_submenu(menuitem_t* menuitem, const char* key, const char* description, const menu_t* menu);

/*!
 * @brief Initializes the passed in menuitem stuct to represent a menu group.
 *
 * This function creates a menuitem that will add a blank line in the menuitem listing.
 * If a group description is provided, the text will be presented after the blank line.
 * The group menuitem is not selectable. It is provided as a means to graphically arrange menu items.
 *
 * @param[in,out] menuitem Menuitem struct to be initialized.
 * @param[in] description String used to describe the following group of menu items. Can be NULL.
 */
void menu_make_menuitem_group(menuitem_t* menuitem, const char* description);

/*!
 * @brief Initializes the passed in menuitem stuct to represent the terminating element of a menu.
 *
 * The menu_present() function requires that a menuitem list of the menu be terminated with a
 * #MENUITEM_NULL element.
 *
 * @param[in,out] menuitem Menuitem struct representing the terminating element of a menu.
 */
void menu_make_menuitem_end(menuitem_t* menuitem);
//@}

//! @}

#endif //__MENU_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

