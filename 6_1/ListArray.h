#pragma once
#include"Coin.h"
#include"ColdWeapon.h"
#include"Exhibit.h"
#include"Figurines.h"
#include"Photo.h"
#include"Picture.h"
#include"List.h"



class ListArray {
private:
	List<Exhibit*> l;
public:
	
	ListArray() {}
	ListArray(ListArray& s) {
		l = s.l;
	}
	ListArray& operator=(ListArray& s) {
		l = s.l;
		return *this;
	}
	ListArray(ListArray&& s) {
		l = s.l;
		s.clear();
	}
	ListArray& operator=(ListArray&& s) {
		l = s.l;
		s.clear();
		return *this;
	}
	
	template<typename T>
	void push_back(T* st) {
		l.push_back(st);
	}
	
	int size() {
		return l.GetSize();
	}
	
	
	void clear() {
		for (int i = 0; i < l.GetSize(); i++) {
			l[i]->clear();
		}
		l.clear();
	}
	void clone(ListArray& s) {
		for (int i = 0; i < s.size(); i++) {
			l.push_back(s.l[i]->clone());
		}
	}

	void pop(int index) {
		l[index]->clear();
		l.removeAt(index);
	}
	void print() {
		if (l.GetSize() == 0) {
			cout << "List is empty!" << endl;
			return;
		}
		for (unsigned int i = 0; i < l.GetSize(); i++)
			cout << *l[i] << endl;
		
	}

	

};