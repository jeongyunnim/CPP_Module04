#include "Cat.hpp"

Cat::Cat(void)
	:	Animal()
{
	_type = "cat";
	brain = new Brain();
	brain->setIdeas("Meow");
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
	brain = new Brain();
	brain = other.brain;
	std::cout << "Copy Constructor called. Cat generated." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
