#include <iostream>
#include <fstream>
using namespace std;
class student{
    private:
    int id;
    string name;
    double gpa;
    string department;
    public:
    student(){
        id = 0;
        name = "";
        gpa = 0;
        department = "";
    }
    student(int id, string name, double gpa, string department){
        this->id = id;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }
    void setStudent(student stud){
        this->id = stud.getID();
        this->name = stud.getName();
        this->department = stud.getDepartment();
        this->gpa = stud.getGPA();
    }
    int getID(){
        return id;
    }
    void setID(int id){
        this->id = id;
    }
    string getName(){
        return name;
    }
    void setID(string name){
        this->name = name;
    }
    double getGPA(){
        return gpa;
    }
    void setGPA(double gpa){
        this->gpa = gpa;
    }
    string getDepartment(){
        return department;
    }
    void setDepartment(string department){
        this->department = department;
    }
    void print(){
        cout << "Student ID: " << this->id << endl;
        cout << "Student Name: " << this->name << endl;
        cout << "Student gpa: " << this->gpa << endl;
        cout << "Student department: " << this->department << endl;
    }
};