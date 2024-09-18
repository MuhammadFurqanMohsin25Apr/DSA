#include<iostream>
#include<ctime>
using namespace std;

class Furqan_lab4 {
public:

void bubblesort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;  
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << "The number of swaps are: " << swaps << endl;
    cout << "The number of comparisons are: " << comparisons << endl;
}

void insertionsort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++; 
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;  
    }
    cout << "The number of swaps are: " << swaps << endl;
    cout << "The number of comparisons are: " << comparisons << endl;
}

void selectionsort(int arr[], int n) {
    int swaps = 0;
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;  
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {  
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
    cout << "The number of swaps are: " << swaps << endl;
    cout << "The number of comparisons are: " << comparisons << endl;
}

};

int main() {
    srand(time(0));
    int n, range;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the range of the elements: ";
    cin >> range;
    int arr[n], carr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
        carr[i] = arr[i];
    }
    
    string algo;
    Furqan_lab4 obj;
    
    for (int i = 0; i < 3; i++) {
        cout << "Enter the choice of algorithm (bubblesort, insertionsort, selectionsort): ";
        cin >> algo;
        
        for (int j = 0; j < n; j++) {
            carr[j] = arr[j];  
        }
        
        if (algo == "bubblesort") {
            obj.bubblesort(carr, n);
        } else if (algo == "insertionsort") {
            obj.insertionsort(carr, n);
        } else if (algo == "selectionsort") {
            obj.selectionsort(carr, n);
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
