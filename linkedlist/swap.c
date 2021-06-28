#include "linkedlist.h"

void	swap(t_data *this, t_data *other)
{
	void	*tmp;

	tmp = this->data;
	this->data = other->data;
	other->data = tmp;
}
