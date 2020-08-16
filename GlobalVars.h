#define BUFFER_LEN 100000

/* Global Variables */


#ifdef DEFINE

char outbuffer[BUFFER_LEN];

char inbuffer[BUFFER_LEN];

int file_length;

int i; // Infile Index

int outfile_index;

char outfile_name[100];

int ul_depth;

int ol_depth;

#else

extern char outbuffer[BUFFER_LEN];

extern char inbuffer[BUFFER_LEN];

extern int file_length;

extern int i; // Infile Index

extern int outfile_index;

extern char outfile_name[100];

extern int ul_depth;

extern int ol_depth;


#endif

