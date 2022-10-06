#pragma once
template <typename A, typename B>class Pair {
public:
	A value_1;
	B value_2;

	Pair() {
		
	}


	Pair(A value_1, B value_2) {
		this->value_1 = value_1;
		this->value_2 = value_2;
	}

	/*inline B get_val_1(A key)
	{
		KeyVal* temp = head;
		while (true) {
			if (temp->key == key)
				return temp->val;
			if (temp->next == nullptr) {
				std::cout << "Error";
				return 0;
			}
			temp = temp->next;
		}
	}

	inline A get_key(B val)
	{
		KeyVal* temp = head;
		while (true) {
			if (temp->val == val)
				return temp->key;
			if (temp->next == nullptr) {
				std::cout << "Error";
				return 0;
			}
			temp = temp->next;
		}
	}*/
};
