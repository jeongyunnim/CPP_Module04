#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	:   _type("WrongAnimal")
{
	std::cout << "Default constructor called. WrongAnimal Class Generated." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "destructor called. WrongAnimal Class deleted." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	_type = rhs._type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	:	_type(other._type)
{
	std::cout << "Copy constructor called. WrongAnimal Class Generated." << std::endl;
}


void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Object can't make any sound." << std::endl;
}

std::string		WrongAnimal::getType(void) const
{
	return (_type);
}