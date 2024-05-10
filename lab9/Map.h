#pragma once
#include <iostream>


template <class Key, class Data>
struct InfoNode {
    Key key;
    Data data;
    int index;
};

template <class Key, class Data>
struct Node {
    InfoNode<Key, Data> content;
    Node<Key, Data>* urm;

    Node() {
        content.index = 0;
    }

    ~Node() {
        delete urm;
    }

    Node<Key, Data>& operator ++() {
        *this = *(this->urm);
        return *this;
    }

    InfoNode<Key, Data> operator *() {
        return this->content;
    }

    bool operator !=(Node<Key, Data>& node) {
        return content.key != node.content.key;
    }
};

template<class Key, class Data>
class Map {
    int size;
    Node<Key, Data>* first;
    Node<Key, Data>* last;
public:
    Map() : size(0) {
        first = new Node<Key, Data>;
        first->content.index = size;
        first->urm = nullptr;
        last = first;
    }
    ~Map() { delete first; }

    Data& operator[] (int key) {
        Node<Key, Data>* nptr = first;
        while (nptr != last) {
            if (key == nptr->content.key)
                return static_cast<Data&>(nptr->content.data);
            nptr = nptr->urm;
        }

        nptr->content.key = key;

        nptr->urm = new Node<Key, Data>;
        last = nptr->urm;
        last->content.index = ++size;
        last->urm = nullptr;

        return static_cast<Data&>(nptr->content.data);
    }

    Node<Key, Data> begin() const {
        return *(this->first);
    }

    Node<Key, Data> end() const {
        return *(this->last);
    }

    void Set(Key key, Data data) {
        (*this)[key] = data;
    }

    bool Get(const Key& key, Data& value) {
        Node<Key, Data>* nptr = first;
        while (nptr != last) {
            if (key == nptr->content.key) {
                value = nptr->content.data;
                return true;
            }
            nptr = nptr->urm;
        }

        return false;
    }

    int Count() { return size; }

    void Clear() {
        delete first;
        first = new Node<Key, Data>;
        first->content.index = size = 0;
        first->urm = nullptr;
        last = first;
    }

    bool Includes(const Map<Key, Data>& map) {
        Data temp;
        for (auto [key, value, index] : map)
            if (Get(key, temp) == false) return false;
        return true;
    }
};