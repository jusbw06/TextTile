#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "GlobalVars.h"

// This function opens the file RDONLY and returns its file descriptor
int openFile(char* file_name){
	
	int fd = open( file_name, O_RDONLY);

	if (fd < 0){
		fprintf(stderr, "Unable to open file: %s\n", file_name);
		exit(1);
	}
	return fd;
}
// This function reads the file pointed to by the file descriptor and fills the inbuffer
int readFile(int fd, char* file_name){
	file_length = read( fd, inbuffer, BUFFER_LEN);
	if( file_length == 0){
		fprintf(stderr, "Empty File: %s", file_name);
		exit(1);
	} else if (file_length < 0){
		fprintf(stderr, "Error Reading from file: %s", file_name);
		exit(1);
	}
	return 0;
}
// This function creates the outfile and returns the file descriptor
int createFile(char* file_name){

	int fd = open( file_name, O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP);
	if (fd < 0){
		fprintf(stderr, "Unable to create file: %s\n", file_name);
		exit(1);
	}
	return fd;
}
// This function writes the outbuffer to the output file
int writeFile( int fd, char* file_name ){
	int err = write( fd, outbuffer, outfile_index ); // subtracted +1
	if ( err < 0){
		fprintf(stderr, "Error writing to file: %s\n", outfile_name);
		exit(1);
	}
	return 0;
}
// This function closes the requested file descriptor
int closeFile( int fd, char* file_name){
	int err = close(fd);
	if(err < 0){
		fprintf(stderr, "Failed to close: %s\n", file_name);
		exit(1);
	}
	return 0;
}
