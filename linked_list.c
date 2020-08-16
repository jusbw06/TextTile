#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#include<stdio.h>


// create global list
void list_init(){

	global_list = (List) malloc( sizeof(struct item) );

}

// This function adds a string to a global list
// If the global list is empty, it creates one
List addItem( char* str ){
	int len = strlen(str);
	List local_element = global_list;

	while(local_element->string != NULL ){
		if(local_element->next == NULL){
			local_element->next = (List) malloc( sizeof(struct item) );
		}
		local_element = local_element->next;

	}
	if(local_element->next == NULL){
		local_element->next = (List) malloc( sizeof(struct item) );
	}

	local_element->string = (char*) calloc( len + 1, sizeof(char) );
	strcpy(local_element->string, str);

	return global_list;
}

int isEmpty(){

	if(global_list->string == NULL){
		return 1;
	}
	return 0;

}

char* removeItem(){

	char* str;

	List local_element = global_list;

	if(local_element->string == NULL){
		fprintf(stderr,"List is Empty\n");
		return NULL;
	}

	while (local_element->next->string != NULL){

		local_element = local_element->next;

	}	
	str = local_element->string;
	local_element->string = NULL;
//	free(local_element);
//	fprintf(stdout, "%s\n", str );	

	return str;
}
