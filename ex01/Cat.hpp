#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
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