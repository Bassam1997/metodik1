#include "int_buffer.h"
#include <algorithm>
#include <iostream>

using namespace std; 

class int_sorted {
public:
	static const int MIN_CAPACITY = 16;
	int_sorted();
	int_sorted(const int* source, size_t size);
	size_t size() const;
	size_t capacity() const;
	int* insert(int value); // returns the insertion point .
		const int* begin() const;
		const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;

private:
	int_buffer buf;
	size_t st;
};