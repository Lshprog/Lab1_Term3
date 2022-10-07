#pragma once
#ifndef LINKEDLISTIMPL_H
#define LINKEDLISTIMPL_H
#include<iostream>
#include <String>
#include"MapStruct.h"



template <typename T>
bool compare_books(T node_1, T node_2)
{
	if (node_1.pub_date_key >= node_2.pub_date_key)
		return true;
	else
		return false;
}
template <typename T>
bool compare_books_no_equality(T node_1, T node_2)
{
	if (node_1.pub_date_key > node_2.pub_date_key)
		return true;
	else
		return false;
}



namespace linkedl {
	template<typename T> class List;

	template <typename T> class Node {
	public:
		T data;
		Node<T>* next;
		Node<T>* prev;
		Node() {
			next = nullptr;
			prev = nullptr;
		}
		Node(T data) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
		~Node() {
			
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
			Node<T>* iter = this->head;
			while (iter != nullptr)
			{
				Node<T>* temp = iter->next;
				iter->~Node();
				iter = temp;
			}
			this->head = nullptr;
			this->tail = nullptr;
		}

		void add_elem(T data) {
			Node<T>* new_node = new Node<T>(data);
			if (head == nullptr && tail == nullptr) {
				head = new_node;
				tail = new_node;
			}
			else {
				tail->next = new_node;
				new_node->prev = tail;
				tail = new_node;
			}
		}
		
		void push_elem(T data) {
			Node<T>* node = new Node<T>(data);
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

		void swap_nodes(Node<T>* temp, Node<T>* key) {
			if (temp->prev != nullptr && key->next!=nullptr) {//CHANGED TOTAL SHIT
				(temp->prev)->next = key;

				(key->next)->prev = temp;
				temp->next = key->next;
				key->prev = temp->prev;
			}
			if (temp->next = key) {

				temp->prev = key;
				key->next = temp;
			}
			else {
				if (key != nullptr) {//changed shit
					temp->prev = key->prev;
					key->next = temp->next;
				}
			}
			if (temp == head)
				head = key;

			else if (key = tail)
				tail = temp;
		}

		void insertionSort(Node<T>* headref)
		{
			// Initialize sorted linked list
			Node<T>* sorted = nullptr;
			Node<T>* current = headref;
			// Traverse the given linked list and insert every
			// node to sorted
			while (current != nullptr) {
				// Store next for next iteration
				Node<T>* nextn = current->next;
				// insert current in sorted linked list
				sortedInsert(current,sorted);
				// Update current
				current = nextn;
			}
			// Update head_ref to point to sorted linked list
			head = sorted;
		}

		/*
		 * function to insert a new_node in a list. Note that
		 * this function expects a pointer to head_ref as this
		 * can modify the head of the input linked list
		 * (similar to push())
		 */
		void sortedInsert(Node<T>* newnode,Node<T>* &sorted)
		{
			/* Special case for the head end */
			if (sorted == nullptr || compare_books(sorted->data,newnode->data)) {
				newnode->next = sorted;
				if (sorted != nullptr)
					sorted->prev = newnode;
				else
					tail = newnode;
				sorted = newnode;
			}
			else {
				Node<T>* current = sorted;
				/* Locate the node before the point of insertion
				 */
				while (current->next != nullptr
					&& compare_books_no_equality(newnode->data,current->next->data)) {
					current = current->next;
				}
				newnode->next = current->next;
				if (current->next != nullptr)
					(current->next)->prev = newnode;
				else
					tail = newnode;
				
				current->next = newnode;
				newnode->prev = current;
			}
		}
		/* Function to print linked list */
		/*void printlist(Node* head)
		{
			while (head != NULL) {
				cout << head->val << " ";
				head = head->next;
			}
		}*/



		/* Swap data of nodes */
		void swap(T* a, T* b)
		{
			T t = *a; *a = *b; *b = t;
		}

		/* Considers last element as pivot,
		places the pivot element at its
		correct position in sorted array,
		and places all smaller (smaller than
		pivot) to left of pivot and all greater
		elements to right of pivot */
		Node<T>* partition(Node<T>* l, Node<T>* h)
		{
			// set pivot as h element 
			T x = h->data;

			// similar to i = l-1 for array implementation 
			Node<T>* i = l->prev;

			// Similar to "for (int j = l; j <= h- 1; j++)" 
			for (Node<T>* j = l; j != h; j = j->next)
			{
				if (compare_books(x,j->data))
				{
					// Similar to i++ for array 
					i = (i == nullptr) ? l : i->next;

					swap(&(i->data), &(j->data));
				}
			}
			i = (i == nullptr) ? l : i->next; // Similar to i++ 
			swap(&(i->data), &(h->data));
			return i;
		}

		/* A recursive implementation
		of quicksort for linked list */
		void _quickSort(Node<T>* l, Node<T>* h)
		{
			if (h != NULL && l != h && l != h->next)
			{
				Node<T>* p = partition(l, h);
				_quickSort(l, p->prev);
				_quickSort(p->next, h);
			}
		}

		// The main function to sort a linked list.
		// It mainly calls _quickSort() 
		void quickSort()
		{
			// Find last node 
			Node<T>* h = tail;

			// Call the recursive QuickSort 
			_quickSort(head, h);
		}

		Node<T>* merge(Node<T>* firstNode, Node<T>* secondNode) {
			Node<T>* merged = new Node<T>();
			Node<T>* temp = new Node<T>();

			// merged is equal to temp so in the end we have the top
			// Node.
			merged = temp;

			// while either firstNode or secondNode becomes NULL
			while (firstNode != nullptr && secondNode != nullptr) {

				if (compare_books_no_equality(secondNode->data,firstNode->data)) {
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
		Node<T>* start_merge_sort(Node<T>* head) {
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

		T end() {
			if (this->tail->data != nullptr) {
				return this->tail->data;
			}
			else {
				std::cout << "stack is empty!" << std::endl;
				return nullptr;
			}
		}
		void pop_end() {

			Node<T>* temp = this->tail;
			if (this->tail != nullptr) {
				if (this->tail == this->head) {
					this->head = nullptr;
					this->tail = nullptr;
				}
				else {
					this->tail = (this->tail->prev);
					this->tail->next = nullptr;
					temp->prev = nullptr;
				}
				
			}
			else {
				std::cout << "stack is empty!" << std::endl;
				
			}
			delete temp;
		}

	};

	template <typename T> class Queue :virtual List<T> {
	public:

		T front() {
			if (this->head->data != nullptr) {
				return this->head->data;
			}
			else {
				std::cout << "queue is empty!" << std::endl;
				return nullptr;
			}
		}

		void pop_front() {
			Node<T>* temp = this->head;
			if (this->head != nullptr) {
				if (this->tail == this->head) {
					this->head = nullptr;
					this->tail = nullptr;
				}
				else {
					this->head = (this->head->next);
					this->head->prev = nullptr;
					temp->next = nullptr;
				}
			}
			else {
				std::cout << "queue is empty!" << std::endl;
			}
			delete temp;
		}

	};

	template <typename T> class DeQueue :Stack<T>, Queue<T> {
	public:
		
	};


	
}
#endif

