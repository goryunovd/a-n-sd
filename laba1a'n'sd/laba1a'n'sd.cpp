#include <iostream>
#include"Listclass.h"
/*some commit*/
int main()
{
	List list(1);
	list.push_back(2);
	list.push_front(0);
	if (!list.isEmpty()) std::cout << "List is not empty.\n";
	else { std::cout << "List is empty.\n"; }

	for (int index = 0; index < 5; index++) {
		list.push_back(index + 10);
	}

	std::cout << "Size list: " << list.get_size() << std::endl;

	list.pop_front();
	list.pop_back();
	list.remove(3);
	list.insert(21, 3);
	std::cout << "Element[2]:" << list.at(2) << std::endl;
	list.set(3, 35);
	list.insert(1, 5);
	list.reverse();
	std::cout << list << std::endl;
	std::cout << "Delete full list.\n";
	list.clear();
}