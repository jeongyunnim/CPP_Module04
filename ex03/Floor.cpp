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
	floorNode	*ptr;
	floorNode	*temp;

	if (head == NULL)
		return ;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->content != NULL)
			delete ptr->content;
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
	head = NULL;
}

void	Floor::printNode(void)
{
	floorNode	*ptr;
	int i = 0;

	if (head == NULL)
	{
		std::cout << "Node empty" << std::endl;
		return ;
	}
	ptr = head;
	while (ptr != NULL)
	{
		std::cout << "\n" << i << "th node\n========================================\nhead: " << ptr << "\ncontent: " << ptr->content << std::endl;
		ptr = ptr->next;
		i++;
	}
}

void	Floor::addNode(AMateria *content)
{
	floorNode	*newNode = new floorNode();
	floorNode	*temp;


	newNode->content = content;
	if (head == NULL)
		head = newNode;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	newNode->next = NULL;
}
