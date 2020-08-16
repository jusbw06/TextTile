/* File Handling */

// This function opens the file RDONLY and returns its file descriptor
int openFile(char* file_name);

// This function reads the file pointed to by the file descriptor and fills the inbuffer
int readFile(int fd, char* file_name);

// This function creates the outfile and returns the file descriptor
int createFile(char* file_name);

// This function writes the outbuffer to the output file
int writeFile( int fd, char* file_name );

// This function closes the requested file descriptor
int closeFile( int fd, char* file_name);



/* Parser Tools */

// Parse

// This function finds the index of the next occurence of the input string
int findNextWord(char* buffer, int offset, char* str);

// This function find the next occurence of whitespace
int findNextWhiteSpace(char* buffer, int offset);

// This function tells you if you have the start index of the requested word
int isNextWord(char* buffer, int offset, char* str);


// Write

// writes the string to the output buffer, the returns the length
void writeWord(char* str);

// Writes the chars between the two parameters; Inclusive both;
void writeFromTo(int start_index, int end_index);

// Writes to end of key, index is set to next character after key
void writeTo(char* key);


// Skip

// Skips to end of key, index is set to next character after key
void skipTo(char* key);


// Creating Headers

void writeParagraph();

void writeHeader(int level);

/* Text Options */

void insertLink();

void insertImage();

void writeUnorderedList();

void writeOrderedList();

/* Parser */

void parseFile();

void parseStyle(int closing_index);

void writeStyledText(char* open, char* close, char* end); //must leave at end + 1


/* Misc */

void list_init();

int findNextI(char* buffer, int offset, char I);


