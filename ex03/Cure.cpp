#include "Cure.hpp"

Cure::Cure(void)
	:	AMateria("cure")
{
}

Cure::~Cure(void)
{
}

Cure& Cure::operator=(const Cure& rhs)
{
	_type = rhs._type;
	return (*this);
}

Cure::Cure(const Cure& rhs)
	:	AMateria(rhs._type)
{
}

AMateria*	Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
