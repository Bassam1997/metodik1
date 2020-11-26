// laboration1metodik.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include "int_sorted.h"
#include "int_buffer.h"
#include <utility> 
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

//void f(int_buffer buf);
//int_sorted sortis(const int* begin, const int* end);
//void selectionSort(int* begin, int* end);



/* Function to print an array */
/*void printArray(int_sorted a)
{
    for (const int* j = a.begin(); j < a.end(); j++)
        cout << *j << " ";
    cout << endl;
} */



int main(int argc, const char* argv[])
{
   
    /*auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    //  Insert the code that will be timed
    */
    
    /*
    std::cout << "Choose sortingalgorithm:" << std::endl;
    std::cout << "1. SelectionSort" << std::endl;
    std::cout << "2. Sortis" << std::endl;
    std::cout << "3. Sort" << std::endl;
    
    int val;
    std::cin >> val;
    const int husow = 400000;
    int_buffer buf(husow);
    for (int indek = 0; indek < husow; indek++) { //buffer med alla randomtal
        buf [indek] = (rand() % 20) + 1;
       //cout << buf[indek] << endl;
       
    }
    
    
    
    if (val == 1) {
        auto start = chrono::steady_clock::now();
        selectionSort(buf.begin(), buf.end());
      // test 1 selec sort: 137918 ms
      //test 2 selec sort: 137939 ms
       //test 3 selec sort: 137912 ms
        auto end = chrono::steady_clock::now();

        // Store the time difference between start and end
        auto diff = end - start;
        cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }
    if (val == 2) {
        auto start = chrono::steady_clock::now();
        sortis(buf.begin(), buf.end());
        // test 1 sortis: 1041.56 ms
        //test 2 sortis: 1033.91 ms
        //test 3 sortis: 1032.96 ms   
        auto end = chrono::steady_clock::now();
        /*for (auto a : sortis(buf.begin(), buf.end()))
        {
            cout << a << endl;
        }*/
        // Store the time difference between start and end
        /*auto diff = end - start;
        cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }
    if (val == 3) {
        auto start = chrono::steady_clock::now();
    sort(buf.begin(), buf.end()); //sort är en sorteringsalgorithm som finns i algortihm biblioteket
        // test 1 sort: 136.618 ms
        //test 2 sort: 136.604 ms
        //test 3 sort: 136.587 ms
    
    auto end = chrono::steady_clock::now();

    // Sparar tidsskillnaden mellan start och slut 
    auto diff = end - start;
    cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }

   
   
        */

   
    
    
   //f(int_buffer (10));
   
    int_buffer a(3);
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
    

    return 0; 
}


/*
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
    
} 
*/

/*
int_sorted sortis(const int* begin, const int* end) {
    if (begin == end) return
        int_sorted(nullptr, 0);
    if (begin == end - 1) return
        int_sorted(begin, 1);
    ptrdiff_t half = (end - begin) / 2; //pointer diff type
    const int* mid = begin + half;
    return sortis(begin, mid).merge(sortis(mid, end));
}

void selectionSort(int* begin, int* end)
{
    
    // One by one move boundary of unsorted subarray  
    for (int* i = begin; i != end; i++)
    {
        // Find the minimum element in unsorted array  
        int* min_idx = i;
        for (int* j = i + 1; j != end; j++) {
            if (*j < *min_idx) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Swap the found minimum element with the first element  
            swap(*min_idx, *i);
        }
    }
}
*/
