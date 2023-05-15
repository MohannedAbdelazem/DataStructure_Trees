#ifndef HEAP_H
#define HEAP_H
#include "Student.h"
#include <vector>
#include <iostream>
using namespace std;
class HeapSort{
    private:
        vector<Student> st;
        void swap(Student &gpa1, Student &gpa2);
        void heapifyMin(int n, int i);
        void heapsortMin();
        void heapifyMax(int n, int i);
        void heapsortMax();
    public:
        void insert(Student s);
        void printMin();
        void printMax();
};
#endif