#include "BksCh.h"
#include "LinkedListImpl.h"
#include "Trees_impl.h"
#include "ArrayListImpl.h"
#include "MapStruct.h"
//#include <iostream>

linkedl::List<linkedl::List<books::Book>*> start_prog_linkedl(linkedl::List<books::Character> listofch) {
	linkedl::List<linkedl::List<books::Book>*> series = linkedl::List<linkedl::List<books::Book>*>();
	linkedl::Node<books::Character>* tempn = listofch.head;

	while (tempn != nullptr) {
		/*books::Character* temp = new books::Character();*/
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

arrayl::ArrayList<arrayl::ArrayList<books::Book>> start_prog_arrayl(arrayl::ArrayList<books::Character> listofch) {

}


int main() {
	/*linkedl::List<books::Book> list1 = linkedl::List<books::Book>();
	books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc","alex","12122003",20,"nice",1);
	list1.add_elem(book1);
	list1.add_elem(book2);
	linkedl::Node<books::Book>* temp = list1.head;
	while (temp != nullptr) {
		std::cout << temp->data.pub_date_key<<std::endl;
		temp = temp->next;
	}
	
	linkedl::List<books::Character> listch = linkedl::List<books::Character>();
	books::Character character1 = books::Character();
	character1.list_of_names->add_elem("Oleg");
	character1.list_of_names->add_elem("Oleg228");
	Pair<books::Book,int> pair1 = Pair<books::Book, int>(book1,1);
	Pair<books::Book, int> pair2 = Pair<books::Book, int>(book2, 2);
	character1.list_of_books->add_elem(pair1);
	character1.list_of_books->add_elem(pair2);
	listch.add_elem(character1);
	linkedl::List<linkedl::List<books::Book>*> series =	start_prog(listch);
	*/
		

	arrayl::ArrayList<books::Book> arrlist1 = arrayl::ArrayList<books::Book>();
	books::Book book1 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book2 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	arrlist1.add_elem(book1);
	arrlist1.add_elem(book2);
	for (int i = 0; i < arrlist1.index_end; i++) {
		std::cout << arrlist1.array[i].pub_date_key <<std::endl;
	}




}






