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

};
