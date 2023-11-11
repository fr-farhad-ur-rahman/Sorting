#include <iostream>
using namespace std;
// 7 9 3 2 6

int partition(int arr[], int first, int last){
    int pivot = arr[last];

    int pivot_index = first - 1;
    int itr = first;

    while(itr < last){
        if(arr[itr] < pivot){
            pivot_index++;
            swap(arr[itr], arr[pivot_index]);
        }
        itr++;
    }
    swap(arr[pivot_index + 1], arr[last]);
    return pivot_index + 1;
}

void quickSort(int arr[], int first, int last){
    if(first >= last) return;

    int pivot = partition(arr, first, last);

    quickSort(arr, first, pivot - 1);
    quickSort(arr, pivot + 1, last);
}

int main(){
    int arr[] = {7, 9, 3, 2, 6};
    quickSort(arr, 0, 4);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}