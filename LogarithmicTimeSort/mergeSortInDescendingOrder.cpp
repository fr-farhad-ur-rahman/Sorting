#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int aN = mid - low + 1;
    int bN = high - mid;

    int a[aN], b[bN];

    for(int i = 0; i < aN; i++){
        a[i] = arr[i + low];
    }

    for(int i = 0; i < bN; i++){
        b[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = low;

    while(i < aN && j < bN){
        if(a[i] > b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i < aN){
        arr[k++] = a[i++];
    }
    while(j < bN){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter number of array elements: " << endl;
    int n; cin >> n;
    cout << "Enter arrays: " << endl;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Before calling merge sort: " << endl;
    display(arr, n);
    cout << "After calling merge sort: " << endl;
    mergeSort(arr, 0, n - 1);
    display(arr, n);
    return 0;
}