#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
public:

	Cure(void);
	~Cure(void);
	Cure& operator=(const Cure& rhs);
	Cure(const Cure& rhs);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);

};