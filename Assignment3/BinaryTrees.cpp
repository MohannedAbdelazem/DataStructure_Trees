#include <iostream>
#include "./Student.cpp"
using namespace std;
class BST{    
    protected:
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
        virtual Node* insert(Node *node, Student stud){
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
        void printInOrder(Node *node){
            if(node == NULL)
                return;
            printInOrder(node->left);
            node->student->print();
            cout << '\n';
            printInOrder(node->right);
        }
        virtual void removeNode(Node *&node, Student stud){
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
                    delete node;
                    node = NULL;
                }
                else if(node->left == NULL){
                    Node* tmp = node;
                    node = node->right;
                    delete tmp;
                }
                else if(node->right == NULL){
                    Node* tmp = node;
                    node = node->left;
                    delete tmp;
                }
                else{
                    Node *predecessor = node->left;
                    while(predecessor->right != NULL){
                        predecessor = predecessor->right;
                    }
                    node->student->setStudent(*(predecessor->student));
                    removeNode(predecessor, *(predecessor->student));
                }
            }
        }
        Node *root;
    private:    
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
    public:
        BST() : root(NULL){}
        virtual void insert(Student stud){
            root = insert(root, stud);
        }
        virtual void print(){
            printInOrder(root);
        }
        virtual void remove(Student stud){
            removeNode(root, stud);
        }
        bool search(Student stud){
            bool result = search(root, stud);
            return result;
        }
};
class AVL : public BST{
    private:
        int calculateHeight(Node* node){
            if(node == NULL){
                return -1;
            }
            int leftHeight = calculateHeight(node->left);
            int rightHeight = calculateHeight(node->right);
            if(leftHeight > rightHeight){
                return leftHeight + 1;
            }else{
                return rightHeight + 1;
            }
        }
        int calculateBalance(Node* node){
            if(node==NULL){
                return -1;
            }
            return (calculateHeight(node->left) - calculateHeight(node->right));
        }
        Node* rightRotate(Node* node){
            Node *otherNode = node->left;
            Node *subTree = otherNode->right;
            otherNode->right = node;
            node->left = subTree;
            return otherNode;
        }
        Node* leftRotate(Node *node) {
            Node *otherNode = node->right;
            Node *subTree = otherNode->left; 
            otherNode->left = node;
            node->right = subTree;
            return otherNode;
        }
    protected:
        virtual Node* insert(Node* node, Student stud) {
            node = BST::insert(node, stud);
            int balanceFactor = calculateBalance(node);

            // Left Left Case
            if (balanceFactor > 1 && stud.getID() < node->left->student->getID())
                return rightRotate(node);

            // Right Right Case
            if (balanceFactor < -1 && stud.getID() > node->right->student->getID())
                return leftRotate(node);

            // Left Right Case
            if (balanceFactor > 1 && stud.getID() > node->left->student->getID()) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (balanceFactor < -1 && stud.getID() < node->right->student->getID()) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }
        virtual Node* removeNode(Node* node,Student stud){
            BST::removeNode(node, stud);
            if (root == NULL)
		        return root;
            int balanceFactor = calculateBalance(root);
            // Left Left Case
            if (balanceFactor > 1 && stud.getID() < node->left->student->getID())
                return rightRotate(node);
            // Right Right Case
            if (balanceFactor < -1 && stud.getID() > node->right->student->getID())
                return leftRotate(node);
            // Left Right Case
            if (balanceFactor > 1 && stud.getID() > node->left->student->getID()) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            // Right Left Case
            if (balanceFactor < -1 && stud.getID() < node->right->student->getID()) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }
    public:
        virtual void insert(Student stud) {
            root = AVL::insert(root, stud);
        }
        virtual void remove(Student stud){
            root = AVL::removeNode(root, stud);
        }
};