#pragma once
#include <String>
namespace datastruct {
	template <typename T> class Node {
		Node<T>* next;
		Node<T>* prev;
		T info;
		Node(T info) {
			this->info = info;
			next = nullptr;
			prev = nullptr;
		}
	};
	template <typename T> class NodeList {

		Node<T>* head;
		Node<T>* tail;
	public:
		NodeList() {
			this->head = nullptr;
			this->tail = nullptr;
		}
		~NodeList() {
			//....
		}

		void add_to_list(Node<T> node) {
			if (head == nullptr && tail == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
		}

	};

	
	
	template <typename T> class ArrayList {

	};

	template <typename T> class VectorList {

	};




	template <typename T> class List {

	};

	template <typename T> class Stack :NodeList, ArrayList, VectorList {
		
	};

	template <typename T> class Queue :NodeList {

	};

	template <typename T> class DeQueue :NodeList {

	};


	template <typename A, typename B>class Map {
		class KeyVal {
			A key;
			B val;
		};
		KeyVal* tail = nullptr;
		KeyVal* head = nullptr;

		inline void addtomap(A key, B val)
		{
			KeyVal* node = new KeyVal(key, val);
			if (head == nullptr && tail == nullptr) {
				tail = node;
				head = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
		}
		
		inline B get_val(A key)
		{
			KeyVal* temp = head;
			while (true) {
				if (temp->key == key)
					return temp->val;
				if (temp->next == nullptr) {
					std::cout << "Error";
					return 0;
				}
				temp = temp->next;
			}
		}
		
		inline A get_key(B val)
		{
			KeyVal* temp = head;
			while (true) {
				if (temp->val == val)
					return temp->key;
				if (temp->next == nullptr) {
					std::cout << "Error";
					return 0;
				}
				temp = temp->next;
			}
		}
	};
	
	
}