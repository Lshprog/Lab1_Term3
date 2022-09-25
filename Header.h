#pragma once
#include"MapStruct.h"
#include "BksCh.h"
#include <String>
namespace linkeld {

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
		template <typename A, typename B>
		void insertrion_sort() {
			Node<T> key = head->next;
			Node<T> temp = head;
			Node<T> key_2 = (key->next)->next;
			Node<T> temp_2 = key->next;

			/*while (key != nullptr&&temp->value > key->value) {
				(temp->prev)->next = key;
				(key->next)->prev = temp;
				temp->next = key->next;
				key->prev = temp->prev;
				temp->prev = key;
				key->next = temp;
				if (temp == head){
					head = key;

				else if (key = tail)
					tail = temp;
			}*/

			while (key != nullptr) {
				while (key != nullptr && books::compare<A>(temp,key)) {
					temp = temp->prev;
				}
				(temp->prev)->next = key;
				(key->next)->prev = temp;
				temp->next = key->next;
				key->prev = temp->prev;
				temp->prev = key;
				key->next = temp;
				if (temp == head)
					head = key;

				else if (key = tail)
					tail = temp;
			}
			key = key_2;
			temp = temp_2;
		}
	private:
		template <typename A> T get_value(A value) {
			Node<T> temp = head;
			do {
				if (temp->info->value == value)
					return temp;
				else
					temp = temp->next;
			} while (temp != nullptr || temp != head);
		}
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


	
}