NAME 		=	ex00

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./Dog.hpp\
				./Cat.hpp\
				./Animal.hpp\
				./WrongCat.hpp\
				./WrongAnimal.hpp\
				./Brain.hpp\

SRCS		=	./main.cpp\
				./Dog.cpp\
				./Cat.cpp\
				./Animal.cpp\
				./WrongCat.cpp\
				./WrongAnimal.cpp\
				./Brain.cpp\

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