#pragma once

#include <iostream>


const int arr_length = 30;



namespace arrayl{
	
	template <typename T> class ArrayList {
	public:
		T* array;
		int index_end;

		ArrayList() {
			this->index_end = 0;
			this->array = new T[arr_length];
		}

		~ArrayList() {
			
		}

		void add_elem(T data) {
			if (index_end < arr_length) {
				array[index_end] = data;
				index_end++;
			}
			else
				std::cout << "Not enough space!" << std::endl;
		}

		

		int search_elem_index(T data) {
			int i = 0;
			while (i<index_end) {
				if (check_equality(array[i],data)) {
					return i;
				}
				else
					i++;
			}
			std::cout << "No such elem" << std::endl;
			return -1;
		}

		

		void insertionSort()
		{
			int i, j;
			T key;
			for (i = 1; i < index_end; i++)
			{
				key = this->array[i];
				j = i - 1;

				while (j >= 0 && compare_books(this->array[j],key))
				{
					this->array[j + 1] = this->array[j];
					j = j - 1;
				}
				this->array[j + 1] = key;
			}
		}
		 void swap(T* arr, int i, int j)
		{
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		int partition(T* arr, int low, int high)
		{


			T pivot = arr[high];

			// Index of smaller element and
			// indicates the right position
			// of pivot found so far
			int i = (low - 1);

			for (int j = low; j <= high - 1; j++) {

				// If current element is smaller
				// than the pivot
				if (compare_books_no_equality(pivot,arr[j])) {

					// Increment index of
					// smaller element
					i++;
					swap(arr, i, j);
				}
			}
			swap(arr, i + 1, high);
			return (i + 1);
			
		}

		void quickSort(T* arr, int start, int end)
		{

			// base case
			if (start >= end)
				return;

			// partitioning the array
			int p = partition(arr,start, end);

			// Sorting the left part
			quickSort(arr, start, p - 1);

			// Sorting the right part
			quickSort(arr, p + 1, end);
		}


		void merge(T* arr, int const left, int const mid, int const right)
		{
			int const subArrayOne = mid - left + 1;
			int const subArrayTwo = right - mid;
			
			// Create temp arrays
			T* leftArray = new T[subArrayOne];
			T* rightArray = new T[subArrayTwo];

			// Copy data to temp arrays leftArray[] and rightArray[]
			for (int i = 0; i < subArrayOne; i++)
				leftArray[i] = arr[left + i];
			for (int j = 0; j < subArrayTwo; j++)
				rightArray[j] = arr[mid + 1 + j];

			int indexOfSubArrayOne = 0; // Initial index of first sub-array
			int	indexOfSubArrayTwo = 0; // Initial index of second sub-array
			int indexOfMergedArray = left; // Initial index of merged array

			// Merge the temp arrays back into array[left..right]
			while (indexOfSubArrayOne < subArrayOne
				&& indexOfSubArrayTwo < subArrayTwo) {
				if (compare_books(rightArray[indexOfSubArrayTwo], leftArray[indexOfSubArrayOne])) {
					arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
					indexOfSubArrayOne++;
				}
				else {
					arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
					indexOfSubArrayTwo++;
				}
				indexOfMergedArray++;
			}
			// Copy the remaining elements of
			// left[], if there are any
			while (indexOfSubArrayOne < subArrayOne) {
				arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
				indexOfMergedArray++;
			}
			// Copy the remaining elements of
			// right[], if there are any
			while (indexOfSubArrayTwo < subArrayTwo) {
				array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
				indexOfMergedArray++;
			}
			delete[] leftArray;
			delete[] rightArray;
		}

		// begin is for left index and end is
		// right index of the sub-array
		// of arr to be sorted */
		void mergeSort(T* arr, int const begin, int const end)//1st in end = index_end - 1
		{
			if (begin >= end)
				return; // Returns recursively

			auto mid = begin + (end - begin) / 2;
			mergeSort(arr, begin, mid);
			mergeSort(arr, mid + 1, end);
			merge(arr, begin, mid, end);
		}

	};

	template <typename T> class Stack :virtual public ArrayList<T> {
	public:
		T back_elem() {
			return this->array[this->index_end - 1];
		}
		void pop_back() {
			if (this->index_end > 0) {
				this->index_end--;
			}
			else {
				std::cout << "empty!!" << std::endl;
			}
		}
	};

	template <typename T>class Queue :virtual public ArrayList<T> {
	public:
		T front_elem() {
			return this->array[0];
		}

		void pop_front() {
			if (this->index_end > 0) {
				for (int i = 0; i < this->index_end; i++) {
					this->array[i] = this->array[i + 1];
				}
				this->index_end--;
			}
			else {
				std::cout << "empty!!" << std::endl;
			}
		}
	};
	

	template <typename T>class DeQue :public Stack<T>,public Queue<T> {
	public:
		void add_front(T data) {
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