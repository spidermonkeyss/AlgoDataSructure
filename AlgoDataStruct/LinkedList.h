#pragma once
#include <string>

template <class T>
class Node
{
public:
	T data;
	Node* next = nullptr;
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* currentIterationNode;

	Node<T>* GetNextNode(Node<T>* node);
	Node<T>* IterateToTail();

	void DeleteNextNode(Node<T>* node);
public:
	int count;
	
	LinkedList();
	~LinkedList();

	void BeginListIteration();
	void NextListIteration();
	T GetCurrentListIterationData();

	void PushBack(T data);
	void PushFront(T data);
	void PopBack();
	void PopFront();

	std::string DisplayList();
};

#include "LinkedList.hpp"