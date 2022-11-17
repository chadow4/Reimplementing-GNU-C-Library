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
- Compile the SHELL file and run it: ```make mini_shell``` then enter ```./mini_shell``` in order to execute it.
-  Compile the Test file and run it: : ```make``` then enter ```./TEST``` in order to execute it.
-  Compile the mini_touch command and run it:: ```make mini_touch ``` then enter ```./mini_touch votreFichier``` in order to execute it.
-  Compile the mini_cp command and run it: ```make mini_cp ``` then enter ```./mini_cp fichier1 fichier2``` in order to execute it.
-  Compile the mini_echo command and run it:  : ```make mini_echo ``` then enter ```./mini_echo votre texte``` in order to execute it.
-  Compile the mini_cat command and run it: ```make mini_cat ``` then enter ```./mini_cat votreFichier``` in order to execute it.
-  Compile the mini_head command and run it: ```make mini_head ``` then enter ```./mini_head votreFichier``` in order to execute it.
-  Compile the mini_tail command and run it: ```make mini_tail ``` then enter ```./mini_tail votreFichier``` in order to execute it.
-  Compile the mini_clean command and run it: ```make mini_clean ``` then enter ```./mini_clean votreFichier``` in order to execute it.
-  Compile the mini_grep command and run it: ```make mini_grep ``` then enter ```./mini_grep mot votreFichier``` in order to execute it.
-  Compile the mini_wc command and run it: ```make mini_wc ``` then enter ```./mini_grep votreFichier``` in order to execute it.
- Delete object files: ```make clearObject``` 
- Delete executable files : ```make clearExec```


## Credits : 

Created by Julien SANCHEZ 
