#include "Floor.hpp"

Floor::Floor(void)
	: head(NULL)
{
}

Floor::~Floor(void)
{
	deleteAllNode();
}

Floor& Floor::operator=(const Floor& rhs)
{
	deleteAllNode();
	head = rhs.head;
	return (*this);
}

Floor::Floor(const Floor& rhs)
{
	*this = rhs;
}

void	Floor::deleteAllNode(void)
{
	floorNode	*temp;

	if (head == NULL)
		return ;
	temp = head;
	while (temp != NULL)
	{
		delete temp->content;
		delete temp;
		temp = temp->next;
	}
	head = NULL;
}

void	Floor::addNode(AMateria *content)
{
	floorNode	*newNode = new floorNode();

	newNode->content = content; 
	if (head == NULL)
		head = newNode;
	else
	{
		floorNode *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	head->next = NULL;
}
