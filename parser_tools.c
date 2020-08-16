#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "GlobalVars.h"
#include "functions.h"

struct loc{
	int col;
	int line;
};

struct loc findCurrentLocation(int current_index){
	struct loc location;
	location.col = 1;
	location.line = 1;
	int counter = 0;
	for (; counter <= current_index; counter++){
		if( inbuffer[counter++] == '\n' ){
			location.line += 1;
			location.col = 1;
		}else{
			location.col++;
		}
	}
	return location;
}


/* Parsing Functions */

// This function finds the index of the next occurence of the input string
int findNextWord(char* buffer, int offset, char* str){
	struct loc location;
	while( offset < file_length ){
		
		if(isNextWord(buffer, offset, str)){
			return offset;	
		}
		offset++;
	}
	location = findCurrentLocation(i);
	fprintf(stderr, "Word \"%s\" was not found\nLine: %i\nColumn: %i\n", str, location.line, location.col);
	exit(1);
}

// This function finds the index of the next occurence of whitespace
int findNextWhiteSpace(char* buffer, int offset){
	
	while(1){
		if( isspace(buffer[offset++]) ){
			return offset -1;
		}
	}

}

// This function tells you if you have the start index of the requested word
int isNextWord(char* buffer, int offset, char* str){

	for (int j = 0; j < strlen(str); j++, offset++  ){

		if(buffer[offset] == str[j]){
			continue;
		}else{
			return 0;
		}

	}
	return 1;
}


/* Writing Functions */

// writes the string to the output buffer, the returns the length
void writeWord(char* str){
	int len = strlen(str);
	for (int i = 0; i < len; i++){
		outbuffer[outfile_index++] = str[i];
	}
}

// Writes the chars between the two parameters; Inclusive both;
void writeFromTo(int start_index, int end_index){
	for (; start_index <= end_index; start_index++){
		outbuffer[outfile_index++] = inbuffer[start_index];
	}
}

// Writes to end of key, index is set to next character after key
void writeTo(char* key){
	int closing_index = findNextWord(inbuffer, i, key) + strlen(key);
	for (; i < closing_index; i++){
		outbuffer[outfile_index++] = inbuffer[i];
	}
}


/* Commenting Functions */

// Skips to end of key, index is set to next character after key
void skipTo(char* key){
	i = findNextWord(inbuffer, i, key) + strlen(key);
}


/* Private Helper Functions */

// Finds the index of the next character
int findNextI(char* buffer, int offset, char I){
	for (; offset < file_length; offset++){
		if( buffer[offset] == I ){
			return offset;
		}
	}
	fprintf(stderr, "Character  \"%c\" does not exist\n", I);
	exit(1);
}

// This function tells you if you have stumbled on a particular character
int isNextI(char* buffer, int offset, char I){
	if (inbuffer[i] == I){
		return 1;
	}
	return 0;
}

