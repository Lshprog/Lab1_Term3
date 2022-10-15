#pragma once
#include <iostream>
#include "LinkedListImpl.h"
#include "VectorListImpl.h"
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

		BinaryTree() {
			root = nullptr;
		}

		virtual Binary_Node<T>* bnode_insert(T data) {
			Binary_Node<T>* node = new Binary_Node<T>(data);
			if (root == nullptr) {
				root = node;
				return node;
			}

			linkedl::Queue<Binary_Node<T>*> queue = linkedl::Queue<Binary_Node<T>*>();
			linkedl::Node<Binary_Node<T>*>* tempn = new linkedl::Node<Binary_Node<T>*>(root);
			queue.add_elem(tempn->data);

			while (queue.head != nullptr) {
				Binary_Node<T>* temp = queue.front();
				queue.pop_front();

				if (temp->left != nullptr)
					queue.add_elem(temp->left);
				else {
					temp->left = node;
					node->parent = temp;
					return root;
				}
				if (temp->right != nullptr)
					queue.add_elem(temp->right);
				else {
					temp->right = node;
					node->parent = temp;
					return root;
				}
			}

		}

		Binary_Node<T>* bnode_search(T data) {
			if (root == nullptr) {
				return nullptr;
			}

			linkedl::Queue<Binary_Node<T>*> queue = linkedl::Queue<Binary_Node<T>*>();
			linkedl::Node<Binary_Node<T>*>* tempn = new linkedl::Node<Binary_Node<T>*>(root);
			queue.add_elem(tempn->data);

			while (queue.head != nullptr) {
				Binary_Node<T>* temp = queue.front();
				queue.pop_front();

				if (temp != nullptr) {
					if (temp->data.id == data.id)
						return temp;
					else {
						if (temp->left != nullptr) {
							if (temp->left->data.id == data.id)
								return temp->left;
							else
								queue.add_elem(temp->left);
						}

						if (temp->right != nullptr) {
							if (temp->right->data.id == data.id)
								return temp->right;
							else
								queue.add_elem(temp->right);
						}
					}
				}
			}
			std::cout << "No such elem" << std::endl;
			return nullptr;
		}

		void bnode_delete(T data) {
			Binary_Node<T>* temp;
			Binary_Node<T>* temp2;
			temp = bnode_search(data);
			if (temp == nullptr)
				return;
			if (check_equality(this->root, temp)) {
				delete this->root;
				this->root = nullptr;
				return;
			}
			if (temp->data.id == this->root->data.id) {
				if (temp->right != nullptr) {
					this->root = temp->right;
					temp->right->parent = nullptr;
				}
				else if (temp->left != nullptr) {
					this->root = temp->left;
					temp->left->parent = nullptr;
					return;
				}
				else {
					std::cout << "empty tree " << std::endl;
					return;
				}
			}

			else if (compare_books_no_equality(temp->data, (temp->parent)->data)) {
				(temp->parent)->right = temp->right;
				(temp->right)->parent = temp->parent;
			}

			else if (!compare_books_no_equality(temp->data, (temp->parent)->data)) {
				(temp->parent)->left = temp->right;
				(temp->right)->parent = temp->parent;
			}


			temp2 = (temp->right)->left;
			if (temp2 != nullptr) {
				while (temp2->left != nullptr)
					temp2 = temp2->left;
				(temp->left)->parent = temp2;
				temp2->left = temp->left;
			}
			else {
				(temp->left)->parent = temp->right;
				(temp->right)->left = temp->left;
			}


			delete temp;

		}

		void treeout(Binary_Node<T>* root) {
			if (root == nullptr)
				return;
			treeout(root->left);
			std::cout << root->data.pub_date_key << std::endl;
			treeout(root->right);
		}
	};
	template <typename T>
	class BinarySearchTree : public BinaryTree<T> {
	public:

		void bnode_insert(Binary_Node<T>* node, Binary_Node<T>* root) {
			if (this->root == nullptr) {
				this->root = node;
				return;
			}

			if (compare_books(node->data, root->data)) {
				if (root->right == nullptr) {
					root->right = node;
					node->parent = root;
				}
				else
					bnode_insert(node, root->right);
			}
			else if (!compare_books(node->data, root->data)) {
				if (root->left == nullptr) {
					root->left = node;
					node->parent = root;
				}
				else
					bnode_insert(node, root->left);
			}
			else {
				std::cout << "Error" << std::endl;
			}
		}
	};

	template <typename T>
	class Arb_Node {
	public:
		T data;
		Arb_Node<T>* parent;
		linkedl::List<Arb_Node<T>*> children = linkedl::List<Arb_Node<T>*>();

		Arb_Node() {
			this->parent = nullptr;
		}
		Arb_Node(T data) {
			this->parent = nullptr;
			this->data = data;
			
		}
		~Arb_Node() {
			
			linkedl::Node<Arb_Node<T>*>* temp = this->children.head;
			while (temp!=nullptr ) {
				delete temp->data;
				temp = temp->next;
			}
		}
	};


	template <typename T>
	class GeneralTree {
	public:

		Arb_Node<T>* root;

		GeneralTree() {
			root = nullptr;
		}

		~GeneralTree() {
			delete root;
		}
		
		void arbnode_insert(T data) {
			Arb_Node<T>* noded = new Arb_Node<T>(data);
			if (this->root == nullptr) {
				root = noded;
				return;
			}
			root->children.add_elem(noded);
			noded->parent = this->root;
		}

		Arb_Node<T>* arbnode_search(T data) {
			if (root == nullptr) {
				return nullptr;
			}
			
			Arb_Node<T>* noded = new Arb_Node<T>(data);

			if (check_equality(root, noded)) {
				return root;
			}

			linkedl::Queue<Arb_Node<T>*> queue = linkedl::Queue<Arb_Node<T>*>();
			queue.add_elem(this->root);

			while (queue.head != nullptr) {
				Arb_Node<T>* temp = queue.front();
				queue.pop_front();
				linkedl::Node<Arb_Node<T>*>* check_node = temp->children.head;
				while (check_node != nullptr) {
					if (check_equality(check_node->data, noded)) {
						return check_node->data;
					}
					else {
						queue.add_elem(check_node->data);
						check_node = check_node->next;
					}
				}
			}

			std::cout << "No such element " << std::endl;
			return nullptr;
		}

		virtual void arbnode_delete(T data) {

			Arb_Node<T>* temp = arbnode_search(data);
			if (temp == nullptr)
				return;
			if (check_equality(this->root, temp)) {
				delete this->root;
				this->root = nullptr;
				return;
			}
			if (temp->children.head == nullptr) {
				temp->parent->children.delete_elem(temp);
			}
			else {
				if (temp->data.id == temp->parent->children.head->data->data.id) {

					temp->children.tail->next = temp->parent->children.head->next;
					if (temp->parent->children.head->next != nullptr)
						temp->parent->children.head->next->prev = temp->children.tail;
					temp->parent->children.head = temp->children.head;

				}
				else if (temp->data.id == temp->parent->children.tail->data->data.id)
				{
					temp->children.head->prev = temp->parent->children.tail->prev;
					if (temp->parent->children.tail->prev != nullptr)
						temp->parent->children.tail->prev->next = temp->children.head;
					temp->parent->children.tail = temp->children.tail;

				}
				else {
					linkedl::Node<Arb_Node<T>*>* temp1 = temp->parent->children.head;
					while (temp1 != nullptr) {
						if (temp1->data->data.id == temp->data.id) {
							temp1->prev->next = temp->children.head;
							temp->children.head->prev = temp1->prev;
							temp1->next->prev = temp->children.tail;
							temp->children.tail->next = temp1->next;

						}
					}
				}
				linkedl::Node<Arb_Node<T>*>* tempp = temp->children.head;
				while (tempp != temp->children.tail)
					tempp->data->parent = temp->parent;
				tempp->data->parent = temp->parent;
			}

			delete temp;
		}

		bool check_equality(Arb_Node<T>* node_1, Arb_Node<T>* node_2) {
			if (node_1->data.id == node_2->data.id)
				return true;
			return false;
		}

	};


	template <typename T>
	class Arb_Node_Vector {
	public:
		T data;
		int index_end;
		Arb_Node_Vector<T>* parent;
		std::vector<Arb_Node_Vector<T>*> children;

		Arb_Node_Vector() {
			this->index_end = 0;
		}
		Arb_Node_Vector(T data) {
			this->data = data;
			this->index_end = 0;
		}
		~Arb_Node_Vector() {
			if(this->children.size()!=0)
				this->children.clear();
		}
	};


	template <typename T>
	class GeneralTreeVector {
	public:
		Arb_Node_Vector<T>* root;

		~GeneralTreeVector() {
			delete root;
		}

		void arb_node_vec_insert(T data) {
			Arb_Node_Vector<T>* node_to_add = new Arb_Node_Vector<T>(data);
			if (this->root == nullptr) {
				this->root = node_to_add;
				return;
			}
			this->root->children.push_back(node_to_add);
			node_to_add->parent = this->root;
			this->root->index_end++;

		}

		Arb_Node_Vector<T>* arbnode_search(T data) {
			if (root == nullptr) {
				return nullptr;
			}

			Arb_Node_Vector<T>* noded = new Arb_Node_Vector<T>(data);

			if (check_equality(root, noded)) 
				return root;
			
			vectorl::Queue<Arb_Node_Vector<T>*> queue = vectorl::Queue<Arb_Node_Vector<T>*>();
			queue.add_elem(this->root);

			while (queue.index_end>0) {
				Arb_Node_Vector<T>* temp = queue.front_elem();
				queue.pop_front();
				if (temp->children.size() != 0) {
					Arb_Node_Vector<T>* check_node = temp->children[0];
					int i = 0;
					while (i < temp->index_end) {
						if (check_equality(check_node, noded)) {
							return check_node;
						}
						else {
							queue.add_elem(check_node);
							i++;
						}
					}
				}
			}
			std::cout << "No such element " << std::endl;
			return nullptr;
		}

		virtual void arbnode_delete(T data) {

			Arb_Node_Vector<T>* temp = arbnode_search(data);

			if (temp == nullptr) {
				return;
			}

			if (check_equality(this->root, temp)) {
				delete this->root;
				this->root = nullptr;
				return;
			}

			Arb_Node_Vector<T>* temp2 = temp->parent;
			int i = 0;
			while (i < temp2->children.size()) {
				if (check_equality(temp2->children[i], temp)) {
					temp2->children.erase(temp2->children.begin() + i);
					break;
				}
				i++;
			}
			
			delete temp;
		}

		bool check_equality(Arb_Node_Vector<T>* node_1, Arb_Node_Vector<T>* node_2) {
			if (node_1->data.id == node_2->data.id)
				return true;
			return false;
		}
	};
}

	
