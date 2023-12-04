#include <iostream>
#include "Single_linked_list.h"

int main(){
 my::Forward_list<int> my_list;

    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(3);
    my_list.push_back(3);
    my_list.push_back(3);
    my_list.push_back(4);
    my_list.push_back(99);

	my_list.clear();
    my_list.push_back(3);
    my_list.push_back(4);


	std::cout << my_list.front() << std::endl;
	std::cout << my_list.back() << std::endl;
	std::cout << my_list.size() << std::endl;

	my::Forward_list<int> test(my_list);

	std::cout << my_list.front() << std::endl;
	std::cout << my_list.back() << std::endl;
	std::cout << my_list.size() << std::endl;


}