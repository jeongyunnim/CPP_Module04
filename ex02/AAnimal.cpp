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



std::string		AAnimal::getType(void) const
{
	return (_type);
}