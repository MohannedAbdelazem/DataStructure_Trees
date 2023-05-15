#ifndef TREES_H
#define TREES_H
#include "Student.h"
#include <iostream>
#include <map>
using namespace std;
class BST{    
    protected:
        map<string, int> stdDp;
        int size = 0;
        struct Node{
            Node *left;
            Node *right;
            Student *student;
            Node(){
                student = new Student();
                left = NULL;
                right = NULL;
            }
        };
        virtual Node *insert(Node *node, Student stud);
        void printInOrder(Node *node);
        virtual Node *removeNode(Node *&node, Student stud);
        Node *root;
    private:
        bool search(Node *node, Student stud);
    public:
        int getSize();
        BST() : root(NULL){}
        virtual void insert(Student stud);
        virtual void print();
        virtual void remove(Student stud);
        bool search(Student stud);
};
class AVL : public BST{
    private:
        int calculateHeight(Node *node);
        int calculateBalance(Node *node);
        Node *rightRotate(Node *node);
        Node *leftRotate(Node *node);
    protected:
        virtual Node *insert(Node *node, Student stud);
        virtual Node *removeNode(Node *node, Student stud);
    public:
        virtual void insert(Student stud);
        virtual void remove(Student stud);
};
#endif
