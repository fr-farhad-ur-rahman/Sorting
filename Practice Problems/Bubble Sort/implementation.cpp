#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector <int> &v, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j + 1] > v[j])
                swap(v[j + 1], v[j]);
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(vector <int> v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

int main(){
    int n; cin >> n; 
    vector <int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Before sorting: " << endl;
    print(v, n);
    cout << endl;
    cout << "After sorting: " << endl;
    bubbleSort(v, n);
    print(v, n);

    return 0;
}




