#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
}

Brain&	Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i].clear();
		ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = idea;
	}
}