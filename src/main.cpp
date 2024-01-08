#include <iostream>
#include <ostream>
#include "Single_linked_list.h"

int main(){
 
	my::Forward_list<int> my_list = {8, 7, 6, 4, 9, 2, 7, 15, 1, 5};

	my_list.print();
	std::cout << "*****" << std::endl;
	
	// // my_list.insertionSort();
	// my_list.print();
	// std::cout << "*****" << std::endl;

	my::Forward_list<int>::f_itr itr = my_list.begin();
	itr++; // 8
	itr++; // 7
	std::cout  << itr->m_val << std::endl;
	
	for(auto val = my_list.begin(); val != my_list.end(); ++val)
	{
		std::cout << val->m_val << " ";
	}
	std::cout << std::endl;
}
