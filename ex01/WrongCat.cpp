#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	:	WrongAnimal()
{
	_type = "wrongcat";
	std::cout << "Default Constructor called. WrongCat generated." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called. WrongCat deleted." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	_type = rhs._type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat& other)
{
	_type = other._type;
	std::cout << "Copy Constructor called. WrongCat generated." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
