#include <iostream>
#include <ostream>
#include "Single_linked_list.h"


int main(){
 
	my::Forward_list<int> my_list = {8, 7, 6, 4, 9, 2, 7, 15, 1, 5};

	my_list.print();
	std::cout << "*****" << std::endl;

	std::cout << my_list.find(9)->m_val << std::endl;


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
		if(val == itr)
		{
			std::cout << "\nYES  ";
			std::cout  << *itr << std::endl;
			++val;
		}

		std::cout << *val << " ";
	}
	std::cout << std::endl;

}
