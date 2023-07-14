#include "Character.hpp"

Character::Character(std::string name)
	:	_name(name)
{
	for(int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	floor.deleteAllNode();
    for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
		else
			return ;
	}
}

Character& Character::operator=(const Character& rhs)
{
    for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		else
			break ;
	}
    for (int i = 0; i < 4; i++)
	{
		if (rhs.inventory[i] != NULL)
			inventory[i] = rhs.inventory[i]->clone();
		else
			break ;
	}
	return (*this);
}

Character::Character(const Character& other)
{
	*this = other;
}

const std::string&  Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	if (m == NULL)
		return ;
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << _name << " equip the [" << inventory[i]->getType() << "]" << std::endl;
			return ;
		}
		else if (inventory[i] == m)
		{
			std::cout << "[Warning] Do not try equip duplicated Materia!" << std::endl;
			return ;
		}
	}
	std::cout << "inventory slot is full " << '[' << m->getType() << "] will be thrown to floor" << std::endl;
	floor.addNode(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "[Error] Out of inventory range.." << std::endl;
		return ;
	}
	if (inventory[idx] != NULL)
	{
		floor.addNode(inventory[idx]); 
		std::cout << _name << " unequip the " << inventory[idx]->getType() << std::endl;
		inventory[idx] = NULL;
	}
	for (int i = idx + 1; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			inventory[i - 1] = inventory[i];
			inventory[i] = NULL;
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "[Error] Out of inventory range.." << std::endl;
		return ;
	}
	if (inventory[idx] == NULL)
		std::cout << "There is empty slot..." << std::endl;
	else
		inventory[idx]->use(target);
}
