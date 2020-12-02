#include "int_sorted.h"
#include "int_buffer.h"
#include <iostream>
#include <algorithm>

using namespace std;


int_sorted::int_sorted(const int* source, size_t size) : buf(source, size)
{

}


size_t int_sorted::size() const
{
	return buf.size();
}


int* int_sorted::insert(int value)
{
	int_buffer sorting(buf.size() + 1); //st�rre buffer +1
	std::merge(buf.begin(), buf.end(), &value, &value + 1, sorting.begin()); //Mergea v�r nuvarande buffer med value. Flyttar v�r merge till sorting.begin och d�refter till buffern
	buf = move(sorting); //flytta in allt till buffern
	for (int i = 0; i < buf.size(); i++) {
		if (value == buf[i]) {
			return buf.begin() + i;
		}
	}
	return (buf.end() - 1);
	
}

const int* int_sorted::begin() const
{
	return buf.begin();
}

const int* int_sorted::end() const
{
	return buf.end();
} 

int_sorted int_sorted::merge(const int_sorted& merge_with) const //Merge funkar p� det s�ttet att den delar osorterad lista till en N sublists, each containing one element.
{																 //Merge upprepar sublist f�r att skapa nya sorterade sublister.A �r listan vi �r och b �r listan vi vill mergea med
	int_buffer output(size() + merge_with.size());  //skapar en buffert som ska inneh�lla v�ra mergeade element 
	const int* a = begin();  // begin returnerar en const pekare
	const int* b = merge_with.begin(); 
	int* c = output.begin(); // Skriver in till c

	while (a != end() && b != merge_with.end()) { //K�r s� l�nge a och b 
		if (*a < *b) { //j�mf�r vad de pekar p�, kollar v�rdet.
			*c = *a; // det C pekar p� ska bli det A pekar p�
			a++;  
		}
		else {		
			*c = *b; 
			b++;
		}
		c++;
	}
	while (a != end()) { // h�r skriver vi resterande
		*c = *a;
		c++;
		a++;
	}
	while (b != merge_with.end()) { 
		*c = *b;
		b++;
		c++;
	}
	int_sorted sorted(nullptr, 0); // Skapar tom int sorted. Allokerar inget minne
	sorted.buf = std::move(output); // flyttar in det i v�r skapade buffer genom move
	return sorted; 

}
