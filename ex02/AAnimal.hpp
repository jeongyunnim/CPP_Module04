#pragma once
#include <iostream>
#include <string>

class AAnimal
{
public:

	AAnimal(void);
	virtual ~AAnimal(void);
	AAnimal& operator=(const AAnimal& rhs);
	AAnimal(const AAnimal& other);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:

	std::string _type;

};