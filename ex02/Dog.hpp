#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : virtual public AAnimal
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