#include "AMateria.hpp"

class Ice : public AMateria
{
public:

	Ice(void);
	~Ice(void);
	Ice& operator=(const Ice& rhs);
	Ice(const Ice& rhs);

	AMateria*	clone(void);
	void	use(ICharacter& target);

};