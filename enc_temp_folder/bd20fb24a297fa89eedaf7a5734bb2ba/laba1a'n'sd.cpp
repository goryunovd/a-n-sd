#include <iostream>
#include"Listclass.h"
#include"Nodeclass.h"
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
	list.insert(22, 5);

	std::cout << "Element by index 3:" << list.at(3) << std::endl;
	list.set(3, 35);
	list.insert(99, 5);
	list.reverse();

	list.insert(99, 0);
	std::cout << list << std::endl;

	std::cout << "Delete full list.\n";
	list.clear();
}