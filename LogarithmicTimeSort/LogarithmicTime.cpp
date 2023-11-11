#include <bits/stdc++.h>
using namespace std;

// function prototype.
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void quickSort(int arr[], int first, int last);
void partition(int arr[], int first, int last);
void display(int arr[], int n);
void swap(int *a, int *b);

class LogarithmicSort{
public:

    void mergeSort(int arr[], int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);;
    }

    void merge(int arr[], int low, int mid, int high){
        int aN, bN;
        aN = mid - low + 1;
        bN = high - mid;
        int a[aN], b[bN];

        for(int i = 0; i < aN; i++){
            a[i] = arr[low + i];
        }

        for(int j = 0; j < bN; j++){
            b[j] = arr[mid + 1 + j];
        }

        int i = 0; // to keep track of left half of the array
        int j = 0; // to keep track of right half of the array.
        int k = low; // to increment original array.

        while(i < aN && j < bN){
            if(a[i] < b[j]){
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

    void quickSort(int arr[], int first, int last){
        // base case
        if(first >= last) return;
        // finding pivot
        int pivot = partition(arr, first, last);
        // making tree for left elements of pivot
        quickSort(arr, first, pivot - 1);
        // making tree for right elements of pivot.
        quickSort(arr, pivot + 1, last);
    }

    int partition(int arr[], int first, int last){
        int pivot = arr[last];

        int i = first - 1;
        int j = first;

        while(j < last){
            if(arr[j] < pivot){
                i++;
                swapArray(&arr[i], &arr[j]);
            }
            j++;
        }
        swapArray(&arr[i + 1], &arr[last]);
        return i + 1;
    }

    void swapArray(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void display(int arr[], int n){
        cout << "array = {";
        for(int i = 0; i < n; i++){
            cout << arr[i];
            if(i != n - 1){
                cout << " ";
            }
            else{
                cout << "}";
            }
        }
        cout << "\n\n";
    }
};

void menu(){
    cout << "Choose an option: " << endl;
    cout << "press 0 to display current array." << endl;
    cout << "press 1 for merge sort." << endl;
    cout << "press 2 for quick sort." << endl;
    cout << "press -1 to quit the program." << endl;
}

int main(){
    LogarithmicSort log;
    cout << "Enter number of elements: " << endl;
    int n; cin >> n;
    cout << "Enter array elements: " << endl;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while(true){
        menu();
        int options;
        cin >> options;

        if(options < -1 && options > 2){
            cout << "Enter correct options: " << endl;
        }
        else{
            switch(options){
                case 0: log.display(arr, n); break;
                case 1: log.mergeSort(arr, 0, n - 1); 
                cout << "merge sort completed.\n\n"; break;
                case 2: log.quickSort(arr, 0, n - 1); 
                cout << "quick sort completed.\n\n"; break;
                case -1: cout << "program terminated."; return 0;
            }
        }
    }  
    return 0;
}