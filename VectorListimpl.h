#pragma once
#include <iostream>
#include <vector>


namespace vectorl {
	//to do: deletion rebalance
	template <typename T> class VectorList {
	public:
		std::vector<T> array = std::vector<T>();
		int index_end;

		VectorList() {
			this->index_end = 0;
		}

		~VectorList() {
			array.clear();
		}

		void add_elem(T data) {
			array.push_back(data);
			index_end++;
				
		}


		int search_elem_index(T data) {
			int i = 0;
			while (i < index_end) {
				if (array[i].id == data.id) {
					return i;
				}
				else
					i++;
			}
			std::cout << "No such elem" << std::endl;
			return -1;
		}

		void swap_elements_zeroes() {
			int i = 0;
			int amount_of_gaps = 0;
			T temp = new T();

			while (i < index_end) {
				if (array[i] == NULL) {
					amount_of_gaps++;
					i++;
				}
				else if (amount_of_gaps > 0) {
					array[i - amount_of_gaps] = array[i];
					i++;
				}
				else
					i++;
			}
			index_end = index_end - amount_of_gaps;
		}
	


		void insertionSort()
		{
			int i, j;
			T key;
			for (i = 1; i < index_end; i++)
			{
				key = this->array[i];
				j = i - 1;

				while (j >= 0 && compare_books(this->array[j], key))
				{
					this->array[j + 1] = this->array[j];
					j = j - 1;
				}
				this->array[j + 1] = key;
			}
		}

		int partition(std::vector<T>& arr, int start, int end)
		{

			T pivot = arr[start];

			int count = 0;
			for (int i = start + 1; i <= end; i++) {
				if (compare_books(pivot, arr[i]))
					count++;
			}

			// Giving pivot element its correct position
			int pivotIndex = start + count;
			T temp = arr[pivotIndex];
			arr[pivotIndex] = arr[start];
			arr[start] = temp;
			

			// Sorting left and right parts of the pivot element
			int i = start, j = end;

			while (i < pivotIndex && j > pivotIndex) {

				while (compare_books(pivot, arr[i])) {
					i++;
				}

				while (compare_books(arr[i], pivot)) {
					j--;
				}

				if (i < pivotIndex && j > pivotIndex) {
					temp = arr[i++];
					arr[i++] = arr[j--];
					arr[j--] = temp;
				}
			}
			
			return pivotIndex;
		}

		void quickSort(std::vector<T>& arr, int start, int end)
		{

			// base case
			if (start >= end)
				return;

			// partitioning the array
			int p = partition(arr, start, end);

			// Sorting the left part
			quickSort(arr, start, p - 1);

			// Sorting the right part
			quickSort(arr, p + 1, end);
		}


		void merge(std::vector<T>& arr, int const left, int const mid, int const right)
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
		void mergeSort(std::vector<T>& arr, int const begin, int const end)//1st in end = index_end - 1
		{
			if (begin >= end)
				return; // Returns recursively

			auto mid = begin + (end - begin) / 2;
			mergeSort(arr, begin, mid);
			mergeSort(arr, mid + 1, end);
			merge(arr, begin, mid, end);
		}
	};

	template <typename T> class Stack :virtual public VectorList<T> {
	public:
		T back_elem() {
			return this->array[this->index_end - 1];
		}
		void popBack() {
			if (this->index_end > 0) {
				this->array.pop_back();
				this->index_end--;
			}
			else {
				std::cout << "empty!!" << std::endl;
			}
		}
	};

	template <typename T>class Queue :virtual public VectorList<T> {
	public:
		T front_elem() {
			return this->array[0];
		}

		void pop_front() {
			if (this->index_end > 0) {
				this->array.erase(this->array.begin());
				this->index_end--;
			}
		}
	};


	template <typename T>class DeQue :public Stack<T>,public Queue<T> {
	public:
		void add_front(T data) {

			this->array.insert(this->array.begin(),data);
			this->index_end++;

		}
	};
}