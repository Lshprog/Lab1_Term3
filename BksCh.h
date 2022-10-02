#pragma once
#ifndef BKSCH_H
#define BKSCH_H
#include "LinkedListImpl.h" 
#include "Trees_impl.h"

template <typename T>
class linkedl::List;

namespace books {
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
		linkedl::List<std::string> list_of_names = linkedl::List<std::string>();
		linkedl::List<Map<std::string, int>> list_of_books = linkedl::List<Map<std::string, int>>();

	};
}
bool compare_books(books::Book node_1, books::Book node_2);
#endif