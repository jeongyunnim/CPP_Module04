#include "Cat.hpp"

Cat::Cat(void)
	:	Animal()
	,	brain(NULL)
{
	_type = "cat";
	brain = new Brain();
 	std::cout << "Default constructor called. Cat generated." << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Destructor called. Cat deleted." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	_type = rhs._type;
	brain = rhs.brain;
	return (*this);
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	brain = new Brain(*(other.brain));
	std::cout << "Copy constructor called. Cat generated." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

void	Cat::whereIsBrain(void) const
{
	brain->printIdeasAddress();
}
