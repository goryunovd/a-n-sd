#pragma once
#ifndef listclass_H
#include<iostream>
#include"Nodeclass.h"
/*
here is the descrpitpion of 
*/
class List
{
private:
	Node* head, *tail;
public:
	List() { this->head = NULL; this->tail = this->head; }
	
	List(int data)
	{
		Node* elem = new Node(data);
		this->head = elem;
		this->tail = elem;
	}
	void push_back(int data)// algorithm for adding a node to the end
	{
		if (this->tail == NULL)
		{
			push_front(data);
		}
		else
		{

			Node* cur = new Node();
			cur = this->tail;	
			Node *tmp = new Node(data);
			this->tail->setNext(tmp);
			this->tail = tmp;
			this->tail->setPrev(cur);
		}
	}
	void push_front(int data)// algorithm for adding a node to the beginning
	{
		if (head == NULL)
		{
			Node *tmp = new Node(data);
			head = tmp;
			tail = head;
			tail->makeNull();
			head->makeNull();
		}
		else
		{
			Node* cur = new Node;
			cur = this->head;
			Node *tmp = new Node(data);
			tmp->setNext(head);
			this->head = tmp;
			cur->setPrev(head);
		}
	}

	void pop_back() //delete last element of the list
	{
		if (tail == head) { pop_front(); }
		else { Node* cur = new Node; cur = tail; tail = tail->getPrev(); delete cur; tail->makeNull(); }
	}
	
	void pop_front()//delete first element of the list
	{
		if (head == NULL) { throw runtime_error("Failed to execute the functon pop_front\n"); }
		else { Node* cur = new Node; cur = head; head = head->getNext(); delete cur; }
	}

	void insert(int data, size_t index) //add element before current element choosed by index
	{
		Node* cur = new Node;
		cur = this->head;
		int number=0; bool check=0;
		if (index == number)
		{
			push_front(data); check = 1;
		}
		if (index == get_size() ) { push_back(data); check = 1; }
		else 
		{
			cur = head;
			while (cur != NULL)
			{
				if (index == (number + 1))
				{//cur2->tmp->cur
					check = 1;
					Node *cur2 = cur;
					Node *tmp = new Node(data);
					cur = cur->getNext();
					cur2->setNext(tmp);
					tmp->setNext(cur);
					tmp->setPrev(cur2);
					cur->setPrev(tmp);
				}
				number++;
				cur = cur->getNext();
			}
		}
		if(check==0)
		{
			throw invalid_argument("Failed to execute the function insert()\n");
		}
	}
	int at(size_t index)//get element by index
	{
		Node* cur = new Node;
		cur = this->head;
		int count = 0;
		while (cur != NULL)
		{
			if (index == count) { return cur->getData(); }

			count++;
			cur = cur->getNext();
		}
		if (cur == NULL) { throw invalid_argument("Not found element with this index\n"); }
	}

	void remove(size_t index) //delete current element
	{
	Node* cur = new Node;
		if (index==0)
	{
		pop_front();
	}
	else if (index == get_size() - 1) { pop_back(); }
	else { int count = 0; 
		cur = head; 
		while (cur != NULL)
		{
			if (count + 1 == index)
			{
				Node *prev_ = cur;
				cur = cur->getNext();
				Node *tmp = cur;
				cur = cur->getNext();
				prev_->setNext(cur);
				cur->setPrev(prev_);
				delete tmp;
			}
			count++;
			cur = cur->getNext();
		}
		}
		if (index>get_size())
		{
			throw invalid_argument("Failed to execute the function remove()\n");
		}
	}
	size_t get_size() { //get size of list
		Node *cur = head;
		int count = 0;
		while (cur != NULL)
		{
			count++;
			cur = cur->getNext();
		}
		return count;
	}
	void clear()//delete full list
	{
		Node* cur = head;
		while (cur != NULL)
		{
			head = cur->getNext();
			delete cur;
			cur = head;
		}
	}
	void set(size_t index, int new_data) //element[index] have new data
	{
		Node *cur = head;
		int count = 0;
		bool check = 0;
		while (cur != NULL)
		{
			if(index==count)
			{
				cur->setData(new_data);
				check = 1;
				break;
			}
		
			else
			{
				count++;
				cur = cur->getNext();
			}
		}
		if (check == 0) { throw invalid_argument("Failed to execute the function set()\n"); }
	}

	bool isEmpty() {//check if list is empty
		if (head == NULL) { return 1; }
		else {
			return 0;
		}
	}
friend ostream& operator<< (ostream& out,const List&List);
void reverse()
{
	if (get_size() <= 1) return;
	int tmp;
	for (size_t i = 0; i < get_size() / 2; i++)
	{
		tmp = at(i);
		set(i, at(get_size() - 1 - i));
		set(get_size() - 1 - i, tmp);
	}
}
~List() {
	Node* elem = head;
	Node* tmp;
	while (elem != NULL) {
		tmp = elem;
		elem = elem->getNext();
		delete tmp;
	}
}
};	

	ostream& operator<< (ostream& out, List& printList) // Overload operator output
	{
		out << "list: \n";
		for (int index = 0; index < printList.get_size(); index++) {
			out << printList.at(index) << endl;
		}
		return out;
	}
#endif // !listclass_H