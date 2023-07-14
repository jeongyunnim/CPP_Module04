#include "Ice.hpp"

Ice::Ice(void)
	:	AMateria("ice")
{
}

Ice::~Ice(void)
{
}

Ice& Ice::operator=(const Ice& rhs)
{
	_type = rhs._type;
	return (*this);
}

Ice::Ice(const Ice& rhs)
	:	AMateria(rhs._type)
{
}

AMateria*	Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
