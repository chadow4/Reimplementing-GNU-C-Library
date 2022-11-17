
CC = gcc
FLAGS = -c -Wall
EXEC = TEST mini_touch mini_cp mini_echo mini_cat mini_head mini_tail mini_clean mini_grep mini_wc mini_shell

LIB =  mini_string.o mini_memory.o mini_io.o

MAIN = main.o $(LIB)
MINI_TOUCH = mini_touch.o $(LIB)
MINI_CP = mini_cp.o $(LIB)
MINI_ECHO = mini_echo.o $(LIB)
MINI_CAT = mini_cat.o $(LIB)
MINI_HEAD = mini_head.o $(LIB)
MINI_TAIL = mini_tail.o $(LIB)
MINI_CLEAN = mini_clean.o $(LIB)
MINI_GREP = mini_grep.o $(LIB)
MINI_WC = mini_wc.o $(LIB)
MINI_SHELL = mini_shell.o $(LIB)
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
HEADER = mini_lib.h

all: $(MAIN)
	$(CC) -Wall $(MAIN) -o TEST


mini_touch: $(MINI_TOUCH)
	$(CC) -Wall $(MINI_TOUCH) -o mini_touch 

mini_touch.o: mini_touch.c
	$(CC) $(FLAGS) mini_touch.c

mini_cp: $(MINI_CP)
	$(CC) -Wall $(MINI_CP) -o mini_cp 

mini_cp.o: mini_cp.c
	$(CC) $(FLAGS) mini_cp.c

mini_echo: $(MINI_ECHO)
	$(CC) -Wall $(MINI_ECHO) -o mini_echo 

mini_echo.o: mini_echo.c
	$(CC) $(FLAGS) mini_echo.c

mini_cat: $(MINI_CAT)
	$(CC) -Wall $(MINI_CAT) -o mini_cat

mini_cat.o: mini_cat.c
	$(CC) $(FLAGS) mini_cat.c

mini_head: $(MINI_HEAD)
	$(CC) -Wall $(MINI_HEAD) -o mini_head

mini_head.o: mini_head.c
	$(CC) $(FLAGS) mini_head.c

mini_tail: $(MINI_TAIL)
	$(CC) -Wall $(MINI_TAIL) -o mini_tail

mini_tail.o: mini_tail.c
	$(CC) $(FLAGS) mini_tail.c

mini_clean: $(MINI_CLEAN)
	$(CC) -Wall $(MINI_CLEAN) -o mini_clean

mini_clean.o: mini_clean.c
	$(CC) $(FLAGS) mini_clean.c

mini_grep: $(MINI_GREP)
	$(CC) -Wall $(MINI_GREP) -o mini_grep

mini_grep.o: mini_grep.c
	$(CC) $(FLAGS) mini_grep.c

mini_wc: $(MINI_WC)
	$(CC) -Wall $(MINI_WC) -o mini_wc

mini_wc.o: mini_wc.c
	$(CC) $(FLAGS) mini_wc.c

mini_shell: $(MINI_SHELL)
	$(CC) -Wall $(MINI_SHELL) -o mini_shell

mini_shell.o: mini_shell.c
	$(CC) $(FLAGS) mini_shell.c


main.o: main.c
	$(CC) $(FLAGS) main.c

mini_string.o: mini_string.c
	$(CC) $(FLAGS) mini_string.c 

mini_memory.o: mini_memory.c
	$(CC) $(FLAGS) mini_memory.c 

mini_io.o: mini_io.c
	$(CC) $(FLAGS) mini_io.c 

clearObject:
	rm $(OBJ)

clearExec:
	rm $(EXEC)

clearAll: clearObject clearExec
	