#pragma once
#include <iostream>
#include "LinkedListImpl.h"
#include "BksCh.h"
#include <vector>

template <typename T>
bool compare_books(T data1, T data2);

namespace trees {
	
	template <typename T>
	class Binary_Node {
	public:
		T data;
		Binary_Node* left;
		Binary_Node* right;
		Binary_Node* parent;
		
		Binary_Node() {
			this->data = NULL;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
		Binary_Node(T data) {
			this->data = data;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
	};

	template <typename T>
	class BinaryTree {
	public:

		Binary_Node<T>* root;


		virtual Binary_Node<T>* bnode_insert(Binary_Node<T>* node) {
			if (root == nullptr) {
				root = node;
				return node;
			}

			linkedl::Queue<Binary_Node<T>> queue = linkedl::Queue<Binary_Node<T>>;
			linkedl::Node<Binary_Node<T>>* temp = new linkedl::Node<Binary_Node<T>>(root);
			queue.add_elem(temp);

			while (queue.head != nullptr) {
				Binary_Node<T>* temp = queue.front();
				queue.pop_front();

				if (temp->left != nullptr)
					queue.add_elem(new linkedl::Node<Binary_Node<T>>(temp->left));
				else {
					temp->left = node;
					node->parent = temp;
					return root;
				}
				if (temp->right != nullptr)
					queue.add_elem(new linkedl::Node<Binary_Node<T>>(temp->right));
				else {
					temp->right = node;
					node->parent = temp;
					return root;
				}
			}
			delete queue;

		}

		Binary_Node<T>* bnode_search(T data) {
			if (root == nullptr) {
				return nullptr;
			}

			linkedl::Queue<Binary_Node<T>> queue = linkedl::Queue<Binary_Node<T>>;
			linkedl::Node<T>* temp = new linkedl::Node<T>(root);
			queue.add_elem(temp);

			while (queue.head!=nullptr) {
				Binary_Node<T>* temp = queue.front();
				queue.pop_front();

				if (temp->left->data == data)
					return temp->left;
				else
					queue.add_elem(new linkedl::Node<Binary_Node<T>>(temp->left));

				if (temp->right == data)
					return temp->right;
				else 
					queue.add_elem(new linkedl::Node<Binary_Node<T>>(temp->right));

				if (temp == nullptr)
					std::cout << "No such elem" << std::endl;
				
			}
			delete queue;
		}
		
		void bnode_delete(T data) {
			Binary_Node<T>* temp;
			Binary_Node<T>* temp2;
			temp = bnode_search(data);

			if (compare_books(temp->data, (temp->parent)->data))
				(temp->parent)->right = temp->right;

			else if (!compare_books(temp->data, (temp->parent)->data))
				(temp->parent)->left = temp->right;

			(temp->right)->parent = temp->parent;
			temp2 = (temp->right)->left;
			while (temp2 != nullptr)
				temp2 = temp2->left;
			(temp->left)->parent = temp2->parent;
			(temp2->parent)->left = temp->left;

			delete temp;

		}
	};
	template <typename T>
	class BinarySearchTree: public BinaryTree<T> {
	public:
		
		void bnode_insert(Binary_Node<T>* node, Binary_Node<T>* root) override {
			if (compare_books(node->data, root->data)) {
				bnode_insert(node,root->right);
			}
			else if (!compare_books(node->data, root->data)) {
				bnode_insert(node, root->left);
			}
			else if (root == nullptr) {
				root = node;
			}
			else {
				std::cout<< "Error" << std::endl;
			}
		}
	};

	template <typename T>
	class Arb_Binary_Node {
	public:
		T data;
		linkedl::List<Arb_Binary_Node<T>*> children = linkedl::List<Arb_Binary_Node<T>*>;

		Arb_Binary_Node() {

			this->data = NULL;
			children.head = nullptr;
			children.tail = nullptr;
		}
		Arb_Binary_Node(T data) {

			this->data = data;
			children.head = nullptr;
			children.tail = nullptr;
		}
	};


	template <typename T>
	class GeneralTree{
	public:

		Arb_Binary_Node<T>* root;

		void arbnode_insert(T data) {
			Arb_Binary_Node<T> noded = new Arb_Binary_Node<T>(data);
			linkedl::Node<Arb_Binary_Node<T>>* node_to_add = new linkedl::Node<Arb_Binary_Node<T>>(noded);
			(root->children->tail)->next = node_to_add;
			node_to_add->prev = root->children->tail;
			root->children->tail = node_to_add;
		}

		linkedl::Node<Arb_Binary_Node<T>>* arbnode_search(T data) {
			if (root == nullptr) {
				return nullptr;
			}

			Arb_Binary_Node<T>* noded = new Arb_Binary_Node<T>(data);

			linkedl::Queue<Arb_Binary_Node<T>> queue = linkedl::Queue<Arb_Binary_Node<T>>;
			linkedl::Node<Arb_Binary_Node<T>>* temp = new linkedl::Node<Arb_Binary_Node<T>>(root);
			queue.add_elem(temp);

			while (queue->head!=nullptr) {
				Arb_Binary_Node<T>* temp = queue.front();
				queue.pop_front();
				linkedl::Node<Arb_Binary_Node<T>>* check_node = temp->children->head;
				while (check_node != nullptr) {
					if (check_equality(check_node->data,noded)){
						return check_node;
					}
					else {
						queue.add_elem(new linkedl::Node<Arb_Binary_Node<T>>(check_node));
						check_node = check_node->next;
					}
				}
			}
			delete queue;
			std::cout << "No such element " << std::endl;
			return nullptr;
		}

		virtual void arbnode_delete(T data) {
			
			Arb_Binary_Node<T>* temp = arbnode_search(data);
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			delete temp;

		}

		bool check_equality(Arb_Binary_Node<T>* node_1, Arb_Binary_Node<T>* node_2) {
			if (node_1->data == node_2->data)
				return true;
			return false;
		}
	};


	template <typename T>
	class Arb_Binary_Node_Vector {
	public:
		T data;
		int index_end;
		std::vector<Arb_Binary_Node<T>*> children;

		Arb_Binary_Node_Vector() {
			this->data = NULL;
			this->index_end = 0;
		}
		Arb_Binary_Node_Vector(T data) {
			this->data = data;
			this->index_end = 0;
		}
	};


	template <typename T>
	class GeneralTreeVector {
	public:
		Arb_Binary_Node_Vector<T>* root;

		void arb_node_vec_insert(T data) {
			Arb_Binary_Node_Vector<T> node_to_add = new Arb_Binary_Node_Vector<T>(data);

			root->children[root->index_end] = node_to_add;
			root->index_end++;

		}
//.........................change later
		linkedl::Node<Arb_Binary_Node_Vector<T>>* arbnode_search(T data) {// change node type later(to do)
			if (root == nullptr) {
				return nullptr;
			}

			Arb_Binary_Node_Vector<T>* noded = new Arb_Binary_Node_Vector<T>(data);

			linkedl::Queue<Arb_Binary_Node_Vector<T>> queue = linkedl::Queue<Arb_Binary_Node_Vector<T>>;
			linkedl::Node<Arb_Binary_Node_Vector<T>>* temp = new linkedl::Node<Arb_Binary_Node_Vector<T>>(root);
			queue.add_elem(temp);

			while (queue->head != nullptr) {
				Arb_Binary_Node_Vector<T>* temp = queue.front();
				queue.pop_front();
				linkedl::Node<Arb_Binary_Node_Vector<T>>* check_node = temp->children->head;
				while (check_node != nullptr) {
					if (check_equality(check_node->data, noded)) {
						return check_node;
					}
					else {
						queue.add_elem(new linkedl::Node<Arb_Binary_Node_Vector<T>>(check_node));
						check_node = check_node->next;
					}
				}
			}
			delete queue;
			std::cout << "No such element " << std::endl;
			return nullptr;
		}

		virtual void arbnode_delete(T data) {

			Arb_Binary_Node<T>* temp = arbnode_search(data);
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			delete temp;

		}

		bool check_equality(Arb_Binary_Node<T>* node_1, Arb_Binary_Node<T>* node_2) {
			if (node_1->data == node_2->data)
				return true;
			return false;
		}
	};

	//change later
}