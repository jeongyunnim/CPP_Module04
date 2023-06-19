#include "Cat.hpp"

Cat::Cat(void)
	:	Animal()
{
	_type = "cat";
	std::cout << "Default Constructor called. Cat generated." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called. Cat deleted." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	_type = rhs._type;
	return (*this);
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	std::cout << "Copy Constructor called. Cat generated." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
