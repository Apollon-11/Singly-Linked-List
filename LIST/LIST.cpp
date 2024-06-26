﻿#include <iostream>

template<typename T>
class List {
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAT(int index);
	void pop_back();
private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;
		Node(T data=T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int count = 0;
	Node<T> *current = this->head;
	while (current != nullptr) {
		if (count == index)
			return current->data;
		current = current->pNext;
		count++;

	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;	
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0) {
		pop_front(data);
	}
	else {
		Node<T> previos = this->head;
		for (int i = 0; i < index - 1; i++) {
			previos = previos->pNext;
		}
		Node<T> *newNode = new Node<T>(data, previos->pNext);
		previos->pNext = newNode;
	}
	Size++;
}

template<typename T>
void List<T>::removeAT(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T> *previos = this->head;
		for (int i = 0; i < index - 1; i++) {
			previos = previos->pNext;
		}
		Node<T> *toDelete = previos->pNext;
		previos->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAT(Size - 1);
	Size--;
}
