struct item {
	char* string;
	struct item* next;
};
typedef struct item* List;

void list_init();
List addItem( char* str );
char* removeItem();
int isEmpty();

#ifdef DEFINE
List global_list;
#else
extern List global_list;
#endif
