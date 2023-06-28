#pragma once
#include "AMateria.hpp"

struct	floorNode
{
	AMateria			*content;
	struct floorNode	*next;
};

class Floor
{

public:

	Floor(void);
	~Floor(void);
	Floor& operator=(const Floor& rhs);
	Floor(const Floor& rhs);

	void	addNode(AMateria *content);
	void	deleteAllNode(void);

private:

	floorNode	*head;

};