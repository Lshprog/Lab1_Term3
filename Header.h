#pragma once
#include <String>
namespace datastruct {
	template <typename T> class Node {
		Node<T>* next;
		Node<T>* prev;
		
		Node(T info) {
			this->info = info;
			next = nullptr;
			prev = nullptr;
		}
	public:
		T info;
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



	template <typename T> class Stack :NodeList {
	public:
		Node<T> pop_end() {
			Node<T> temp = tail;
			tail = (tail->prev);
			tail->next = nullptr;
			return temp;
		}
		
	};

	template <typename T> class Queue :NodeList {
	public:
		Node<T> pop_front() {
			Node<T> temp = head;
			head = (head->next);
			head->prev = nullptr;
			return temp;
		}

	};

	template <typename T> class DeQueue :Stack, Queue {
	public:
		void add_beg(Node<T> node) {
			if (head == nullptr && tail == nullptr) {
				head = node;
				tail = node;
			}
			else {
				head->prev = node;
				head = node;
			}
		}
	};


	template <typename A, typename B>class Map {
	public:
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