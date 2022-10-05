#include "BksCh.h";
#include <cmath>

bool compare_books(books::Book node_1, books::Book node_2)
{
	if (node_1.pub_date_key >= node_2.pub_date_key)
		return true;
	else
		return false;
}
bool compare_books_no_equality(books::Book node_1, books::Book node_2)
{
	if (node_1.pub_date_key > node_2.pub_date_key)
		return true;
	else
		return false;
}

int books::Book::convert_date(std::string date) {
	int temp = 0;
	temp = (int(date[4]) - 48) * pow(10, 7) + (int(date[5]) - 48) * pow(10, 6) + (int(date[6]) - 48) * pow(10, 5) +
		(int(date[7]) - 48) * pow(10, 4) + (int(date[2]) - 48) * pow(10, 3) + (int(date[3]) - 48) * pow(10, 2) +
		(int(date[0]) - 48) * pow(10, 1) + (int(date[1]) - 48) * pow(10, 0);
	return temp;
}