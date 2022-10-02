#pragma once

#include <iostream>

const int arr_length = 30;

namespace arrayl{
	//to do: deletion rebalance
	template <typename T> class ArrayList {
	public:
		T* array;
		int index_end;

		ArrayList() {
			this->end = 0;
			this->array = new T[arr_length];
		}

		~ArrayList() {
			delete[] array;
		}

		void add_elem(T data) {
			if (index_end < arr_length) {
				array[index_end] = data;
				index_end++;
			}
			else
				std::cout << "Not enough space!" << std::endl;
		}

		void delete_elem(T data) {
			int i = search_elem_index(data);
			delete array[i];
			index_end--;
		}

		int search_elem_index(T data) {
			int i = 0;
			while (i<index_end) {
				if (array[i] == data) {
					return i;
				}
				else
					i++;
			}
			std::cout << "No such elem" << std::endl;
			return NULL;
		}

		void swap_elements() {
			int i = 0;
			int amount_of_gaps = 0;
			T temp = new T();

			while (i < index_end) {
				if (array[i] == NULL) {
					amount_of_gaps++;
					i++;
				}
				else if (amount_of_gaps > 0) {
					array[i-amount_of_gaps] = array[i];
					i++;
				}
				else
					i++;
			}
			index_end = index_end - amount_of_gaps;
		}
	};

	template <typename T> class Stack :virtual ArrayList<T> {
		
		T back_elem() {
			return this->array[this->index_end - 1];
		}
	};

	template <typename T>class Queue :virtual ArrayList<T> {
		T front_elem() {
			return this->array[0];
		}

		void pop_front() {
			delete this->array[0];
			this->swap_elements();
		}
	};
	

	template <typename T>class DeQueue :Stack<T>,Queue<T> {
	public:
		void add_front(T data) {
			if (this->index_end >= arr_length)
				this->swap_elements();

			if (this->index_end >= arr_length)
				std::cout << "DeQueue is full!!!" << std::endl;
			else {
				int i = this->index_end;
				while (i>0) {
					this->array[i] =this->array[i - 1];
					i--;
				}
				this->index_end++;

				this->array[0] = data;
				
			}
		}
	};

}