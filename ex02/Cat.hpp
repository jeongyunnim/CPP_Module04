#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : virtual public AAnimal
{

public:

	Cat(void);
	virtual ~Cat(void);
	Cat& operator=(const Cat& rhs);
	Cat(const Cat& other);

	void makeSound(void) const;
    void whereIsBrain(void) const;

private:
    Brain   *brain;

};