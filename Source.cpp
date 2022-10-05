#include "BksCh.h"
#include "LinkedListImpl.h"
#include "Trees_impl.h"
#include "ArrayListImpl.h"
//#include <iostream>

int main() {
	linkedl::List<books::Book> list1 = linkedl::List<books::Book>();
	books::Book book1 = books::Book("Abc","alex","12122003",20,"nice",1);
	books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	list1.add_elem(book1);
	list1.add_elem(book2);
	linkedl::Node<books::Book>* temp = list1.head;
	while (temp != nullptr) {
		std::cout << temp->data.pub_date_key<<std::endl;
		temp = temp->next;
	}
	delete& list1;
}


linkedl::List<linkedl::List<books::Book>>* start_prog(linkedl::List<books::Character>* listofch){
	linkedl::List<linkedl::List<books::Book>>* series = new linkedl::List<linkedl::List<books::Book>>();
	linkedl::Node<books::Character>* tempn = listofch->head;

	while (tempn!=nullptr) {
		/*books::Character* temp = new books::Character();*/	
		linkedl::Node<linkedl::List<books::Book>>* temp_node_series = new linkedl::Node<linkedl::List<books::Book>>();

		linkedl::Node<Pair<books::Book, int>>* temp_pair = tempn->data.list_of_books.head;

		while (temp_pair!=nullptr) {		
			if(temp_pair->data.value_2<2){
				linkedl::Node<books::Book>* newnode = new linkedl::Node<books::Book>(temp_pair->data.value_1);
				temp_node_series->data.add_elem(newnode->data);
			}
		}
		temp_node_series->data.quick_sort(temp_node_series->data.head,temp_node_series->data.tail);
		series->add_elem(temp_node_series->data);
		tempn = tempn->next;
	}

	return series;
}




