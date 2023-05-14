#include <iostream>
#include "./Student.cpp"
using namespace std;
class BST{
    private:
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
        Node *root;
        void removeNode(Node *&node, Student stud){
            if(node == NULL){
                return;
            }
            else if(stud.getID() < node->student->getID()){
                removeNode(node->left, stud);
            }
            else if(stud.getID() > node->student->getID()){
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
                    root->student->setStudent(*(predecessor->student));
                    removeNode(predecessor, *(predecessor->student));
                }
            }
        }
        bool search(Node *node, Student stud){
            bool result;
            if(node == NULL){
                return false;
            }
            if(node->student->getID() < stud.getID()){
                result = search(node->right, stud);
            }
            else if(node->student->getID() > stud.getID()){
                result = search(node->left, stud);
            }
            else{
                node->student->print();
                cout << '\n';
                return true;
            }
            return result;
        }
        Node* insert(Node *node, Student stud){
            if(node == NULL){
                node = new Node();
                node->student->setStudent(stud);
            }
            else if(stud.getID() <= node->student->getID()){
                node->left = insert(node->left, stud);
            }
            else{
                node->right = insert(node->right, stud);
            }
            return node;
        }
    public:
        BST() : root(NULL){}
        void insert(Student stud){
            root = insert(root, stud);
        }
        void printInOrder(Node *node){
            if(node == NULL)
                return;
            printInOrder(node->left);
            node->student->print();
            cout << '\n';
            printInOrder(node->right);
        }
        void print(){
            printInOrder(root);
        }
        void remove(Student stud){
            removeNode(root, stud);
        }
        bool search(Student stud){
            bool result = search(root, stud);
            return result;
        }

};
