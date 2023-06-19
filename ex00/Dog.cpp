#include "Dog.hpp"

Dog::Dog(void)
	:	Animal()
{
	_type = "dog";
	std::cout << "Default Constructor called. Dog generated." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called. Dog deleted." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	_type = rhs._type;
    return (*this);
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	std::cout << "Copy Constructor called. Dog generated." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow" << std::endl;
}
