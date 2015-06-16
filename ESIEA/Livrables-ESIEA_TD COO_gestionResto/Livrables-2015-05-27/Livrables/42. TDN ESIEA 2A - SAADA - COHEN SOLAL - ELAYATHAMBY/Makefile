CC=g++
CXXFLAGS=-g -pedantic-errors -Wall

all:	main go

clean:	
	-rm -f *.o main

main: main.o Plat.o Client.o Pizza.o Dessert.o Boisson.o Plat_du_jour.o Plat_vegetarien.o

go:	main
	-./main

# DO NOT DELETE

Client.o: Plat.h Client.h
main.o: Client.h Plat.h Pizza.h Makefile
Pizza.o: Pizza.h Plat.h Dessert.h
Dessert.o: Dessert.h Plat.h
Boisson.o : Boisson.h Plat.h
Plat_du_jour.o : Plat_du_jour.h Plat.h
Plat_vegetarien.o :Plat_vegetarien.h Plat.h
Plat.o: Plat.h

