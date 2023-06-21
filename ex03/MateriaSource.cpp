#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
	:	sources{NULL, NULL, NULL, NULL}
{
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
	{
		if (sources[i] != NULL)
		{
			delete sources[i];
			sources[i] = NULL;
		}
		else
			break ;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    for (int i = 0; i < 4; i++)
	{
		if (sources[i] != NULL)
		{
			delete sources[i];
			sources[i] = NULL;
		}
		else
			break ;
	}
    for (int i = 0; i < 4; i++)
	{
		if (rhs.sources[i] != NULL)
			sources[i] = rhs.sources[i]->clone();
		else
			break ;
	}
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	*this = rhs;
}


void	MateriaSource::learnMateria(AMateria* materia)
{

}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	
}
