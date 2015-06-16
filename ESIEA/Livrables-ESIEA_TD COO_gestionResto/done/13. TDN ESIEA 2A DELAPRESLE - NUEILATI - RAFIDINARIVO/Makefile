CC=g++
CXXFLAGS=-g -pedantic-errors -Wall

all:	main go

clean:	
	-rm -f *.o main

main: main.o Plat.o Commande.o Pizza.o Dessert.o Boisson.o PlatDuJour.o Plat_Vegetarien.o

go:	main
	-./main

# DO NOT DELETE

Client.o: Plat.h Commande.h
main.o: Commande.h Plat.h Pizza.h Makefile
Pizza.o: Pizza.h Plat.h Dessert.h
Dessert.o: Dessert.h Plat.h
Boisson.o : Boisson.h Plat.h
Plat_du_jour.o : PlatDuJour.h Plat.h
Plat_vegetarien.o :Plat_Vegetarien.h Plat.h
Plat.o: Plat.h

