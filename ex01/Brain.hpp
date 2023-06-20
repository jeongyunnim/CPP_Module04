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
	
	void	printIdeasAddress(void);

private:

	std::string	ideas[100];

};