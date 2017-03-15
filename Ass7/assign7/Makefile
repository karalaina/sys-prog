
a7:	main.o	print.o	list.o	init.o	input.o
	gcc -o a7 main.o print.o list.o init.o input.o 

main.o:	main.c	a7Defs.h
	gcc -c main.c

print.o:	print.c	a7Defs.h
	gcc -c print.c

list.o:	list.c	a7Defs.h
	gcc -c list.c

init.o:	init.c	a7Defs.h	
	gcc -c	init.c

input.o:	input.c	a7Defs.h
	gcc -c input.c

	
