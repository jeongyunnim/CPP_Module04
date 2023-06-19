#pragma once
#include <iostream>
#include <string>

class Brain
{

public:

	Brain(void);
	~Brain(void);
	Brain&	operator=(const Brain& rhs);
	Brain(const Brain& other);
	
	void	setIdeas(std::string idea);

protected:

	std::string	ideas[100];

};