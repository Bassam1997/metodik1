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
	int_buffer sorting(buf.size() + 1); //större buffer +1
	std::merge(buf.begin(), buf.end(), &value, &value + 1, sorting.begin()); //Mergea vår nuvarande buffer med value. Flyttar vår merge till sorting.begin och därefter till buffern
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

int_sorted int_sorted::merge(const int_sorted& merge_with) const //Merge funkar på det sättet att den delar osorterad lista till en N sublists, each containing one element.
{																 //Merge upprepar sublist för att skapa nya sorterade sublister.A är listan vi är och b är listan vi vill mergea med
	int_buffer output(size() + merge_with.size());  //skapar en buffert som ska innehålla våra mergeade element 
	const int* a = begin();  // begin returnerar en const pekare
	const int* b = merge_with.begin(); 
	int* c = output.begin(); // Skriver in till c

	while (a != end() && b != merge_with.end()) { //Kör så länge a och b 
		if (*a < *b) { //jämför vad de pekar på, kollar värdet.
			*c = *a; // det C pekar på ska bli det A pekar på
			a++;  
		}
		else {		
			*c = *b; 
			b++;
		}
		c++;
	}
	while (a != end()) { // här skriver vi resterande
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
	sorted.buf = std::move(output); // flyttar in det i vår skapade buffer genom move
	return sorted; 

}
