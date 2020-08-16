#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include "GlobalVars.h"
#include "linked_list.h"


// returns the number of depth
int countElement(char* buffer, int offset, char I){
	return findNextI(buffer, offset, I) - offset;
}


void writeList(char* open_list, char* close_list){
	// ol li
	// ul li
	// "\n<ul>", "</ul>\n"
//	i++; // sets i on first * or #
	int index_newline;
	int index_space = findNextWord(inbuffer, i, " "); //header_terminator
//	int depth = index_space - i; // counts number of * or #
	int depth = 0;
	
	/* Open exerpt -- handle *{} */
	char added_css[100];
	int css_index = 0;

	int state = 1;




	// Handles css options
	for (; i < index_space; i++){

		switch (state){
		
			case 1:
				if (inbuffer[i] == '*'){ // will not work for ordered
					depth++;
					break;
				}
				state = 2;
			case 2:
				if ( inbuffer[i] == '=' ){
					addItem("text-align:center;");
				}else if (inbuffer[i] == '{'){
					state = 3;
				}
				break;
			case 3:
				if (inbuffer[i] == '}'){
					added_css[css_index] = '\0';
					addItem(added_css);
					continue; // breaks from loop
				}
				added_css[css_index++] = inbuffer[i];
				break;
			default:
				fprintf(stderr, "writeList Default, you shouldn't be here\n");

		}
	}

/*
	open_header[0] = '\0';
	// Handles if css is present
	if (!isEmpty()){ // isStyled
		strcpy(open_header, "<ul ");
		writeWord("style=\"");
		while( !isEmpty() ){
			writeWord(  removeItem()  );
		}
		writeWord("\">");
	}else{
		ul_depth++;
		writeWord(open_list);
	}
*/	
	
	
	/* close exerpt */
	
	

	if (depth > ul_depth){
//		for (; ul_depth < depth; ul_depth++){
			//writeWord(open_list);
			
			// Handles if css is present
			if (!isEmpty()){ // isStyled
				writeWord("<ul ");
				writeWord("style=\"");
				while( !isEmpty() ){
					writeWord(  removeItem()  );
				}
				writeWord("\">");
				ul_depth++;
			}else{
				ul_depth++;
				writeWord(open_list);
			}
			
			
//		}
	}

	if (depth < ul_depth){
	//	for (; ul_depth > depth; ul_depth--){
			ul_depth--;
			writeWord(close_list);
	//	}
	}

	writeWord("\n<li>");				
//	i+= depth + 1; // +1 for space
	//i+=2;
			
	index_newline = findNextWord(inbuffer, i, "\n");

	parseStyle(index_newline);

	writeWord("</li>\n");

	if( !isNextWord(inbuffer, i, "\n*")  ){
		for (; ul_depth > 0; ul_depth--){
			writeWord("\n</ul>\n");
		}		
	}	
}

void writeUnorderedList(){

	writeList("\n<ul>\n","\n</ul>\n");

}

void writeOrderedList(){

	writeList("\n<ol>\n","\n</ol>\n");

}

void insertLink(){

	int start_name = i+1;
	int end_name = findNextWord(inbuffer, i, "\":") - 1;
	int start_link = end_name + 3;
	int end_link = findNextWhiteSpace(inbuffer, end_name) - 1;

	writeWord("<a href=");
	writeFromTo(start_link, end_link);
	writeWord(">");
	writeFromTo(start_name,end_name);
	writeWord("</a>");

	i = end_link + 1;
}

void insertImage(){

	char added_css[100];
	int css_index = 0;
	i++;
	writeWord("<img ");

// Handles css options
	for (; ; i++){
		if ( inbuffer[i] == '=' ){
			addItem("text-align:center;");
		}else if ( inbuffer[i] == '{'){
			i++;
			while(inbuffer[i] != '}'){

				added_css[css_index++] = inbuffer[i];
				i++;	
			}

			added_css[css_index] = '\0';
			addItem(added_css);
			if(inbuffer[i] == '}'){  // i stops on term
				break;
			}
		}
	}


// Handles if css is present
	if (!isEmpty()){ // isStyled
		
		writeWord("style=\"");
		while( !isEmpty() ){
			
			writeWord(  removeItem()  );

		}
		writeWord("\" ");
	}


	int key = findNextWord(inbuffer, i, "!");

	writeWord("src=\"");
//	writeTo("!");
	writeFromTo(i+1, key-1);
	writeWord("\"/>");
	i = key + 1;

}

//
void writeStyledText(char* open, char* close, char* end){ //must leave at end + 1

	i++;// skip to text
	int temp = findNextWord(inbuffer, i, end);

	writeWord(open);

	parseStyle(temp); // finds index of end key

	writeWord(close);
	i++;
}

