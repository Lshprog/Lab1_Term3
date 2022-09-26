#pragma once
#include "Header.h" 

namespace books{
	class Book {
	public:
		std::string name;
		int key_to_author;
		std::string pub_date;
		int num_of_pages;
		std::string description;
		int numb;
	};
	class Character {
	public:
		linkeld::LinkedList<std::string> list_of_names = linkeld::LinkedList<std::string>();
		linkeld::LinkedList<Map<std::string, int>> list_of_books = linkeld::LinkedList<Map<std::string, int>>();

	};
	bool compare(Book node_1, Book node_2) {

		if (node_1.pub_date > node_2.pub_date)
			return true;
		else
			return false;

	};
};