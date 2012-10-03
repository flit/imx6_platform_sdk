
#define INDENT 4
#define INDENT_MAX 120
#define KEY_MAX 8

typedef enum _menu_actions
{
	MENU_SHOW,
	MENU_EXIT,
	MENU_CONTINUE,
	MENU_CONTINUE_PRINT,
	MENU_BACK

} menu_action_t;


typedef struct _menu_context menu_context_t;
typedef struct _menuitem menuitem_t;
typedef struct _menu menu_t;

typedef menu_action_t (*menu_function_t) (const menu_context_t* const context, void* const param);

typedef enum _menuitem_types
{
	MENUITEM_MENU,
	MENUITEM_GROUP,
	MENUITEM_SUBMENU,
	MENUITEM_FUNCTION,
	MENUITEM_NULL

} menuitem_type_t;

struct _menuitem
{
	menuitem_type_t type;
	const char* key;
	const char* description;
	const menu_t* submenu;
	menu_function_t func;
	void* param;
};

typedef struct _menu
{
	const char* header;
	const menuitem_t* menuitems;
	const char* footer;
} menu_t;

struct _menu_context
{
	const menu_t* menu;
	int depth;
};

menu_action_t menuitem_cmd_showmenu(const menu_context_t* const context, void* const param);// { return MENU_SHOW; }
menu_action_t menuitem_cmd_exitmenu(const menu_context_t* const context, void* const param);// { return MENU_EXIT; }

#define MAKE_MENU(header, menuitems, footer)  { header, menuitems, footer }
#define MAKE_MENUITEM(key, desc, func, param) { MENUITEM_FUNCTION, key,  desc,            NULL,      func,                  param },
#define MAKE_CMD_SHOWMENU()                   { MENUITEM_FUNCTION, "m",  "Display menu.", NULL,      menuitem_cmd_showmenu, NULL  },
#define MAKE_CMD_EXITMENU()                   { MENUITEM_FUNCTION, "q",  "Exit menu.",    NULL,      menuitem_cmd_exitmenu, NULL  },
#define MAKE_SUBMENU(key, desc, menu)         { MENUITEM_SUBMENU,  key,  desc,            menu,      NULL,                  NULL  },
#define MAKE_GROUP(desc)                      { MENUITEM_GROUP,    NULL, desc,            NULL,      NULL,                  NULL  },
#define MAKE_END_MENU()                       { MENUITEM_NULL,     NULL, NULL,            NULL,      NULL,                  NULL  }

menu_action_t menu_present(const menu_t* const menu);
void menu_print(const char* const indent, const menu_t* const menu);
void menu_print_footer(const char* const indent, const menu_t* const menu);
const char* const menu_get_indent(const menu_context_t* const context);

void menu_make_menu(menu_t* const menu, const char* const header, const menuitem_t* const menuitems, const char* const footer);
void menu_make_menuitem(menuitem_t* const menuitem, const char* const key, const char* const description, menu_function_t func, void* const func_param);
void menu_make_cmd_showmenu(menuitem_t* const menuitem);
void menu_make_cmd_exitmenu(menuitem_t* const menuitem);
void menu_make_submenu(menuitem_t* const menuitem, const char* const key, const char* const description, const menu_t* const menu);
void menu_make_group(menuitem_t* const menuitem, const char* const description);
void menu_make_end_menuitem(menuitem_t* const menuitem);

/////
///// PRIVATE
/////

typedef enum _menu_key_find
{
	MENU_KEY_FIND_NONE = -2,
	MENU_KEY_FIND_MORE_THAN_ONE = -1,

} menu_key_find_t;

int menu_key_find(const menu_t* menu, const char* key);
int menu_key_find_first(const menu_t* menu, const char* key);
int menu_get_size(const menu_t* menu);
