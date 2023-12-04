#include <iostream>
#include "Single_linked_list.h"

int main(){
 my::Forward_list<int> my_list;

    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);

	std::cout << my_list.front() << std::endl;
	std::cout << my_list.back() << std::endl;

}
