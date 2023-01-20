# Reimplementing GLIBC, system commands and SHELL

## About the Project

In this project, the standard library was recreated from scratch as well as system commands and a SHELL in order to execute them.

### Developped with :
* C (only system Call)

## Getting Started

The project has a makefile in order to compile the library, the Test file, the SHELL file and the different system commands.



#### the library contains 4 files :

- mini_string.c

  - mini_printf
  - mini_scanf
  - mini_exit_string
  - mini_strlen
  - mini_strcpy
  - mini_strcmp
  - stringToInt (ATOI)
  - intToString (ITOA)
  - mini_perror
  
- mini_memory.c

  - mini_calloc
  - mini_free
  - mini_exit
 
- mini_io.c
  
  - mini_fopen
  - mini_fread
  - mini_fwrite
  - mini_fflush
  - mini_fclose
  - mini_exit_io
  - mini_fgetc
  - mini_fputc
  
- mini_lib.h

###### The SHELL and the system commands use only this library !!

#### List of system commands implemented : 
- mini_touch.c
- mini_cp.c
- mini_echo.c
- mini_cat.c
- mini_head.c
- mini_tail.c
- mini_clean.c
- mini_grep.c
- mini_wc.c

#### Test File : 
- main.c

#### SHELL File : 
- shell.c



### COMMANDS : 
- Compile All FIles : ```make all```
- Clear All FIles : ```make cleanall```


## Credits : 

Created by Julien SANCHEZ 
