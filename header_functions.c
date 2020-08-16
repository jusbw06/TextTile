#include "functions.h"
#include "GlobalVars.h"
#include "linked_list.h"


void createHeader(char* open_label, char* close_label){

	int header_terminator;
	int body_terminator;
	char added_css[100];
	int css_index = 0;

	writeWord(open_label);

	i+=2; // skip to index after h#	

	header_terminator = findNextWord(inbuffer, i, "\n");

// Handles css options
	for (; i < header_terminator; i++){
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
		}
	}


// Handles if css is present
	if (!isEmpty()){ // isStyled
		
		writeWord("style=\"");
		while( !isEmpty() ){
			
			writeWord(  removeItem()  );

		}
		writeWord("\">");
	}else{
		writeWord(">");
	}


	i++; // may be necessary to index to first index of text
	body_terminator = findNextWord(inbuffer, i, "\n\n");
	
	parseStyle(body_terminator);

	writeWord(close_label); // writes </html>; add a newline	

}



//
void writeParagraph(int isImplied){

	if (isImplied){

		int body_terminator;

		writeWord("<p>");

		body_terminator = findNextWord(inbuffer, i, "\n\n");
		
		parseStyle(body_terminator);

		writeWord("</p>"); // writes </html>; add a newline

	}else{
		createHeader("<p ", "</p>");
	}

}


//
void writeHeader(int level){
	if (level == 1){
		createHeader("<h1 ", "</h1>");
	}else if(level == 2){
		createHeader("<h2 ", "</h2>");
	}else if(level == 3){
		createHeader("<h3 ", "</h3>");
	}else if(level == 4){
		createHeader("<h4 ", "</h4>");
	}
}



