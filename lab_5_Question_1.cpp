#include <iostream>
#include <stack>
#include<algorithm>

using namespace std;

class Furqan_lab05{
public:
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);
    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();
        int p = partition(arr, low, high);
        if (p - 1 > low) {
            s.push(low);
            s.push(p - 1);
        }
        if (p + 1 < high) {
            s.push(p + 1);
            s.push(high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
int main() {
    Furqan_lab05 obj;
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    obj.printArray(arr, n);

    return 0;
}