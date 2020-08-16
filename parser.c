#include "GlobalVars.h"
#include "functions.h"
#include <ctype.h>

// This method determines if the * is a list or a bold
// return 1 if list
int list_helper( char type ){
	if (inbuffer[i+1] == type){
		return 1;
	}
	if (isspace( inbuffer[i+1] )){
		return 1;
	}
	if (inbuffer[i+1] == '{'){
		return 1;
	}
	if(!isspace( inbuffer[i+1] )){
		return 0;	
	}
	return 0;
	
}

// 
void parseStyle(int closing_index){

	while( i < closing_index){
		if ( inbuffer[i] == '\\' ){ // backslash to escape styles
			outbuffer[outfile_index++]= inbuffer[++i];
			i++;
		}
		/* Bullets & Numbers*/
		else if ( isNextWord(inbuffer, i, "*") && list_helper('*')   ){ 	
			writeUnorderedList();		
		}
		else if ( isNextWord(inbuffer, i, "#") && list_helper('#')   ){ 	
			writeOrderedList();		
		}
		/* Style */
			/* Underline */
		else if ( isNextWord(inbuffer, i, "+")   ){ 	
			writeStyledText( " <ins>", "</ins>", "+"); // TODO
		}	/* Bold */
		else if ( isNextWord(inbuffer, i, "*")   ){
			writeStyledText(" <strong>" , "</strong>", "*");
		}	/* StrikeThrough */		// <--- Newly Added
		else if ( isNextWord(inbuffer, i, "-")   ){
			writeStyledText(" <strike>" , "</strike>", "-");
		}
	/* Newline */
		else if( inbuffer[i] == '\n' && inbuffer[i+1] != '*'){
			writeWord("<br>");
			i++;
		}	/* Links */
		else if(   isNextWord(inbuffer, i, "\"")   ){
			insertLink();
		}	/* Images */
		else if ( isNextWord(inbuffer, i , "!") ){
			insertImage();
		}
		else{ // not a trigger
			outbuffer[outfile_index++]= inbuffer[i++];
		}
	}
}


void parseFile(){

	while( i < file_length){


		/* Comments */
		if ( isNextWord(inbuffer, i, "%{")  ){
			skipTo("%}");
		}	
		/* CSS */
		else if ( isNextWord(inbuffer, i, "<style>") ){
			writeTo("</style>");
		}
		else if ( isNextWord(inbuffer, i, "<title>") ){
			writeTo("</title>");
		}	
		/* Plain HTML */
		else if (  isNextWord(inbuffer, i, "<" )    ){ // html trigger
			writeTo(">");
		}
		/* Headers */
		else if ( isNextWord(inbuffer, i, "\np")   ){ 	// paragraph trigger
			writeParagraph(0);		
		}
		else if ( isNextWord(inbuffer, i, "\nh1")   ){ 	
			writeHeader(1);		
		}
		else if ( isNextWord(inbuffer, i, "\nh2")   ){ 	
			writeHeader(2);		
		}
		else if ( isNextWord(inbuffer, i, "\nh3")   ){ 
			writeHeader(3);		
		}
		else if ( isNextWord(inbuffer, i, "\nh4")   ){ 	
			writeHeader(4);		
		}
		else if(  !isspace(inbuffer[i])   ){ //is not whitespace
			writeParagraph(1);	
		}
		else{ // is whitespace
			outbuffer[outfile_index++]= inbuffer[i++]; // copy over whitespace
		}

	}
}
