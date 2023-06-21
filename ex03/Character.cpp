#include "Character.hpp"

Character::Character(std::string name)
    :   inventory{NULL, NULL, NULL, NULL}
	,	_name(name)
{
}

Character::~Character(void)
{
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
			break ;
		}
	}
	if (inventory[i] == m)
		std::cout << _name << " equip the materia" << std::endl;
}

void	Character::unequip(int idx)
{
	AMateria *temp;

	if (inventory[idx] != NULL)
	{
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
