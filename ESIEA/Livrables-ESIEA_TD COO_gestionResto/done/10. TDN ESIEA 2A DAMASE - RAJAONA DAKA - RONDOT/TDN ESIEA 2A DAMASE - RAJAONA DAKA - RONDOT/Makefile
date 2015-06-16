#compiler and option
ERROR = -Wall
EXTEND = -std=c++11

#Directories path
SRCDIR = src/
OBJDIR = obj/

#List of source and object files
SRC = $(addprefix $(SRCDIR), main.cpp) $(addprefix $(SRCDIR), client.cpp) $(addprefix $(SRCDIR), product.cpp) $(addprefix $(SRCDIR), command.cpp)
OBJ = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRC))

#Output name
OUT = TD_Restaurant

#construire l'executable
$(OUT) : $(OBJ)
	g++ $(EXTEND) $(ERROR) $(OBJ) -o $@
	
#construire les objet
$(OBJDIR)%.o : $(SRCDIR)%.cpp
	mkdir -p $(OBJDIR)
	g++ $(EXTEND) $(ERROR) -c $< -o $@
	
#Clean the project
clean :
	rm -f $(OBJ) $(OUT)
