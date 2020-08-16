#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>


#define DEFINE 1
#include "GlobalVars.h"
#include "linked_list.h"
#include "functions.h"

/* This program will convert textile to regular html ignoring regular html tags */

int main(int argc, char** argv){

/* Local Vars */
	int fd;
	

/* Global Init */
	i = 0;
	outfile_index = 0;
	ul_depth = 0;
	ol_depth = 0;

	list_init();

/* File Open & Read */

	fd = openFile(argv[1]);  // opens file and returns file descriptor

	readFile(fd, argv[1] ); // reads file and populates inbuffer

	closeFile(fd, argv[1]);

/* Parser */

	parseFile();

/* File Create & Write */

	fd = createFile(argv[2]);

	writeFile(fd, outfile_name);

	closeFile(fd, outfile_name);



	return 0;
}

