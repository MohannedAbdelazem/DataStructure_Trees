#include <iostream>
using namespace std;
#include "./student.cpp"
struct Node{
    Node *left;
    Node *right;
    student *st;
    // int id, string name, double gpa, string department
    Node(){
        st = new student();
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node* insert(Node *node, student stud){
        if(node == NULL){
            node = new Node();
            node->st->setStudent(stud);
        }
        else if(stud.getID() <= node->st->getID()){
            node->left = insert(node->left, stud);
        }
        else{
            node->right = insert(node->right, stud);
        }
        return node;
    }
    void insert(student stud){
        root = insert(root, stud);
    }
    void printInOrder(Node *node){
        if(node == NULL)
            return;
        printInOrder(node->left);
        node->st->print();
        printInOrder(node->right);
    }
    void print(){
        printInOrder(root);
    }
    // bool search(Node *node, student stud){
    //     if(node == NULL){
    //         return false;
    //     }
    //     else if(stud.getID() == node->st->getID()){
    //         return true;
    //     }
    //     else if(stud.getID() <= node->left->st->getID()){
    //         search(node->left, stud);
    //     }
    //     else{
    //         search(node->right, stud);
    //     }
    // }
    void removeNode(Node *&node, student stud){
        if(node == NULL){
            return;
        }
        else if(stud.getID() < node->st->getID()){
            removeNode(node->left, stud);
        }
        else if(stud.getID() > node->st->getID()){
            removeNode(node->right, stud);
        }
        else{
            //which means stud.getID() == node->st->getID()
            if(node->left == NULL && node->right == NULL){
                // delete node;
                node = NULL;
            }
            else if(node->left == NULL){
                Node *tmp = node;
                node = node->right;
                tmp = NULL;
                // delete tmp;
            }
            else if(node->right == NULL){
                Node *tmp = node;
                node = node->left;
                // delete tmp;
                tmp = NULL;
            }
            else{
                Node *predecessor = node->left;
                while(predecessor->right != NULL){
                    predecessor = predecessor->right;
                }
                root->st->setStudent(*(predecessor->st));
                removeNode(predecessor, *(predecessor->st));
            }
        }
    }
    void remove(student stud){
            removeNode(root, stud);

    }
    bool search(Node *node, student stud){
        bool result;
        if(node == NULL){
            return false;
        }
        if(node->st->getID() < stud.getID()){
            result = search(node->left, stud);
        }
        else if(node->st->getID() > stud.getID()){
            result = search(node->right, stud);
        }
        else{
            return true;
        }
        return result;
    }
    bool search(student stud){
        bool result = search(root, stud);
        return result;
    }

};
