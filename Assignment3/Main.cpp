#include <iostream>
#include "./student.cpp"
#include <vector>
using namespace std;


class Main{
    private:
    vector<student> students;
    public:
    Main(){
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
    st.printStudents();
    return 0;
}