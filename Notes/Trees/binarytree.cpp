#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {

    TreeNode* head;
    TreeNode* current;
    public:

    Tree() {
        head = nullptr;
        current = head;
    }

    void insert(int nodeData) {
        TreeNode* node = new TreeNode(nodeData);
        if(head == nullptr) {
            head = node;
            current = head;
        }
        else if(node->data <= head->data) {
            head->left = node;
            current = current->left;
        }
        else {
            head->right = node;
            current = current->right;
        }
    }

    void print() {
        cout << "Head: " << head->data << endl;
        cout << "Left: " << head->left->data << endl;
        cout << "Right: " << head->right->data << endl;
        
    }
};


int main() {
    Tree t = Tree();
    t.insert(5);
    t.insert(4);
    t.insert(6);

    t.print();
}
