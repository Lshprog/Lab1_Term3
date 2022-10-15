#pragma once
#ifndef BKSCH_H
#define BKSCH_H
#include "LinkedListImpl.h" 
#include "ArrayListimpl.h"
#include "VectorListimpl.h"
#include "Trees_impl.h"
#include <cmath>
#include <stdlib.h>

template <typename T>
class linkedl::List;

namespace books {
	
	class Book {
	public:
		char name[20];
		char author_name[20];
		char pub_date[10];
		int pub_date_key;
		int num_of_pages;
		char description[200];
		int id;

		Book(const char* name,const char* author_name,const char* pub_date, int num_of_pages,const char* description, int numb) {
			strcpy_s(this->name, _countof(this->name),name);
			strcpy_s(this->author_name, _countof(this->author_name), author_name);
			strcpy_s(this->pub_date, _countof(this->pub_date),pub_date);
			this->num_of_pages = num_of_pages;
			strcpy_s(this->description, _countof(this->description),description);
			this->id = numb;
			this->pub_date_key = convert_date(this->pub_date);
		}
		Book(){	
			this->name[20]=NULL;
			this->author_name[20] = NULL;
			this->pub_date[10]=NULL;
			this->description[200] = NULL;
			this->num_of_pages = 0;
			this->id = -1;
			this->pub_date_key = 0;
		}
		

		int convert_date(char* date);
	};
	template <typename A,typename B>
	class Character {
	public:
		
		A* list_of_names = new A();
		B* list_of_books = new B();

		Character() {
			
		}
	};
}
bool compare_books(books::Book node_1, books::Book node_2);
bool compare_books_no_equality(books::Book node_1, books::Book node_2);
bool check_equality(books::Book node_1, books::Book node_2);
linkedl::List<linkedl::List<books::Book>*> start_prog_linkedl(linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>> listofch);
arrayl::ArrayList<arrayl::ArrayList<books::Book>> start_prog_arrayl(arrayl::ArrayList<books::Character<arrayl::ArrayList<std::string>,
	arrayl::ArrayList<Pair<books::Book, int>>>> listofch);
vectorl::VectorList<vectorl::VectorList<books::Book>> start_prog_vectorl(vectorl::VectorList<books::Character<vectorl::VectorList<std::string>,
	vectorl::VectorList<Pair<books::Book, int>>>> listofch);
#endif