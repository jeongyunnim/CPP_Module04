#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{

public:

    Dog(void);
    virtual ~Dog(void);
    Dog& operator=(const Dog& rhs);
    Dog(const Dog& other);

	void makeSound(void) const;
    void whereIsBrain(void) const;

private:

    Brain   *brain;

};