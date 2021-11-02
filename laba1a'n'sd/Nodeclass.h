#ifndef NODECLASS_H
#pragma once
#include<iostream>
using namespace std;
/*
Every list has empty or no Node/element, description of node is here 
*/
class Node
{
public:
	Node(int initdata = 0, Node*next = NULL, Node*prev = NULL): data(data), next(next), prev(prev) {}
	~Node()=default;
	int getData() { return this->data; }
	int getNextData() { if (this->next == NULL)  return 0; else return this->next->data; }
	int getPrevData() { if (this->prev == NULL)  return 0; else return this->prev->data; }
	void setData(int newData) { this->data= newData; }
	void setNext(Node *newnext) {this->next = newnext;}
	void setPrev(Node *newprev) { this->prev = newprev;}

	Node *getNext()  { if (this->next == NULL) { return 0; } else return this->next; }
	Node *getPrev()  { if (this->prev== NULL) { return 0; } else return this->prev; }
	Node *makeNull() { return this->next = NULL; }
private:
	int data;
	Node *next;Node *prev;
};
#endif