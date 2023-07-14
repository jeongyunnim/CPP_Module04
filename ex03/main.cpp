#include "./AMateria.hpp"
#include "./Character.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"
#include "./ICharacter.hpp"
#include "./IMateriaSource.hpp"
#include "./MateriaSource.hpp"

void leak(void)
{
	system("leaks $PPID");
}

void    iMaterSourceTest(IMateriaSource& skillBook)
{
	std::cout << "[IMateriaSource test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "Filling skill book [ice][ice][ice][cure]" << std::endl;
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Cure());
	
	std::cout << "\n[Skill book's slot is full]" << std::endl;
	skillBook.learnMateria(new Ice());
}

void    equipTest(ICharacter& target, IMateriaSource& skillBook)
{
	std::cout << "\n[Equip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	AMateria* tmp;
	tmp = skillBook.createMateria("ice");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);

	std::cout << "\nTesting equip equipped Materia pointer already" << std::endl;
	target.equip(tmp);
	target.equip(tmp);
	target.equip(tmp);
	target.equip(tmp);

	std::cout << "\nFilling character's inventory with created other Materia" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	std::cout << "\nCharacter's inventory [ice][cure][cure][cure]" << std::endl;

	std::cout << "\n[Character's inventory slot is full]" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
}

void    useTest(ICharacter& target)
{
	std::cout << "\n[Use test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "\nTesting a character's use of a skill (material) in order" << std::endl;
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);
}

void    unequipTest(ICharacter& target)
{
	std::cout << "\n[Unequip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(0);
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);

	target.unequip(3);
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);
}

void    rangeTest(ICharacter& target)
{
	std::cout << "\n[range test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(4);
	target.unequip(-2147483648);
	target.use(4, target);
	target.use(-2147483648, target);
}

void    interactiveTest(ICharacter& target, IMateriaSource& skillBook)
{
	iMaterSourceTest(skillBook);
	equipTest(target, skillBook);
	useTest(target);
	unequipTest(target);
	rangeTest(target);
}

int main()
{
	atexit(leak);
	
	IMateriaSource* skillBook = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* monster = new Character("monster");

	interactiveTest(*me, *skillBook);

	me->use(0, *monster);
	me->use(1, *monster);

	delete monster;
	delete me;
	delete skillBook;

	return 0;
}