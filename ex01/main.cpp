#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	Animal	*zoo[100];

	for (int index = 0; index < 100; index++)
	{
		if (index % 2 == 0)
			zoo[index] = new Dog();
		else
			zoo[index] = new Cat();
	}

	for (int index = 0; index < 100; index++)
	{
		delete zoo[index];
	}

	Dog target;
	const Dog* copyDog = new Dog(target);

	target.whereIsBrain();
	copyDog->whereIsBrain();

	delete copyDog;

    return (0);
}