#pragma once
#include"Coin.h"
#include"ColdWeapon.h"
#include"Exhibit.h"
#include"Figurines.h"
#include"Photo.h"
#include"Picture.h"
#include"List.h"

class OwnedList {
public:
    OwnedList() : size(0) {}
    ~OwnedList() {
        clear();
    }

    void insert(Exhibit* item) {
        Exhibit** newItems = new Exhibit * [size + 1];
        for (size_t i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        newItems[size] = item;
        delete[] items;
        items = newItems;
        size++;
    }

    void remove(size_t index) {
        if (index >= size) {
            return;
        }

        Exhibit** newItems = new Exhibit * [size - 1];
        for (size_t i = 0, j = 0; i < size; i++) {
            if (i != index) {
                newItems[j++] = items[i];
            }
            else {
                delete items[i];
            }
        }
        delete[] items;
        items = newItems;
        size--;
    }

    void clear() {
        for (size_t i = 0; i < size; i++) {
            delete items[i];
        }
        delete[] items;
        items = nullptr;
        size = 0;
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            items[i]->print();
        }
    }

private:
    size_t size;
    Exhibit** items;
};