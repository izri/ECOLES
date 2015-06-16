DEBUG		= 	no

NAME		=	restaurant

SRCDIR		=	src/

SRC		=	$(SRCDIR)main.cpp	\
			$(SRCDIR)Client.cpp	\
			$(SRCDIR)Parser.cpp	\
			$(SRCDIR)History.cpp	\
			$(SRCDIR)Data.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -fr

CC		=	g++

INCLUDES	=	-I includes/

CPPFLAGS	=	-W -Wall -Wextra $(INCLUDES)

ifeq ($(DEBUG),yes)

CPPFLAGS 	+= 	-g3

else

CPPFLAGS	+= 	-O3

endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
