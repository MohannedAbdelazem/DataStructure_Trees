#include <iostream>
#include "./BinarySearchTree.cpp"
#include <vector>
using namespace std;


class Main{
    private:
    vector<student> students;
    public:
     void BinarySearchTreeInterface();
     void AVLInterface();
     void MaxHeapInterface();
     void MinHeapInterface();
    Main(){
        while(1){
            // Add students to the vector
            string path = "./file.txt";
            string line;
            ifstream file(path);
            if(file.is_open()){
                getline(file, line);
                int n = stoi(line);
                    for(int i = 0;i< n;i++){
                        int id;
                        string name;
                        double gpa;
                        string department;
                        for(int j = 0;j<4;j++){
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
                                cout << "Impossible.... I must've made a mistake" << endl;
                                break;
                            }
                  }
                        student st(id, name, gpa, department);
                        students.push_back(st);
                }
            }
            //Main App
            a:cout << "Welcome to our dataStructure Application" << endl;
            cout << "Please choose one of the DataStructures: " << endl;
            cout << "1. BST" << endl;
            cout << "2. AVL" << endl;
            cout << "3. Min heap" << endl;
            cout << "4. Max heap" << endl;
            cout << "5. Exit program" << endl;
            int choice;
            cin >> choice;
            switch(choice){
                case 1:
                    BinarySearchTreeInterface();
                    break;
                case 2:
                    AVLInterface();
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
                    cout << "Invalid entry.... please enter a valid entry" << endl;
                    goto a;
                    break;
            }
        }
    }

    void printStudents(){
        for(auto student: students){
            cout << "ID << " << student.getID() << endl;
            cout << "Name << " << student.getName() << endl;
            cout << "GPA << " << student.getGPA() << endl;
            cout << "Department << " << student.getDepartment() << endl;
        }
    }
};

int main(){
    Main st;
    return 0;
}