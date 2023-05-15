#include "HeapSort.h"
void HeapSort::swap(Student &gpa1, Student &gpa2){
    Student gpa1tmp(gpa1);
    gpa1.setStudent(gpa2);
    gpa2.setStudent(gpa1tmp);
}
void HeapSort::heapifyMin(int n, int i){
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
void HeapSort::heapsortMin(){
    for(int i = st.size()/2-1;i>=0;i--){
        heapifyMin(st.size(), i);
    }
    for(int i = st.size()-1;i>=0;i--){
        swap(st[i], st[0]);
        heapifyMin(i, 0);
    }
}
void HeapSort::heapifyMax(int n, int i){
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
void HeapSort::heapsortMax(){
    for(int i = st.size()/2-1;i>=0;i--){
        heapifyMax(st.size(), i);
    }
    for(int i = st.size()-1;i>=0;i--){
        swap(st[i], st[0]);
        heapifyMax(i, 0);
    }
}
void HeapSort::insert(Student s){
    st.push_back(s);
}
void HeapSort::printMin(){
    cout << "Print " << st.size() << " Students\n";
    heapsortMin();
    for (int i = 0; i < st.size(); i++)
    {
        st[i].print();
        cout << '\n';
    }
}
void HeapSort::printMax(){
    cout << "Print " << st.size() << " Students\n";
    heapsortMax();
    for (int i = 0; i < st.size(); i++)
    {
        st[i].print();
        cout << '\n';
    }
}