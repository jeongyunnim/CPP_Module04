#include "Animal.hpp"

Animal::Animal(void)
	:   _type("Animal")
{
	std::cout << "Default constructor called. Animal Class Generated." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called. Animal Class deleted." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	_type = rhs._type;
	return (*this);
}

Animal::Animal(const Animal& other)
	:	_type(other._type)
{
	std::cout << "Copy constructor called. Animal Class Generated." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal object can't make any sound." << std::endl;
}

const std::string&		Animal::getType(void) const
{
	return (_type);
}