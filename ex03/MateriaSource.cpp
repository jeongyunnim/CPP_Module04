#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < 4; i++)
	{
		sources[i] = NULL;
	}

}

MateriaSource::~MateriaSource(void)
{
	floor.deleteAllNode();
    for (int i = 0; i < 4; i++)
	{
		if (sources[i] != NULL)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (sources[i] == sources[j])
				{
					sources[i] = NULL;
					break ;
				}
			}
			if (sources[i] != NULL)
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
			for (int j = i + 1; j < 4; j++)
			{
				if (sources[i] == sources[j])
				{
					sources[i] = NULL;
					break ;
				}
			}
			if (sources[i] != NULL)
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
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	*this = rhs;
}


void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (sources[i] == NULL)
		{
			sources[i] = materia;
			return ;
		}
	}
	floor.addNode(materia);
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << sources[i]->getType() << std::endl;
		if (sources[i]->getType() == type)
		{
			std::cout << type << " successfully created" << std::endl;
			return (sources[i]->clone());
		}
	}
	return (NULL);
}
