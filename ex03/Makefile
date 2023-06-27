NAME 		=	ex03

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

INCS		=	./AMateria.hpp\
				./Character.hpp\
				./Cure.hpp\
				./Ice.hpp\
				./ICharacter.hpp\
				./IMateriaSource.hpp\
				./MateriaSource.hpp\

SRCS		=	./main.cpp\
				./AMateria.cpp\
				./Character.cpp\
				./Cure.cpp\
				./Ice.cpp\
				./MateriaSource.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.c
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re