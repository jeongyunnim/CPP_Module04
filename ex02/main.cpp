#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	delete j;//should not create a leak
	delete i;

	AAnimal	*zoo[100];

	for (int index = 0; index < 100; index++)
	{
		if (index < 50)
			zoo[index] = new Dog();
		else
			zoo[index] = new Cat();
	}

	for (int index = 0; index < 100; index++)
	{
		delete zoo[index];
	}

	Dog target;
	Dog* copyDog = new Dog(target);

	target = *copyDog;

	target.whereIsBrain();
	copyDog->whereIsBrain();

	delete copyDog;

    return (0);
}