#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "BksCh.h"
#include "ArrayListimpl.h"
#include "doctest.h"
#include "LinkedListImpl.h"
#include "PairStruct.h"
#include "Trees_impl.h"
#include "VectorListimpl.h"
#include <iostream>



TEST_CASE("linked list impl ") {

	linkedl::DeQue<books::Book> list;

	books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
	books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
	books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

	REQUIRE(list.head == nullptr);
	REQUIRE(list.tail == nullptr);


	SUBCASE("adding element") {
		list.add_elem(book1);

		CHECK(list.head->next == nullptr);
		CHECK(list.head->next == nullptr);
		CHECK(list.head->data.id == book1.id);

	}

	SUBCASE("push elem") {
		list.push_elem(book1);
		list.push_elem(book2);

		CHECK(list.head->data.id == book2.id);
	}

	SUBCASE("search elem in empty list") {
		linkedl::Node<books::Book>* result = list.search_elem(book2);

		CHECK(result == nullptr);
	}

	SUBCASE("search elem which doesn`t exist") {
		list.add_elem(book1);
		linkedl::Node<books::Book>* result = list.search_elem(book2);

		CHECK(result == nullptr);
	}

	SUBCASE("search elem which exists") {
		list.add_elem(book1);
		linkedl::Node<books::Book>* result = list.search_elem(book1);

		CHECK(result->data.id == book1.id);
	}

	SUBCASE("delete elem from empty list") {
		list.delete_elem(book2);
		CHECK(list.head == nullptr);
	}


	SUBCASE("delete elem which doesn`t exist") {
		list.add_elem(book1);
		list.delete_elem(book2);

		CHECK(list.head != nullptr);
	}

	SUBCASE("delete elem which exists ") {
		list.add_elem(book1);
		list.delete_elem(book1);

		CHECK(list.head == nullptr);
	}

	SUBCASE("pop functions") {
		list.add_elem(book1);
		list.add_elem(book2);

		books::Book result = list.end();
		CHECK(result.id == book2.id);

		result = list.front();
		CHECK(result.id == book1.id);

		list.pop_end();
		list.pop_front();

		CHECK(list.head == nullptr);
		CHECK(list.tail == nullptr);
	}

	SUBCASE("sorting empty list") {
		SUBCASE("quick sort") {
			list.quickSort();
		}
		SUBCASE("merge sort") {
			list.start_merge_sort(list.head);
		}
		SUBCASE("insertion sort") {
			list.insertionSort(list.head);
		}
		CHECK(list.head == nullptr);
		CHECK(list.tail == nullptr);
	}

	SUBCASE("sorting list with 1 elem") {
		list.add_elem(book1);
		SUBCASE("quick sort") {
			list.quickSort();
		}
		SUBCASE("merge sort") {
			list.start_merge_sort(list.head);
		}
		SUBCASE("insertion sort") {
			list.insertionSort(list.head);
		}
		CHECK(list.head->data.id == book1.id);
	}
	SUBCASE("sorting list with multiple elems") {
		list.add_elem(book1);
		list.add_elem(book2);
		list.add_elem(book3);
		SUBCASE("quick sort") {
			list.quickSort();
		}

		SUBCASE("merge sort") {
			list.head = list.start_merge_sort(list.head);
		}

		SUBCASE("insertion sort") {
			list.insertionSort(list.head);
		}
		CHECK(list.head->data.id == book3.id);
		CHECK(list.tail->data.id == book1.id);
	}

	SUBCASE("series function") {
		linkedl::List<linkedl::List<books::Book>*> series = linkedl::List<linkedl::List<books::Book>*>();
		linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>> listch =
			linkedl::List<books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>>();
		books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>> character1 =
			books::Character<linkedl::List<std::string>, linkedl::List<Pair<books::Book, int>>>();
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
		series = start_prog_linkedl(listch);
	}
	
};

