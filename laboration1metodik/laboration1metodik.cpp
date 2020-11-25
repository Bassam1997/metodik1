// laboration1metodik.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include "int_sorted.h"
#include "int_buffer.h"
#include <utility> 

using namespace std;

void f(int_buffer buf);
int_sorted sort(const int* begin, const int* end);


int main(int argc, const char* argv[])
{
    //f(int_buffer (10));
   
   /* int_buffer a(3);
    int_buffer b(2);
    a[0] = 1;
    a[1] = 2;
    a[2] = 5;
    b[0] = 3;
    b[1] = 4;
    int_sorted a_sorted(a.begin(), a.size());
    int_sorted b_sorted(b.begin(), b.size());
    int_sorted c = a_sorted.merge(b_sorted);

    for (auto i : c) {
        cout << i << endl;
        }
   */
    int array[]{ 30, 50, 20, 10, 40 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        int smallestIndex{ startIndex };

        // Then look for a smaller element in the rest of the array
        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
                // then keep track of it
                smallestIndex = currentIndex;
        }

        // smallestIndex is now the smallest element in the remaining array
                // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(array[startIndex], array[smallestIndex]);
    }

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0; 
}

void f(int_buffer buf)
{
    int r = 1;
    for (int* i = buf.begin(); i != buf.end(); i++)
    {
        *i = r;
        r++;
    }
    const int_buffer& buf1 = buf;
    for (const int* i = buf1.begin(); i != buf1.end(); i++)
        {
            cout << *i << endl;
        }
    /*
    for(auto& e : buf) {
        e = r;
        cout << e << endl;
        r++;
    */
}

int_sorted sort(const int* begin, const int* end) {
    if (begin == end) return
        int_sorted(nullptr, 0);
    if (begin == end - 1) return
        int_sorted(begin, 1);
    ptrdiff_t half = (end - begin) / 2; //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}