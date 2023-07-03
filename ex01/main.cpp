#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leak()
{
	system("leaks $PPID");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	atexit(leak);
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

	Cat target;
	Cat* copyCat = new Cat(target);

	target.whereIsBrain();
	copyCat->whereIsBrain();

	delete copyCat;

	return (0);
}
