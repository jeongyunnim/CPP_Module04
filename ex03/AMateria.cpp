#include "AMateria.hpp"

const std::string& AMateria::getType() const
{
    return (_type);
}

AMateria::AMateria(void)
    :   _type("* NONE *")
{
}

AMateria::~AMateria(void)
{
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
    _type = rhs._type;
    return (*this);
}

AMateria::AMateria(const AMateria& rhs)
{
    *this = rhs;
}

AMateria::AMateria(const std::string& type)
{
    _type = type;
}

void AMateria::use(ICharacter& target)
{
		std::cout << "* " << target.getName() << " Invalid type *" << std::endl;
}
