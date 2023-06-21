#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:

	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource& operator=(const MateriaSource& rhs);
	MateriaSource(const MateriaSource& rhs);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);

private:

	AMateria*	sources[4];

};
