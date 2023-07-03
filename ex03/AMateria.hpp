#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
public:

	const std::string& getType(void) const;

	AMateria(void);
	virtual ~AMateria(void);
	virtual AMateria&	operator=(const AMateria& rhs);
	AMateria(const AMateria& rhs);

	AMateria(const std::string& type);
	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);

protected:

	std::string	_type;

};