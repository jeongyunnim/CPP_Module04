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

	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	floor.addNode(m);
}

void	Character::unequip(int idx)
{
	if (inventory[idx] != NULL)
	{
		floor.addNode(inventory[idx]);
		inventory[idx] = NULL;
		std::cout << _name << " unequip the materia" << std::endl;
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
	if (inventory[idx] == NULL)
		std::cout << "Nothing happened..." << std::endl;
	else
		inventory[idx]->use(target);
}
