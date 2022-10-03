#include "BksCh.h"
#include "LinkedListImpl.h"
#include "Trees_impl.h"
#include "ArrayListImpl.h"


int main() {

}


void start_prog(linkedl::List<books::Character>* listofch){
	linkedl::List<linkedl::List<books::Book>>* series = new linkedl::List<linkedl::List<books::Book>>();
	while (true) {
		/*books::Character* temp = new books::Character();*/

		linkedl::Node<books::Character>* tempn = listofch->head;

		while (tempn != nullptr) {
			linkedl::Node<Map<books::Book, int>>* temp_map = tempn->data.list_of_books.head;// TO DO MAIN FUNC;
		}
	}
}