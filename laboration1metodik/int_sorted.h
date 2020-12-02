#include "int_buffer.h"
#include <algorithm>
#include <iostream>

using namespace std; 

class int_sorted {
public:
	int_sorted(const int* source, size_t size);
	size_t size() const;
	int* insert(int value); // returns the insertion point .
		const int* begin() const;
		const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;

private:
	int_buffer buf;
	
};