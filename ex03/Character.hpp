#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:

	~Character(void);
	Character& operator=(const Character& rhs);
	Character(const Character& other);

	Character(std::string name);
	const std::string&  getName(void) const;
	void    			equip(AMateria* m);
	void    			unequip(int idx);
	void    			use(int idx, ICharacter& target);

private:

	Character(void);

	AMateria	*inventory[4];
	std::string	_name;

};