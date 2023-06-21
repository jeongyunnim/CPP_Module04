#include "AAnimal.hpp"

AAnimal::AAnimal(void)
	:   _type("AAnimal")
{
	std::cout << "Default constructor called. AAnimal Class Generated." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "destructor called. AAnimal Class deleted." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	_type = rhs._type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal& other)
	:	_type(other._type)
{
	std::cout << "Copy constructor called. AAnimal Class Generated." << std::endl;
}


std::string		AAnimal::getType(void) const
{
	return (_type);
}