TEST_CASE("array list impl"){

		arrayl::DeQue<books::Book> list;

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

		SUBCASE("adding element") {
			list.add_elem(book1);

			CHECK(list.array[0].id == book1.id);
		}

		SUBCASE("push elem") {
			list.add_front(book1);
			list.add_front(book2);
			CHECK(list.array[0].id == book2.id);
		}

		SUBCASE("search elem in empty list") {
			int elem_index = list.search_elem_index(book2);

			CHECK(elem_index == -1);
		}

		SUBCASE("search elem which doesn`t exist") {
			list.add_elem(book1);
			int elem_index = list.search_elem_index(book2);

			CHECK(elem_index == -1);
		}

		SUBCASE("search elem which exists") {
			list.add_elem(book1);
			int elem_index = list.search_elem_index(book1);

			CHECK(elem_index == 0);
		}

		SUBCASE("pop functions") {
			list.add_elem(book1);
			list.add_elem(book2);

			books::Book result = list.back_elem();
			CHECK(result.id == book2.id);

			result = list.front_elem();
			CHECK(result.id == book1.id);

			list.pop_back();
			list.pop_front();

			CHECK(list.index_end==0);
		}

		SUBCASE("sorting empty list") {
			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);

			}
			SUBCASE("insertion sort") {
				list.insertionSort();

			}
		}

		SUBCASE("sorting list with 1 elem") {

			list.add_elem(book1);

			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("insertion sort") {
				list.insertionSort();
			}
			CHECK(list.array[0].id == book1.id);
		}

		SUBCASE("sorting list with multiple elem") {

			list.add_elem(book1);
			list.add_elem(book2);
			list.add_elem(book3);

			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);

			}
			SUBCASE("insertion sort") {
				list.insertionSort();
			}
			CHECK(list.array[0].id == book3.id);
			CHECK(list.array[list.index_end - 1].id == book1.id);
		}
		SUBCASE("series function") {
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
		}
	}

	TEST_CASE("vector list impl") {

		vectorl::DeQue<books::Book> list;

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

		SUBCASE("adding element") {
			list.add_elem(book1);

			CHECK(list.array[0].id == book1.id);
		}

		SUBCASE("push elem") {
			list.add_front(book1);
			list.add_front(book2);
			CHECK(list.array[0].id == book2.id);
		}

		SUBCASE("search elem in empty list") {
			int elem_index = list.search_elem_index(book2);

			CHECK(elem_index == -1);
		}

		SUBCASE("search elem which doesn`t exist") {
			list.add_elem(book1);
			int elem_index = list.search_elem_index(book2);

			CHECK(elem_index == -1);
		}

		SUBCASE("search elem which exists") {
			list.add_elem(book1);
			int elem_index = list.search_elem_index(book1);

			CHECK(elem_index == 0);
		}

		SUBCASE("pop functions") {
			list.add_elem(book1);
			list.add_elem(book2);

			books::Book result = list.back_elem();
			CHECK(result.id == book2.id);

			result = list.front_elem();
			CHECK(result.id == book1.id);

			list.popBack();
			list.pop_front();

			CHECK(list.index_end == 0);
		}

		SUBCASE("sorting empty list") {
			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);

			}
			SUBCASE("insertion sort") {
				list.insertionSort();

			}
		}

		SUBCASE("sorting list with 1 elem") {
			list.add_elem(book1);

			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("insertion sort") {
				list.insertionSort();
			}
			CHECK(list.array[0].id == book1.id);
		}


		SUBCASE("sorting list with multiple elems") {
			list.add_elem(book1);
			list.add_elem(book2);
			list.add_elem(book3);
			SUBCASE("quick sort") {
				list.quickSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("merge sort") {
				list.mergeSort(list.array, 0, list.index_end - 1);
			}
			SUBCASE("insertion sort") {
				list.insertionSort();
			}
			CHECK(list.array[0].id == book3.id);
			CHECK(list.array[list.index_end - 1].id == book1.id);
		}

		SUBCASE("series func") {
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
		}

	}
	TEST_CASE("Binary Tree") {

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

		trees::BinaryTree<books::Book> tree = trees::BinaryTree<books::Book>();
		trees::Binary_Node<books::Book>* temp = new trees::Binary_Node<books::Book>();

		SUBCASE("add elem to our tree") {

			tree.bnode_insert(book1);
			tree.bnode_insert(book2);
			tree.bnode_insert(book3);

			tree.treeout(tree.root);

		}

		SUBCASE("search elem in an empty tree ") {

			temp = tree.bnode_search(book1);
			CHECK(temp==nullptr);
		}

		SUBCASE("search elem which doesn`t exist") {
			tree.bnode_insert(book1);
			temp = tree.bnode_search(book2);

			CHECK(temp == nullptr);
		}

		SUBCASE("search an elem which exists") {
			tree.bnode_insert(book1);
			temp = tree.bnode_search(book1);

			CHECK(temp->data.id == book1.id);
		}

		SUBCASE("delete elem which doesn`t exist") {
			tree.bnode_insert(book1);
			tree.bnode_delete(book2);

			CHECK(tree.root->data.id==book1.id);
		}

		SUBCASE("delete elem which exists") {
			tree.bnode_insert(book1);
			tree.bnode_delete(book1);

			CHECK(tree.root == nullptr);
		}

	}

	TEST_CASE("Binary Search Tree") {

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);
		trees::Binary_Node<books::Book>* to_insert1 = new trees::Binary_Node<books::Book>(book1);
		trees::Binary_Node<books::Book>* to_insert2 = new trees::Binary_Node<books::Book>(book2);
		trees::Binary_Node<books::Book>* to_insert3 = new trees::Binary_Node<books::Book>(book3);

		trees::BinarySearchTree<books::Book> tree = trees::BinarySearchTree<books::Book>();
		trees::Binary_Node<books::Book>* temp = new trees::Binary_Node<books::Book>();

		SUBCASE("add elem to our tree") {
			
			tree.bnode_insert(to_insert1,tree.root);
			tree.bnode_insert(to_insert2,tree.root);
			tree.bnode_insert(to_insert3,tree.root);

			tree.treeout(tree.root);

		}

		SUBCASE("search elem in an empty tree ") {

			temp = tree.bnode_search(book1);
			CHECK(temp == nullptr);
		}

		SUBCASE("search elem which doesn`t exist") {
			tree.bnode_insert(to_insert1, tree.root);
			temp = tree.bnode_search(book2);

			CHECK(temp == nullptr);
		}

		SUBCASE("search an elem which exists") {
			tree.bnode_insert(to_insert1, tree.root);
			temp = tree.bnode_search(book1);

			CHECK(temp->data.id == book1.id);
		}

		SUBCASE("delete elem which doesn`t exist") {
			tree.bnode_insert(to_insert1, tree.root);
			tree.bnode_delete(book2);

			CHECK(tree.root->data.id == book1.id);
		}

		SUBCASE("delete elem which exists") {
			tree.bnode_insert(to_insert1, tree.root);
			tree.bnode_delete(book1);

			CHECK(tree.root == nullptr);
		}

	}

	TEST_CASE("General Tree") {

		trees::GeneralTree<books::Book> tree = trees::GeneralTree<books::Book>();

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

		trees::Arb_Node<books::Book>* to_insert1 = new trees::Arb_Node<books::Book>(book1);
		trees::Arb_Node<books::Book>* to_insert2 = new trees::Arb_Node<books::Book>(book2);
		trees::Arb_Node<books::Book>* to_insert3 = new trees::Arb_Node<books::Book>(book3);

		
		trees::Arb_Node<books::Book>* temp = new trees::Arb_Node<books::Book>();

		SUBCASE("add elem to our tree") {

			tree.arbnode_insert(book1);
			tree.arbnode_insert(book2);
			tree.arbnode_insert(book3);

		}

		SUBCASE("search elem in an empty tree ") {

			temp = tree.arbnode_search(book1);
			CHECK(temp == nullptr);
		}

		SUBCASE("search elem which doesn`t exist") {
			tree.arbnode_insert(book1);
			temp = tree.arbnode_search(book2);

			CHECK(temp == nullptr);
		}

		SUBCASE("search an elem which exists") {
			tree.arbnode_insert(book1);
			temp = tree.arbnode_search(book1);

			CHECK(temp->data.id == book1.id);
		}

		SUBCASE("delete elem which doesn`t exist") {
			tree.arbnode_insert(book1);
			tree.arbnode_delete(book2);

			CHECK(tree.root->data.id == book1.id);
		}

		SUBCASE("delete elem which exists") {
			tree.arbnode_insert(book1);
			tree.arbnode_delete(book1);

			CHECK(tree.root == nullptr);
		}

	}

	TEST_CASE("General Tree Vector") {

		trees::GeneralTreeVector<books::Book> tree = trees::GeneralTreeVector<books::Book>();

		books::Book book2 = books::Book("Abc11", "ale1x", "12122004", 20, "nice", 2);
		books::Book book3 = books::Book("Abc", "alex", "12122003", 20, "nice", 1);
		books::Book book1 = books::Book("Abc12", "alexvika", "12122005", 20, "nice", 3);

		trees::Arb_Node_Vector<books::Book>* to_insert1 = new trees::Arb_Node_Vector<books::Book>(book1);
		trees::Arb_Node_Vector<books::Book>* to_insert2 = new trees::Arb_Node_Vector<books::Book>(book2);
		trees::Arb_Node_Vector<books::Book>* to_insert3 = new trees::Arb_Node_Vector<books::Book>(book3);


		trees::Arb_Node_Vector<books::Book>* temp = new trees::Arb_Node_Vector<books::Book>();

		SUBCASE("add elem to our tree") {

			tree.arb_node_vec_insert(book1);
			tree.arb_node_vec_insert(book2);
			tree.arb_node_vec_insert(book3);

		}

		SUBCASE("search elem in an empty tree ") {

			temp = tree.arbnode_search(book1);
			CHECK(temp == nullptr);
		}

		SUBCASE("search elem which doesn`t exist") {
			tree.arb_node_vec_insert(book1);
			temp = tree.arbnode_search(book2);

			CHECK(temp == nullptr);
		}

		SUBCASE("search an elem which exists") {
			tree.arb_node_vec_insert(book1);
			temp = tree.arbnode_search(book1);

			CHECK(temp->data.id == book1.id);
		}

		SUBCASE("delete elem which doesn`t exist") {
			tree.arb_node_vec_insert(book1);
			tree.arbnode_delete(book2);

			CHECK(tree.root->data.id == book1.id);
		}

		SUBCASE("delete elem which exists") {
			tree.arb_node_vec_insert(book1);
			tree.arbnode_delete(book1);

			CHECK(tree.root == nullptr);
		}

	}