#include <iostream>
using namespace std;

int partition(int arr[], int first, int last){
    int pivot = arr[last];

    int pIndex = first - 1;
    int itr = first;

    while(itr < last){
        if(arr[itr] >= pivot){
            pIndex++;
            swap(arr[pIndex], arr[itr]);
        }
        itr++;
    }
    swap(arr[pIndex + 1], arr[last]);
    return pIndex + 1;
}

void quickSort(int arr[], int first, int last){
    // base case.
    if(first >= last) return;

    // finding the pivot.
    int pivot = partition(arr, first, last);

    quickSort(arr, first, pivot - 1);
    quickSort(arr, pivot + 1, last);
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter number of arrays: " << endl;
    int n; cin >> n;

    int arr[n];
    cout << "Enter array elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Before calling quick sort in ascending order: " << endl;
    display(arr, n);

    cout << "after calling quick sort in ascending order: " << endl;
    quickSort(arr, 0, n - 1);

    display(arr, n);
    return 0;
}
