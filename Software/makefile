OPTIONS = -Wall -pedantic -pthread

main: main.o event.o Nokia5110LCD.o
	gcc -pthread -o main main.o event.o Nokia5110LCD.o -lpigpio -lrt

main.o: event.h main.c
	gcc -c $(OPTIONS) main.c

event.o: event.h event.c
	gcc -c $(OPTIONS) event.c

Nokia5110LCD.o: Nokia5110LCD.h Nokia5110LCD.c
	gcc -c $(OPTIONS) Nokia5110LCD.c

clean:
	rm Nokia5110LCD.o event.o main.o main 2>/dev/null || :
