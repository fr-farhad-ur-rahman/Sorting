#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int j = i;

        while(j > 0 && arr[j - 1] < arr[j]){
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
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
    insertionSort(arr, n);

    display(arr, n);
    return 0;
}
