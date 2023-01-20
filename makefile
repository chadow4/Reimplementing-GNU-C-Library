CC=gcc
CFLAGS=-Wall
EXEC=mini_touch mini_echo mini_cp mini_cat mini_head mini_tail mini_clean mini_grep mini_wc mini_shell
LIB=mini_io mini_string mini_memory

SRCDIR=src/
OBJDIR=obj/
LIBOBJ=$(addprefix $(OBJDIR),$(LIB:=.o))
EXECOBJ=$(addprefix $(OBJDIR),$(EXEC:=.o))

all : obj $(EXEC) test

test : $(LIBOBJ) $(OBJDIR)main.o
	$(CC) -o $@ $^ $(CFLAGS)

mini_glibc : obj $(LIBOBJ)

$(EXEC) : $(LIBOBJ) $(EXECOBJ)
	$(CC) -o $@ $(LIBOBJ) $(OBJDIR)$@.o $(CFLAGS)

$(LIBOBJ) $(EXECOBJ) : $(SRCDIR)mini_lib.h

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm $(LIBOBJ) $(EXECOBJ) $(OBJDIR)main.o
	
cleanexec:
	rm $(EXEC) test

cleanall : clean cleanexec cleandir

cleandir:
	rm -r obj

obj :
	mkdir $@