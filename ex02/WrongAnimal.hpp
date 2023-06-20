#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
public:

	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	WrongAnimal(const WrongAnimal& other);

	void	        makeSound(void) const;
	std::string		getType(void) const;

protected:

	std::string _type;

};