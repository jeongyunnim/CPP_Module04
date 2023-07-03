#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:

	WrongCat(void);
	virtual ~WrongCat(void);
	WrongCat& operator=(const WrongCat& rhs);
	WrongCat(const WrongCat& other);

	void makeSound(void) const;

};