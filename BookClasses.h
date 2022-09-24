#pragma once
#include "Header.h" 
#include "MapStruct.h"

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
		linkedl::LinkedList<std::string> list_of_names = linkedl::LinkedList<std::string>();
		linkedl:: LinkedList<Map<std::string, int>> list_of_books = linkedl::LinkedList<Map<std::string, int>>();

	};
};