#include "arithmeticExpression.h"
#include <stack>
#include <sstream>
#include <fstream>

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

// void arithmeticExpression::visualizeTree(const string &outputFilename){
//     ofstream outFS(outputFilename.c_str());
//     if(!outFS.is_open()){
//         cout<<"Error opening "<< outputFilename<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     visualizeTree(outFS,root);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }


// implement these

/* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the 
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */
    void arithmeticExpression::buildTree() {
        string postfix = infix_to_postfix();
        stack<TreeNode*> postfixStack;
        // have to assign root and its children
        char operandLetter = 'A';
        char c;

        for(unsigned i = 0; i<postfix.size(); i++) {
             c = postfix.at(i);

        // if it's an operator
        /* ex. if the expression was infix: A + B, postFix = AB+
            it would first push A and B onto the stack (in the first 2 iterations)
            then, it would see that there is a + sign 
            at that point, it will assign A as the left child and B as the right child

            visualization:          +
                                A       B
        */
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            TreeNode* newRoot = new TreeNode(c, operandLetter + i);
            // pop twice and set as children
            newRoot->left = postfixStack.top();
            postfixStack.pop();
            newRoot->right = postfixStack.top();
            postfixStack.pop();
            // push the new tree onto the stack
            postfixStack.push(newRoot);
        } 

        // if it's an operand
        else {
            TreeNode* newOperandRoot = new TreeNode(c, operandLetter + i);
            postfixStack.push(newOperandRoot);
        }
    }
    root = postfixStack.top();
    postfixStack.pop();
    // stack should be empty
        }
    

    /* Calls the recursive infix function. */
    void arithmeticExpression::infix() {
        if(isEmpty()) {
            return;
        }
        infix(this->root);
    }

    void arithmeticExpression::infix(TreeNode* node) {
    if(node != nullptr) {
        if (node->left != 0 || node->right != 0) {
            cout << "(";
        }
            infix(node->right);
            cout << node->data;
            infix(node->left);
            if (node->left != 0 || node->right != 0) {
            cout << ")";
            }
        }
        else {
        return;
        }
    }

    

    /* Calls the recursive prefix function. */
    void arithmeticExpression::prefix() {
        if(isEmpty()) {
            return;
        }
        prefix(this->root);
    }
    /* Helper function that outputs the prefix notation of the arithmetic expression tree
       by performing the preorder traversal of the tree. */
    void arithmeticExpression::prefix(TreeNode* node) {
        if(node!=nullptr) {
        cout << node->data;
        prefix(node->right);
        prefix(node->left);
        }
        else {
            return;
        }
    }


    /* Calls the recursive postfix function. */
    void arithmeticExpression::postfix() {
        if(isEmpty()) {
            return;
        }
        postfix(this->root);
    }

    void arithmeticExpression::postfix(TreeNode* node) {
        if(node != nullptr) {
        postfix(node->right);
        postfix(node->left);
        cout << node->data;
        }
        else {
            return;
        }
    }