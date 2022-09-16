#pragma once
#include <String>
namespace books {
	class Book {
		std::string name;
		int key_to_author;
		std::string pub_date;
		int num_of_pages;
		std::string small_description;
		int numb;
	};
	class Character {
		NodeList<std::string> list_of_names = NodeList<std::string>();
		NodeList<Map<std::string,int>> list_of_books = NodeList<Map<std::string, int>>();

	};
	template <typename T>class NodeList {
		class Node {
			Node* next = nullptr;
			T info = 0;
			Node(T info);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	};
	template <typename A, typename B>class Map {
		class KeyVal {
			A key;
			B val;
		};
		KeyVal* tail = nullptr;
		KeyVal* head = nullptr;

		void addtomap(A key,B val);
		B give_val(A key);
		A give_key(B val);
	};
}