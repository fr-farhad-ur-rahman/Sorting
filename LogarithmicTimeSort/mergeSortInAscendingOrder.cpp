#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int aN = mid - low + 1;
    int bN = high - mid;

    int array1[aN], array2[bN];

    for(int i = 0; i < aN; i++){
        array1[i] = arr[i + low];
    }

    for(int i = 0; i < bN; i++){
        array2[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = low;

    while(i < aN && j < bN){
        if(array1[i] < array2[j]){
            arr[k++] = array1[i++];
        }
        else{
            arr[k++] = array2[j++];
        }
    }
    while(i < aN){
        arr[k++] = array1[i++];
    }
    while(j < bN){
        arr[k++] = array2[j++];
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
    cout << "Enter number of arrays: " << endl;
    int n; cin >> n;

    int arr[n];
    cout << "Enter array elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Before calling merge sort in ascending order: " << endl;
    display(arr, n);
    
    cout << "after calling merge sort in ascending order: " << endl;
    mergeSort(arr, 0, n - 1);

    display(arr, n);
    return 0;
}
