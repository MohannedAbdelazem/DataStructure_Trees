#include <bits/stdc++.h>
using namespace std;


// int get_min(int left , int right){
//     if(left < right){
//         return left;
//     }
//     return right;
// }

void heapify_min(int arr[], int n, int i){
    int smallest = i;
    int left = i*2+1;
    int right = i*2+2;
    // int min_lr = get_min(arr[left], arr[right]);
    // if((min_lr < n) && arr[min_lr] < arr[smallest]){

    // }
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}

void minHeapSort(int arr[], int n){
    for(int i = n/2-1;i>=0;i--){
        heapify_min(arr, n , i);
    }
    for(int i = n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify_min(arr, n, 0);
    }
}
int main(){
    int arr[4] = {9, 8, 7, 6};
    minHeapSort(arr, 4);

    for(int i = 0; i <4;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
