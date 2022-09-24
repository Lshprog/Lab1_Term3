#pragma once
#include <String>
namespace linkedl {
	/*template <typename T> class CircularLinkedList;*/
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
	template <typename T> class LinkedList {
	/*friend class CircularLinkedList ;*/

		Node<T>* head;
		Node<T>* tail;
	public:
		LinkedList() {
			this->head = nullptr;
			this->tail = nullptr;
		}
		~LinkedList() {
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
	/*private:
		template <typename T, typename A> T get_value(A value) {
			Node<T> temp = head;

		}*/

	};



	template <typename T> class Stack :LinkedList {
	public:
		Node<T> pop_end() {
			Node<T> temp = tail;
			tail = (tail->prev);
			tail->next = nullptr;
			return temp;
		}

	};

	template <typename T> class Queue :LinkedList {
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


	template <typename T> class CircularLinkedList :LinkedList {
		
	public:
		this->head->prev = tail;
		this->tail->next = head;
		void insert_elem(Node<T> node) {
			if (head == nullptr && tail == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = node;
				tail->next = head;
			}
		}
	};

	

}