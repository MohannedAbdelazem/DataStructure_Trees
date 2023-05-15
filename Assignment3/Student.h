#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student{
    private:
        int id;
        string name;
        double gpa;
        string department;
    public:
        Student(){
            id = 0;
            name = "";
            gpa = 0;
            department = "";
        }
        Student(int id, string name, double gpa, string department){
            this->id = id;
            this->name = name;
            this->department = department;
            this->gpa = gpa;
        }
        void setStudent(Student stud){
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
            cout << '[' << id << ", " << name << ", " << gpa << ", " << department << ']';
        }
};
#endif