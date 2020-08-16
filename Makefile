CC = gcc
CFLAGS = -Wall -pedantic -g
MAIN = ../text2html
TMAIN = ListTest
OBJS = parser.o parser_tools.o file_handler.o linked_list.o header_functions.o text_options.o main.o
TOBJS = linked_list_tester.o linked_list.o
all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

main.o : main.c functions.h GlobalVars.h
	$(CC) $(CFLAGS) -c main.c

parser.o : parser.c functions.h GlobalVars.h
	$(CC) $(CFLAGS) -c parser.c

parser_tools.o : parser_tools.c GlobalVars.h
	$(CC) $(CFLAGS) -c parser_tools.c

file_handler.o: file_handler.c GlobalVars.h
	$(CC) $(CFLAGS) -c file_handler.c

text_options.o: text_options.c GlobalVars.h functions.h
	$(CC) $(CFLAGS) -c text_options.c

header_functions.o: header_functions.c GlobalVars.h functions.h
	$(CC) $(CFLAGS) -c header_functions.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

# 

linked_list_tester.o: linked_list_tester.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list_tester.c


$(TMAIN) : $(TOBJS)
	$(CC) $(CFLAGS) -o $(TMAIN) $(TOBJS)

clean :
	rm *.o $(MAIN) $(TMAIN)

empty :
	rm *.o
