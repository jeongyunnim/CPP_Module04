#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const AAnimal* j = new Dog(); // 부모 개체 생성은 명시적으로 필요한가?
	const AAnimal* i = new Cat();

	std::cout << j->getType() << std::endl;

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
	const Dog target;
	const Dog* copyDog = new Dog(target);

	target.whereIsBrain();
	copyDog->whereIsBrain();

	delete copyDog;

    return (0);
}