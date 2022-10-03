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
		int pub_date_key;
		int num_of_pages;
		std::string description;
		int numb;

		Book(std::string name, int key_to_author, std::string pub_date, int num_of_pages, std::string description, int numb) {
			this->name = name;
			this->key_to_author = key_to_author;
			this->pub_date = pub_date;
			this->num_of_pages = num_of_pages;
			this->description = description;
			this->numb = numb;
		}
		Book(){	
			this->key_to_author = 0;
			this->num_of_pages = 0;
			this->numb = 0;
		}
	};
	class Character {
	public:
		linkedl::List<std::string> list_of_names = linkedl::List<std::string>();
		linkedl::List<Map<Book, int>> list_of_books = linkedl::List<Map<Book, int>>();

	};
}
bool compare_books(books::Book node_1, books::Book node_2);
bool compare_books_no_equality(books::Book node_1, books::Book node_2);

#endif