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

		void add_to_list(Node<T>* node) {
			if (head == nullptr && tail == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
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
				while (key != nullptr && books::compare(temp->info, key->info)) {
					temp = temp->prev;
				}
				swap_nodes(temp, key);
				key = key_2;
				temp = temp_2;
			}
		}

		void quick_sort(Node<T>* low, Node<T>* high ) {

			if (books::compare(high->info, low->info)) {
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
				if (books::compare(pivot->info, temp->info)) {
					i_beg = i_beg->next;
					swap_nodes(temp,i_beg);
				}
			}
			swap_nodes(i_beg->next, pivot);
			return i_beg->next;
		}


		Node<T>* merge(Node<T>* firstNode, Node<T>* secondNode) {
			Node<T>* merged = new Node;
			Node<T>* temp = new Node;

			// merged is equal to temp so in the end we have the top
			// Node.
			merged = temp;

			// while either firstNode or secondNode becomes NULL
			while (firstNode != NULL && secondNode != NULL) {

				if (firstNode->data <= secondNode->data) {
					temp->next = firstNode;
					firstNode = firstNode->next;
				}

				else {
					temp->next = secondNode;
					secondNode = secondNode->next;
				}
				temp = temp->next;
			}

			// any remaining Node in firstNode or secondNode gets
			// inserted in the temp List
			while (firstNode != NULL) {
				temp->next = firstNode;
				firstNode = firstNode->next;
				temp = temp->next;
			}

			while (secondNode != NULL) {
				temp->next = secondNode;
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
			mid->next = nullptr;

			Node<T>* finalhead = merge(start_merge_sort(head),start_merge_sort(head2));
			return finalhead;
		}
		
	};



	template <typename T> class Stack :LinkedList {
	public:
		Node<T>* pop_end() {
			Node<T>* temp = tail;
			tail = (tail->prev);
			tail->next = nullptr;
			return temp;
		}

	};

	template <typename T> class Queue :LinkedList {
	public:
		Node<T>* pop_front() {
			Node<T>* temp = head;
			head = (head->next);
			head->prev = nullptr;
			return temp;
		}

	};

	template <typename T> class DeQueue :Stack, Queue {
	public:
		void add_beg(Node<T>* node) {
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