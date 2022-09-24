#pragma once
template <typename A, typename B>class Map {
public:
	class KeyVal {
		A key;
		B val;
	};
	KeyVal* tail = nullptr;
	KeyVal* head = nullptr;

	inline void addtomap(A key, B val)
	{
		KeyVal* node = new KeyVal(key, val);
		if (head == nullptr && tail == nullptr) {
			tail = node;
			head = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}

	inline B get_val(A key)
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
	}
};
