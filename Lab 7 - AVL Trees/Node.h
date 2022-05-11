#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
    private:
    string str;
    int num;

    Node* left;
    Node* right;
    Node* parent;
    int height;

    

    public:
    Node(string str) {
        this->str = str;
        this->num = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
        this->parent = nullptr;
    }

    void printNode();


    // getters

    int getNum() {
        return this->num;
    }
    string getString() {
        return this->str;
    }

    Node* getLeft() {
        return this->left;
    }

    Node* getRight() {
        return this->right;
    }

    int getHeight() {
        return this->height;
    }

    Node* getParent() {
        return this->parent;
    }

    

    // setters

    void setLeft(Node* newLeft) {
        this->left = newLeft;
    }

    void setRight(Node* newRight) {
        this->right = newRight;
    }

    void setData(string newString, int newNum) {
        this->str = newString;
        this->num = newNum;
    }

    void setHeight(int newHeight) {
        this->height = newHeight;
    }

    void setParent(Node* newParent) {
        this->parent = newParent;
    }

    void addOne() {
        this->num = this->num + 1;
    }

    void decrement() {
        this->num = this->num - 1;
    }

    
};

#endif