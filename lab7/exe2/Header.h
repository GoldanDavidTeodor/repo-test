#pragma once
#include <iostream>

template <typename T>
struct Node {
    T info;
    Node<T>* child;
    Node<T>* sibling;

    Node(T info) : info(info), child(nullptr), sibling(nullptr) {}
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
                while (temp->sibling)
                    temp = temp->sibling;
                temp->sibling = new_node;
            }
        }
    }

    Node<T>* get_node(Node<T>* parent) {
    if (parent)
        return parent->child;
    else
        return root;
}


    void delete_node(Node<T>* node) {
        if (!node) return;
        delete_subtree(node->child);
        delete node;
    }


    void delete_subtree(Node<T>* node) {
        if (!node) return;
        delete_subtree(node->sibling);
        delete_subtree(node->child);
        delete node;
    }
};
