#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	Node(int initdata) {
		data = initdata;
		next = NULL;
	}
	int getData() { return data; }
	Node *getnext() { return next; }
	void setData(int newData) { data = newData; }
	void setNext(Node *newnext) {next = newnext;}
		
	~Node();

private:
	int data;
	Node *next;
};

Node::Node()
{
}

Node::~Node()
{
}