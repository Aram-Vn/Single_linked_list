#include <iostream>
#include "Single_linked_list.h"

int main(){
 my::Forward_list<int> my_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
	std::cout << "*****" << std::endl;
	my_list.print();

	my::Forward_list<int> test(my_list);
	std::cout << "*****" << std::endl;
	test.print();


	test.reverse();
	std::cout << "*****" << std::endl;
	test.print();
}
