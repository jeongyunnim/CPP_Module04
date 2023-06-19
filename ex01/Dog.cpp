#include "Dog.hpp"

Dog::Dog(void)
	:	Animal()
{
	_type = "dog";
	brain = new Brain();
	std::cout << "Default Constructor called. Dog generated." << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Destructor called. Dog deleted." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	_type = rhs._type;
	brain = rhs.brain;
    return (*this);
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	brain = new Brain();
	brain = other.brain;
	std::cout << "Copy Constructor called. Dog generated." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow" << std::endl;
}
