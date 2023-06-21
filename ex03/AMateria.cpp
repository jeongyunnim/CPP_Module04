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
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		std::cout << "* Invalid type *" << std::endl;
} // 붙여놓고 삭제하기
