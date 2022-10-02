#pragma once
#ifndef LINKEDLISTIMPL_H
#define LINKEDLISTIMPL_H
#include<iostream>
#include <String>
#include"MapStruct.h"
//#include "BksCh.h"

template <typename T>
bool compare_books(T data1,T data2);

namespace linkedl {

	template <typename T> class Node {
	public:
		T data;
		Node<T>* next;
		Node<T>* prev;
		Node() {
			this->data = NULL;
			next = nullptr;
			prev = nullptr;
		}
		Node(T data) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
		

	};
	template <typename T> class List {
	public:
		Node<T>* head;
		Node<T>* tail;
	
		List() {
			this->head = nullptr;
			this->tail = nullptr;
		}
		~List() {
			//....
		}

		void add_elem(Node<T>* node) {
			if (head == nullptr && tail == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				node->prev = tail;
				tail = node;
			}
		}

		void swap_nodes(Node<T>* temp, Node<T>* key) {

			(temp->prev)->next = key;
			(key->next)->prev = temp;
			temp->next = key->next;
			key->prev = temp->prev;
			if (temp->next = key) {

				temp->prev = key;
				key->next = temp;
			}
			else {
				temp->prev = key->prev;
				key->next = temp->next;
			}
			if (temp == head)
				head = key;

			else if (key = tail)
				tail = temp;
		}

		template <typename A> void insertrion_sort() {
			Node<T>* key = head->next;
			Node<T>* temp = head;
			Node<T>* key_2 = (key->next)->next;
			Node<T>* temp_2 = key->next;

			while (key != nullptr) {
				while (key != nullptr && compare_books(temp->data, key->data)) {
					temp = temp->prev;
				}
				swap_nodes(temp, key);
				key = key_2;
				temp = temp_2;
			}
		}

		void quick_sort(Node<T>* low, Node<T>* high ) {

			if (compare_books(high->data, low->data)) {
				Node<T>* node = partition_func(low, high);

				quick_sort(low, node->prev);
				quick_sort(node->next, high);
			}
		}


		Node<T>* partition_func(Node<T>* low, Node<T>* high) {


			Node<T>* pivot = high;
			Node<T>* i_beg = low->prev;
			Node<T>* temp = low;

			while(temp!=high) {
				if (compare_books(pivot->data, temp->data)) {
					i_beg = i_beg->next;
					swap_nodes(temp,i_beg);
				}
			}
			swap_nodes(i_beg->next, pivot);
			return i_beg->next;
		}


		Node<T>* merge(Node<T>* firstNode, Node<T>* secondNode) {
			Node<T>* merged = new Node<T>();
			Node<T>* temp = new Node<T>();

			// merged is equal to temp so in the end we have the top
			// Node.
			merged = temp;

			// while either firstNode or secondNode becomes NULL
			while (firstNode != nullptr && secondNode != nullptr) {

				if (compare_books(secondNode->data,firstNode->data)) {
					temp->next = firstNode;
					firstNode->prev = temp;
					firstNode = firstNode->next;
				}

				else {
					temp->next = secondNode;
					secondNode->prev = temp;
					secondNode = secondNode->next;
				}
				temp = temp->next;
			}

			// any remaining Node in firstNode or secondNode gets
			// inserted in the temp List
			while (firstNode != nullptr) {
				temp->next = firstNode;
				firstNode->prev = temp;
				firstNode = firstNode->next;
				temp = temp->next;
			}

			while (secondNode != nullptr) {
				temp->next = secondNode;
				secondNode->prev = temp;
				secondNode = secondNode->next;
				temp = temp->next;
			}
			// return the head of the sorted list
			return merged->next;
		}

		Node<T>* middle(Node<T>* head)
		{
			Node<T>* slow = head;
			Node<T>* fast = head->next;

			while (!slow->next && (!fast && !fast->next)) {
				slow = slow->next;
				fast = fast->next->next;
			}
			return slow;
		}
		Node<T>* start_merge_sort() {
			if (head->next == nullptr)
				return head;

			Node<T>* mid = new Node<T>();
			Node<T>* head2 = new Node<T>();

			mid = middle(head);
			head2 = mid->next;
			head2->prev = nullptr;
			mid->next = nullptr;

			Node<T>* finalhead = merge(start_merge_sort(head),start_merge_sort(head2));
			return finalhead;
		}
		
	};



	template <typename T> class Stack :virtual List<T> {
	public:
		Node<T>* pop_end() {
			if (this->tail != nullptr) {
				Node<T>* temp = this->tail;
				this->tail = (this->tail->prev);
				this->tail->next = nullptr;
				temp->prev = nullptr;
				return temp;
			}
			else {
				std::cout << "stack is empty!" << std::endl;
				return nullptr;
			}
		}

	};

	template <typename T> class Queue :virtual List<T> {
	public:

		T* front() {
			if (this->head->data != nullptr) {
				return this->head->data;
			}
			else {
				std::cout << "queue is empty!" << std::endl;
				return nullptr;
			}
		}

		void pop_front() {
			if (this->head != nullptr) {
				Node<T>* temp = this->head;
				this->head = (this->head->next);
				this->head->prev = nullptr;
				temp->next = nullptr;
			}
			else {
				std::cout << "queue is empty!" << std::endl;
			}
		}

	};

	template <typename T> class DeQueue :Stack<T>, Queue<T> {
	public:
		void add_beg(Node<T>* node) {
			if (this->head == nullptr && this->tail == nullptr) {
				this->head = node;
				this->tail = node;
			}
			else {
				node->next = this->head;
				this->head->prev = node;
				this->head = node;
				
			}
		}
	};


	
}
#endif