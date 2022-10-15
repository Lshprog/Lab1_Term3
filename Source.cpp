#include "BksCh.h"
#include "LinkedListImpl.h"
#include "Trees_impl.h"
#include "ArrayListImpl.h"
#include "VectorListImpl.h"
#include "MapStruct.h"
//#include <iostream>

linkedl::List<linkedl::List<books::Book>*> start_prog_linkedl(linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>> listofch) {
	linkedl::List<linkedl::List<books::Book>*> series = linkedl::List<linkedl::List<books::Book>*>();
	linkedl::Node<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>>* tempn = listofch.head;

	while (tempn != nullptr) {
		
		linkedl::Node<linkedl::List<books::Book>>* temp_node_series = new linkedl::Node<linkedl::List<books::Book>>();

		linkedl::Node<Pair<books::Book, int>>* temp_pair = tempn->data.list_of_books->head;

		while (temp_pair != nullptr) {
			if (temp_pair->data.value_2 < 3) {
				linkedl::Node<books::Book>* newnode = new linkedl::Node<books::Book>(temp_pair->data.value_1);
				temp_node_series->data.add_elem(newnode->data);
				temp_pair = temp_pair->next;
			}
		}


		temp_node_series->data.insertionSort(temp_node_series->data.head);
		//temp_node_series->data.quickSort();
		//temp_node_series->data.head = temp_node_series->data.start_merge_sort(temp_node_series->data.head);
		series.add_elem(&temp_node_series->data);
		tempn = tempn->next;

	}

	return series;
}

arrayl::ArrayList<arrayl::ArrayList<books::Book>> start_prog_arrayl(arrayl::ArrayList<books::Character<arrayl::ArrayList<std::string>,
	arrayl::ArrayList<Pair<books::Book, int>>>> listofch) {

	int i = 0;

	arrayl::ArrayList<arrayl::ArrayList<books::Book>> series = arrayl::ArrayList<arrayl::ArrayList<books::Book>>();
	

	while (i < listofch.index_end) {

		books::Character<arrayl::ArrayList<std::string>, arrayl::ArrayList<Pair<books::Book, int>>> tempn = listofch.array[i];

		int j = 0;
		arrayl::ArrayList<books::Book> temp_node_series = arrayl::ArrayList<books::Book>();

		while (j < tempn.list_of_books->index_end) {
			Pair<books::Book, int> temp_pair = tempn.list_of_books->array[j];
			if (temp_pair.value_2 < 3) {
				temp_node_series.add_elem(temp_pair.value_1);
			}
			j++;
		}
		
		//temp_node_series.insertionSort();
		//temp_node_series.quickSort(temp_node_series.array,0,temp_node_series.index_end-1);
		temp_node_series.mergeSort(temp_node_series.array,0,temp_node_series.index_end-1);
		series.add_elem(temp_node_series);
		i++;
	}

	return series;
}


vectorl::VectorList<vectorl::VectorList<books::Book>> start_prog_vectorl(vectorl::VectorList<books::Character<vectorl::VectorList<std::string>,
	vectorl::VectorList<Pair<books::Book, int>>>> listofch) {

	int i = 0;

	vectorl::VectorList<vectorl::VectorList<books::Book>> series = vectorl::VectorList<vectorl::VectorList<books::Book>>();


	while (i < listofch.index_end) {

		books::Character<vectorl::VectorList<std::string>, vectorl::VectorList<Pair<books::Book, int>>> tempn = listofch.array[i];

		int j = 0;
		vectorl::VectorList<books::Book> temp_node_series = vectorl::VectorList<books::Book>();

		while (j < tempn.list_of_books->index_end) {
			Pair<books::Book, int> temp_pair = tempn.list_of_books->array[j];
			if (temp_pair.value_2 < 3) {
				temp_node_series.add_elem(temp_pair.value_1);
			}
			j++;
		}

		temp_node_series.insertionSort();

		series.add_elem(temp_node_series);
		i++;
	}

	return series;
}







