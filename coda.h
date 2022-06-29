#include"giocatore.h"
#ifndef CODA_H
#define CODA_H
template<typename T>
class nodo {
	nodo<T> * next;
	nodo<T> * prev;
	T val;
	template<typename U>
	friend class coda;
public:
	nodo(T val) : val(val) {next = nullptr; prev = nullptr; }
	nodo<T> * getNext() {return this->next; }
	friend ostream & operator<<(ostream &os, nodo & n) {
		return os << "val = " << n.val << endl;
		return os;
	}
};

template<typename T>
class coda {
	nodo<T> * head;
	int size = 0;
public:
	coda() { head = nullptr; }
	bool isEmpty() {return head == nullptr; }
	void enqueue(T val) {
		if(isEmpty()) {
			head = new nodo<T>(val);
			return;
		}
		nodo<T> * ptr = head;
		while(ptr->next) {
			ptr = ptr->next;
		}
		nodo<T> * toInsert = new nodo<T> (val);
		ptr->next = toInsert;
		return;
	}

	nodo<T> *  dequeue() {
		if(isEmpty()) 
			return nullptr;
		nodo<T> * tmp = head;
		head = head->next;
		
		return tmp;

	}

	friend ostream &operator<<(ostream &os, coda<T> & c) {
		if(c.isEmpty()) {
			cout << "empty " << endl;
			return os;
		}
		nodo<T> * ptr = c.head;
		while(ptr) {
			os << *ptr << endl;
			ptr = ptr->getNext();
		}
		return os;

	}
};
#endif