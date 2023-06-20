#pragma once
#include <iostream>
#include <string>

class AAnimal
{
public:

	virtual ~AAnimal(void);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:

	std::string _type;

};