#include <iostream>
#include "Single_linked_list.h"

int main(){
 my::Forward_list<int> my_list;

    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(4);
    my_list.push_back(5);
    my_list.push_back(6);
    my_list.push_back(7);
    my_list.push_back(8);
 
    my_list.insert(8, 99);
    my_list.insert(1, 99);
    my_list.insert(0, 88);

	my_list.print();
	my_list.erase(1);

	my_list.print();

	my_list.erase(0);

	my_list.print();

	my_list.clear();
    my_list.push_back(3);
    my_list.push_back(4);

	std::cout << "*****" << std::endl;
	my_list.print();

	/* std::cout << my_list.front() << std::endl; */
	/* std::cout << my_list.back() << std::endl; */
	/* std::cout << my_list.size() << std::endl; */

	my::Forward_list<int> test(my_list);

	/* std::cout << my_list.front() << std::endl; */
	/* std::cout << my_list.back() << std::endl; */
	/* std::cout << my_list.size() << std::endl; */


	std::cout << "*****" << std::endl;
	test.print();
}
