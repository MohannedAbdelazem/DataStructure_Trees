#include <iostream>
#include "./student.cpp"
#include <vector>
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
        virtual Node* removeNode(Node* node, Student stud) {
            if (node == NULL) {
                return node;
            }
            if (stud.getID() < node->student->getID()) {
                node->left = removeNode(node->left, stud);
            } else if (stud.getID() > node->student->getID()) {
                node->right = removeNode(node->right, stud);
            } else {
                if (node->left == NULL || node->right == NULL) {
                    Node* temp = node->left ? node->left : node->right;
                    if (temp == NULL) {
                        temp = node;
                        node = NULL;
                    } else {
                        *node = *temp;
                    }
                    delete temp;
                } else {
                    Node* temp = node->left;
                    while (temp->right != NULL) {
                        temp = temp->right;
                    }
                    node->student->setStudent(*(temp->student));
                    node->left = removeNode(node->left, *(temp->student));
                }
            }
            if (node == NULL) {
                return node;
            }
            int balanceFactor = calculateBalance(node);
            if (balanceFactor > 1 && calculateBalance(node->left) >= 0) {
                return rightRotate(node);
            }   
            if (balanceFactor > 1 && calculateBalance(node->left) < 0) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if (balanceFactor < -1 && calculateBalance(node->right) <= 0) {
                return leftRotate(node);
            }
            if (balanceFactor < -1 && calculateBalance(node->right) > 0) {
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

class heapSort{
    private:
    vector<Student> st;
    void swap(Student &gpa1, Student &gpa2){
        Student gpa1tmp(gpa1);
        gpa1.setStudent(gpa2);
        gpa2.setStudent(gpa1tmp);
    }
    void heapifyMin(int n, int i){
        int largest = i;
        int left = i*2+1;
        int right = i*2+2;
        if(left < n && st[left].getGPA() > st[largest].getGPA()){
            largest = left;
        }
        if(right < n && st[right].getGPA() > st[largest].getGPA()){
            largest = right;
        }
        if(largest != i){
            swap(st[i], st[largest]);
            heapifyMin(n, largest);
        }
    }
    void heapsortMin(){
        for(int i = st.size()/2-1;i>=0;i--){
            heapifyMin(st.size(), i);
        }
        for(int i = st.size()-1;i>=0;i--){
            swap(st[i], st[0]);
            heapifyMin(i, 0);
        }
    }


    void heapifyMax(int n, int i){
        int smallest = i;
        int left = i*2+1;
        int right = i*2+2;
        if(left < n && st[left].getGPA() < st[smallest].getGPA()){
            smallest = left;
        }
        if(right < n && st[right].getGPA() < st[smallest].getGPA()){
            smallest = right;
        }
        if(smallest != i){
            swap(st[i], st[smallest]);
            heapifyMax(n, smallest);
        }
    }
    void heapsortMax(){
        for(int i = st.size()/2-1;i>=0;i--){
            heapifyMax(st.size(), i);
        }
        for(int i = st.size()-1;i>=0;i--){
            swap(st[i], st[0]);
            heapifyMax(i, 0);
        }
    }
    public:
    void insert(Student s){
        st.push_back(s);
    }

    void printMin(){
        heapsortMin();
        for(int i = 0;i<st.size();i++){
            st[i].print();
            cout << endl;
        }
    }
    void printMax(){
        heapsortMax();
        for(int i = 0;i<st.size();i++){
            st[i].print();
            cout << endl;
        }
    }
};
