#include "int_sorted.h"
#include "int_buffer.h"
#include <iostream>
#include <algorithm>

using namespace std;


int_sorted::int_sorted():buf(MIN_CAPACITY), size(0) {

}

int_sorted::int_sorted(const int* source, size_t size) : buf(source, size)
{
}


size_t int_sorted::size() const
{
	return buf.size();
}

size_t int_sorted::capacity() const
{
	return buf.size();
}

/*
int* int_sorted::insert(int value)
{
	if (st == capacity()) {
		int new_size = st * 2;
		int_buffer buff(new_size);
		copy(buf.begin(), buf.end(), buf.begin());
		buf = buff;
	}
	buf[st++] = value;

	return nullptr;
	
}
*/
const int* int_sorted::begin() const
{
	return buf.begin();
}

const int* int_sorted::end() const
{
	return buf.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	int_buffer output(size() + merge_with.size());
	const int* a = begin();
	const int* b = merge_with.begin();
	int* c = output.begin();

	while (a != end() && b != merge_with.end()) {
		if (*a < *b) {
			*c = *a;
			a++;
		}
		else {
			*c = *b;
			b++;
		}
		c++;
	}
	while (a != end()) {
		*c = *a;
		c++;
		a++;
	}
	while (b != merge_with.end()) {
		*c = *b;
		b++;
		c++;
	}
	int_sorted sorted(nullptr, 0);
	sorted.buf = std::move(output);
	return sorted;

}
