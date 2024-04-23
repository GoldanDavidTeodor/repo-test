#pragma once
#include <iostream>

template <typename T>
struct Node {
    T info;
    Node<T>* child;
    Node<T>* nextSibling;

    Node(T info) : info(info), child(nullptr), nextSibling(nullptr) {}
};

template<typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete_subtree(root);
    }

    void add_node(Node<T>* parent, T value) {
        Node<T>* new_node = new Node<T>(value);
        if (!parent) {
            if (!root)
                root = new_node;
            else {
                std::cout << "radacina are nod deja" << '\n';
                delete new_node;
            }
        }
        else {
            if (!parent->child)
                parent->child = new_node;
            else {
                Node<T>* temp = parent->child;
                while (temp->nextSibling)
                    temp = temp->nextSibling;
                temp->nextSibling = new_node;
            }
        }
    }

    Node<T>* get_node(Node<T>* parent) {
        return parent ? parent->child : root;
    }

    void delete_node(Node<T>* node) {
        if (!node) return;
        delete_subtree(node->child);
        delete node;
    }

private:
    void delete_subtree(Node<T>* node) {
        if (!node) return;
        delete_subtree(node->nextSibling);
        delete_subtree(node->child);
        delete node;
    }
};
