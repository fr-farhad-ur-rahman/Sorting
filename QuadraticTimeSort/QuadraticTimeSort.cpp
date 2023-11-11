#include <iostream>
#include <vector>
using namespace std;

class SquareTime{    
public:
    void bubble_sort(vector <int>& v, int n){
        for(int i = 0; i < n; i++){
            bool swapped = false;
            for(int j = 0; j < n - 1; j++){
                if(v[j] > v[j + 1]){
                    swap_vector(&v[j], &v[j + 1]);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
    }

    void selection_sort(vector <int>& v, int n){
        for(int i = 0; i < n - 1; i++){
            int mn = i;
            for(int j = i + 1; j < n; j++){
                if(v[j] < v[mn]){
                    mn = j;
                }
            }
            swap_vector(&v[i], &v[mn]);
        }
    }

    void insertion_sort(vector <int>& v, int n){
        for(int i = 0; i < n; i++){
            int j = i;
            while(j > 0 && (v[j - 1] > v[j])){
                swap_vector(&v[j - 1], &v[j]);
                j--;
            }
        }
    }

    void swap_vector(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void display(vector <int>& v, int n){
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    SquareTime sq;
    cout << "Enter number of elements: " << endl;
    int n; cin >> n;
    vector <int> v(n);

    cout << "Enter vector elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    while(true){
        cout << "Enter 0 for display vector elements: " << endl;
        cout << "Enter 1 for bubble sort: " << endl;
        cout << "Enter 2 for selection sort: " << endl;
        cout << "Enter 3 for insertion sort: " << endl;
        cout << "Enter -1 to quit." << endl;
        int options; cin >> options;
        if(!(options >= -1 && options <= 3)){
            cout << "Please enter valid digit." << endl;
        }
        else{
            switch(options){
                case 1: 
                    sq.bubble_sort(v, n);
                    cout << "Bubble sort: " << endl;
                    sq.display(v, n);
                    break;
                case 2: 
                    sq.selection_sort(v, n);
                    cout << "Selection sort: " << endl;
                    sq.display(v, n);
                    break;
                case 3: 
                    sq.insertion_sort(v, n);
                    cout << "Insertion sort: " << endl;
                    sq.display(v, n);
                    break;
            }   
            if(options == -1) break;
        }
    }
    return 0;
}
