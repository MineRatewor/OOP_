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
	void push_back(Coin& st) {
		Coin* st1 = new Coin(st);
		l.push_back(st1);
	}

	void push_back(ColdWeapon& st) {
		ColdWeapon* st1 = new ColdWeapon(st);
		l.push_back(st1);
	}

	void push_back(Figurines& st) {
		Figurines* st1 = new Figurines(st);
		l.push_back(st1);
	}
	
	
	int size() {
		return l.GetSize();
	}
	void push_back(Picture& st) {
		Picture* st1 = new Picture(st);
		l.push_back(st1);
	}

	void push_back(Photo& st) {
		Photo* st1 = new Photo(st);
		l.push_back(st1);
	}

	void pop_back() {
		l.pop_back();
	}
	
	void clear() {
		l.clear();
	}
	
	
	void pop(int index) {
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