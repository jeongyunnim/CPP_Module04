#pragma once
#include <iostream>
#include <string>

class Animal
{

public:

	Animal(void);
	virtual ~Animal(void);
	Animal& operator=(const Animal& rhs);
	Animal(const Animal& other);

	virtual void	makeSound(void) const;
	const std::string&		getType(void) const;

protected:

	std::string _type;

};
