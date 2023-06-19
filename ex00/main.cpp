#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

	std::cout << "========================================\n\n" << std::endl;

    const WrongAnimal* WrongMeta = new WrongAnimal();
    const WrongAnimal* WrongI = new WrongCat();

    std::cout << WrongI->getType() << " " << std::endl;
    WrongI->makeSound(); //will output the cat sound!
    WrongMeta->makeSound();

    delete WrongMeta;
    delete WrongI;

    return (0);
}