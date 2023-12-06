#include <iostream>
#include "Single_linked_list.h"

int main(){
 
	my::Forward_list<int> my_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	my_list.print();
	std::cout << "*****" << std::endl;

	my::Forward_list<int> test;

	test.assign(5, 8);
	test.print();
	std::cout << "*****" << std::endl;

	test.assign({2, 2, 3});
	test.print();
	
}

