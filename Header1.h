#pragma once
#include "Header.h" 
using namespace datastruct;
namespace books{
	class Book {
		std::string name;
		int key_to_author;
		std::string pub_date;
		int num_of_pages;
		std::string description;
		int numb;
	};
	class Character {
		NodeList<std::string> list_of_names = NodeList<std::string>();
		NodeList<Map<std::string, int>> list_of_books = NodeList<Map<std::string, int>>();

	};
};