#include <iostream>
#include "./BinaryTrees.cpp"
using namespace std;
class Controller{

    private:
        BST* bst = new BST();
        AVL* avl = new AVL();
        heapSort Minheap;
        heapSort Maxheap;
        Student generateTempStd(){
            int id;
            Student tmpStd;
            cout << "ID: ";
            cin >> id;
            tmpStd.setID(id);
            return tmpStd;
        }
        void readFile(){
            string path = "./file.txt";
            string line;
            ifstream file(path);
            if(!file.is_open()){
                return;
            }
            getline(file, line);
            int n = stoi(line);
            for (int i = 0; i < n; i++)
            {
                int id;
                string name;
                double gpa;
                string department;
                for (int j = 0; j < 4; j++)
                {
                    getline(file, line);
                    switch (j)
                    {
                    case 0:
                        id = stoi(line);
                        break;
                    case 1:
                        name = line;
                        break;
                    case 2:
                        gpa = stod(line);
                        break;
                    case 3:
                        department = line;
                        break;
                    default:
                        cout << "Impossible.... I must've made a mistake" << '\n';
                        break;
                    }
                }
                Student st(id, name, gpa, department);
                bst->insert(st);
                avl->insert(st);
                Minheap.insert(st);
                Maxheap.insert(st);
            }
        }
    public:
        void start(){
            readFile();
            while(true){
                //Controller App
                a:cout << "Welcome to our DataStructure Application" << '\n';
                cout << "Please choose one of the DataStructures: " << '\n';
                cout << "1. BST" << '\n';
                cout << "2. AVL" << '\n';
                cout << "3. Min heap" << '\n';
                cout << "4. Max heap" << '\n';
                cout << "5. Exit program" << '\n';
                int choice;
                cin >> choice;
                switch(choice){
                    case 1:
                        BinaryInterface(bst);
                        break;
                    case 2:
                        BinaryInterface(avl);
                        break;
                    case 3:
                        MinHeapInterface();
                        break;
                    case 4:
                        MaxHeapInterface();
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout << "Invalid entry.... please enter a valid entry" << '\n';
                        goto a;
                        break;
                }
            }
        }
        void MinHeapInterface(){
            while(1){
                cout << "1.Add student" << endl;
                cout << "2.Print Students" << endl;
                cout << "3.Main menu" << endl;
                int choice;
                cin >> choice;
                if(choice==1){
                    int id;
                    string name, department;
                    double gpa;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Name: ";
                    cin >> name;
                    cout << "GPA: ";
                    cin >> gpa;
                    cout << "Department: ";
                    cin >> department;
                    Student student(id, name, gpa, department);
                    Minheap.insert(student);
                    cout << "The student is added." << '\n';
                }
                else if(choice == 2){
                    Minheap.printMin();
                }
                else{
                    break;
                }

            }
        }
        void MaxHeapInterface(){
            a:cout << "1.Add student" << endl;
            cout << "2.Print Students" << endl;
            cout << "3.Main menu" << endl;
            int choice;
            cin >> choice;
            if(choice==1){
                    int id;
                    string name, department;
                    double gpa;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Name: ";
                    cin >> name;
                    cout << "GPA: ";
                    cin >> gpa;
                    cout << "Department: ";
                    cin >> department;
                    Student student(id, name, gpa, department);
                    Maxheap.insert(student);
                    cout << "The student is added." << '\n';
            }
            else if(choice == 2){
                Maxheap.printMax();
            }
            else{
                return;
            }
            goto a;
        }
        void BinaryInterface(BST* tree){
            BST* bs = tree;
            while(true){
                cout << "1. Add student" << '\n';
                cout << "2. Remove student" << '\n';
                cout << "3. Search student" << '\n';
                cout << "4. Print All (sorted by id)" << '\n';
                cout << "5. Return to main menu" << '\n';
                cout << "Enter number of option: ";
                int choice;
                cin >> choice;
                if(choice==1){
                    int id;
                    string name, department;
                    double gpa;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Name: ";
                    cin >> name;
                    cout << "GPA: ";
                    cin >> gpa;
                    cout << "Department: ";
                    cin >> department;
                    Student student(id, name, gpa, department);
                    bs->insert(student);
                    cout << "The student is added." << '\n';
                }else if(choice ==2){
                    Student std = generateTempStd();
                    if(bs->search(std)){
                        bs->remove(std);
                        cout << "Student is deleted. " << '\n';
                    }else{
                        cout << "Student is not found. " << '\n';
                    }
                }else if(choice ==3){
                    Student std = generateTempStd();
                    if(bs->search(std)){
                        cout << "Student is found. " << '\n';
                    }else{
                        cout << "Student is not found. " << '\n';
                    }
                }else if(choice ==4){
                    bs->print();
                }else if(choice ==5){
                    break;
                }
            }
        }
        // void MaxHeapInterface();
        // void MinHeapInterface();
};

int main(){
    Controller app;
    app.start();
    return 0;
}