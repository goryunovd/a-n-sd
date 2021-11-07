#ifndef NODECLASS_H
#pragma once
#include<iostream>
using namespace std;
/*
Every list has empty or no Node/element, description of node is here 
*/
class Node
{
private:
	int data;
	Node* next;Node* prev;
public:
	Node(int data = 0, Node* next = NULL, Node* prev = NULL): data(data), next(next), prev(prev) {}
	~Node() = default; 
	int getData() { return data; }
	int getNextData() { if (next == NULL)  return 0; else return next->data; }
	int getPrevData() { if (prev == NULL)  return 0; else return prev->data; }
	void setData(int newData) { data= newData; }
	void setNext(Node* newnext) {next = newnext;}
	void setPrev(Node* newprev) {prev = newprev;}

	Node* getNext()  { return next; }
	Node* getPrev()  { return prev; }
	Node* makeNull() { return next = NULL; }


};
#endif