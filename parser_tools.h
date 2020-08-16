// Finds the index of the next character
int findNextI(char* buffer, int offset, char I);

// Finds the index of the first char in the requested pattern
int findNextII(char* buffer, int offset, char I, char II);

// This function tells you if you have stumbled on a length 2 pattern string
int isNextII(char* buffer, int offset, char I, char II);

// This function tells you if you have the start index of the requested word
int isNextWord(char* buffer, int offset, char* str);

// This function finds the index of the next occurence of the input string
int findNextWord(char* buffer, int offset, char* str);

// writes the string to the output buffer, the returns the length
int writeOutStr(char* str);
