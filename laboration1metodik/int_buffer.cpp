#include "int_buffer.h"
#include <algorithm>
#include <iostream>

int_buffer::int_buffer(size_t size) : buffer_beg(new int[size]), buffer_end(buffer_beg + size)
{

}

int_buffer::int_buffer(const int* source, size_t size) : buffer_beg(new int[size]), buffer_end(buffer_beg + size)
{
    std::copy(source, source + size, begin());
}

int_buffer::int_buffer(const int_buffer& rhs) : buffer_beg(new int[rhs.size()]), buffer_end(buffer_beg + rhs.size()) // vår copy konstrukt
{
    std::copy(rhs.begin(), rhs.end(), begin());
}

int_buffer::int_buffer(int_buffer&& rhs) : buffer_beg(rhs.begin()), buffer_end(rhs.end()) //move construct
{
    rhs.buffer_beg = nullptr;
    rhs.buffer_end = nullptr;
}

int_buffer& int_buffer::operator=(const int_buffer& rhs) // copy assign
{
    int_buffer tmp(rhs);
    tmp.swap(*this);
    return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs)  //move assign
{
    rhs.swap(*this);
    return *this;
}

int& int_buffer::operator[](size_t index)
{
    return buffer_beg[index];
}

const int& int_buffer::operator[](size_t index) const
{
    return buffer_end[index];
}

size_t int_buffer::size() const
{
    return buffer_end - buffer_beg;
}

int* int_buffer::begin()
{
    return buffer_beg;
}

int* int_buffer::end()
{
    return buffer_end;
}

const int* int_buffer::begin() const
{
    return buffer_beg;
}

const int* int_buffer::end() const
{
    return buffer_end;
}


void int_buffer::swap(int_buffer& rhs) throw()
{
    std::swap(buffer_beg, rhs.buffer_beg);
    std::swap(buffer_end, rhs.buffer_end);
}

int_buffer::~int_buffer()
{
    delete[] buffer_beg;
}
