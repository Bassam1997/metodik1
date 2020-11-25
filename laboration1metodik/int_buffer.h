#pragma once
#include <cstdlib>

class int_buffer
{
public:	
	explicit int_buffer(size_t size); 
	int_buffer(const int* source, size_t h);
	int_buffer(const int_buffer& rhs);
	int_buffer(int_buffer&& rhs);
	int_buffer& operator =(const int_buffer& rhs);
	int_buffer& operator =(int_buffer&& rhs) ;
	int& operator [](size_t index);
	const int& operator [](size_t index) const;
	size_t size() const;
	int* begin();
	int* end();
	const int* begin() const;
	const int* end() const;
	~int_buffer();
	void swap(int_buffer&)throw();

private:
	int* buffer_beg;
	int* buffer_end;

};

