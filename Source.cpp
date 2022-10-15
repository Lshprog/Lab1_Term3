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

int main() {

	/*linkedl::List<books::Book> list1 = linkedl::List<books::Book>();
	books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc","alex","12122003",20,"nice",1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);
	list1.add_elem(book1);
	list1.add_elem(book2);
	list1.add_elem(book3);
	linkedl::Node<books::Book>* temp = list1.head;
	while (temp != nullptr) {
		std::cout << temp->data.pub_date_key<<std::endl;
		temp = temp->next;
	}

	linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>> listch =
		linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>>();

	books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>character1 =
		books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>();

	character1.list_of_names->add_elem("Oleg");
	character1.list_of_names->add_elem("Oleg228");
	character1.list_of_names->add_elem("Lesha777");
	Pair<books::Book,int> pair1 = Pair<books::Book, int>(book1,1);
	Pair<books::Book, int> pair2 = Pair<books::Book, int>(book2, 2);
	Pair<books::Book, int> pair3 = Pair<books::Book, int>(book3, 2);
	character1.list_of_books->add_elem(pair1);
	character1.list_of_books->add_elem(pair2);
	character1.list_of_books->add_elem(pair3);
	listch.add_elem(character1);
	linkedl::List<linkedl::List<books::Book>*> series =	start_prog_linkedl(listch);*/



	/*arrayl::ArrayList<books::Book> arrlist1 = arrayl::ArrayList<books::Book>();
	books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);
	arrlist1.add_elem(book1);
	arrlist1.add_elem(book2);
	arrlist1.add_elem(book3);
	for (int i = 0; i < arrlist1.index_end; i++) {
		std::cout << arrlist1.array[i].pub_date_key <<std::endl;
	}

	arrayl::ArrayList<books::Character<arrayl::ArrayList<std::string>, arrayl::ArrayList<Pair<books::Book, int>>>> listch =
		arrayl::ArrayList<books::Character<arrayl::ArrayList<std::string>, arrayl::ArrayList<Pair<books::Book, int>>>>();

	books::Character<arrayl::ArrayList<std::string>, arrayl::ArrayList<Pair<books::Book, int>>>character1 =
		books::Character<arrayl::ArrayList<std::string>, arrayl::ArrayList<Pair<books::Book, int>>>();

	character1.list_of_names->add_elem("Oleg");
	character1.list_of_names->add_elem("Oleg228");
	character1.list_of_names->add_elem("Lesha777");
	Pair<books::Book, int> pair1 = Pair<books::Book, int>(book1, 1);
	Pair<books::Book, int> pair2 = Pair<books::Book, int>(book2, 2);
	Pair<books::Book, int> pair3 = Pair<books::Book, int>(book3, 2);
	character1.list_of_books->add_elem(pair1);
	character1.list_of_books->add_elem(pair2);
	character1.list_of_books->add_elem(pair3);
	listch.add_elem(character1);

	arrayl::ArrayList<arrayl::ArrayList<books::Book>> series = start_prog_arrayl(listch);

	std::cout << std::endl;
	for (int i = 0; i < series.index_end; i++) {
		for (int j = 0; j < series.array[i].index_end; j++) {
			std::cout << series.array[i].array[j].pub_date_key << std::endl;
		}
	}*/


	/*vectorl::VectorList<books::Book> veclist1 = vectorl::VectorList<books::Book>();
	books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);
	veclist1.add_elem(book1);
	veclist1.add_elem(book2);
	veclist1.add_elem(book3);
	
	for (int i = 0; i < veclist1.index_end; i++) {
		std::cout << veclist1.array[i].pub_date_key << std::endl;
	}

	vectorl::VectorList<books::Character<vectorl::VectorList<std::string>, vectorl::VectorList<Pair<books::Book, int>>>> listch =
		vectorl::VectorList<books::Character<vectorl::VectorList<std::string>, vectorl::VectorList<Pair<books::Book, int>>>>();

	books::Character<vectorl::VectorList<std::string>, vectorl::VectorList<Pair<books::Book, int>>>character1 =
		books::Character<vectorl::VectorList<std::string>, vectorl::VectorList<Pair<books::Book, int>>>();

	character1.list_of_names->add_elem("Oleg");
	character1.list_of_names->add_elem("Oleg228");
	character1.list_of_names->add_elem("Lesha777");
	Pair<books::Book, int> pair1 = Pair<books::Book, int>(book1, 1);
	Pair<books::Book, int> pair2 = Pair<books::Book, int>(book2, 2);
	Pair<books::Book, int> pair3 = Pair<books::Book, int>(book3, 2);
	character1.list_of_books->add_elem(pair1);
	character1.list_of_books->add_elem(pair2);
	character1.list_of_books->add_elem(pair3);
	listch.add_elem(character1);

	vectorl::VectorList<vectorl::VectorList<books::Book>> series = start_prog_vectorl(listch);

	std::cout << std::endl;

	for (int i = 0; i < series.index_end; i++) {
		for (int j = 0; j < series.array[i].index_end; j++) {
			std::cout << series.array[i].array[j].pub_date_key << std::endl;
		}
	}*/


	/*books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);
	trees::BinarySearchTree<books::Book> newtree = trees::BinarySearchTree<books::Book>();
	newtree.bnode_insert(new trees::Binary_Node<books::Book>(book1), newtree.root);
	newtree.bnode_insert(new trees::Binary_Node<books::Book>(book2), newtree.root);
	newtree.bnode_insert(new trees::Binary_Node<books::Book>(book3), newtree.root);
	newtree.treeout(newtree.root);
	newtree.bnode_delete(book1);
	newtree.bnode_delete(book3);
	newtree.treeout(newtree.root);*/

	/*books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

	trees::GeneralTree<books::Book> newtree = trees::GeneralTree<books::Book>();
	newtree.arbnode_insert(book1);
	newtree.arbnode_insert(book2);
	newtree.arbnode_insert(book3);
	newtree.arbnode_delete(book2);*/


	/*books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book3 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

	trees::GeneralTreeVector<books::Book> newtree = trees::GeneralTreeVector<books::Book>();
	newtree.arb_node_vec_insert(book1);
	newtree.arb_node_vec_insert(book2);
	newtree.arb_node_vec_insert(book3);
	newtree.arbnode_delete(book2);*/


}






