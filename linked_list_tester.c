#include <stdio.h>
#include "linked_list.h"


int main(int argc, char** argv){

	List list;

	list_init();

	
	list = addItem("One");
//	fprintf(stdout,"Flag 1\n");
	addItem("Two");
//	fprintf(stdout,"Flag 2\n");
	addItem("Three");
//	fprintf(stdout,"Flag 3\n");

// Works
	//fprintf(stdout,"%s\n", list->next->next->string);

	fprintf(stdout, "%s\n", removeItem());	
	fprintf(stdout, "%s\n", removeItem());	
	fprintf(stdout, "%s\n", removeItem());	

	addItem("One");
	fprintf(stdout, "%s\n", removeItem());	
}

