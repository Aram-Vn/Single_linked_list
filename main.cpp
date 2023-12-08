#include <iostream>
#include "Single_linked_list.h"

int main(){
 
	my::Forward_list<int> my_list = {8, 7, 6, 4, 9, 2, 7, 15, 1, 0};

	my_list.print();
	std::cout << "*****" << std::endl;
	
	my_list.insertionSort();
	my_list.print();
	std::cout << "*****" << std::endl;
	
}
