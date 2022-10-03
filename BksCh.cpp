#include "BksCh.h";

bool compare_books(books::Book node_1, books::Book node_2)
{
	if (node_1.pub_date >= node_2.pub_date)
		return true;
	else
		return false;
}
bool compare_books_no_equality(books::Book node_1, books::Book node_2)
{
	if (node_1.pub_date > node_2.pub_date)
		return true;
	else
		return false;
}

