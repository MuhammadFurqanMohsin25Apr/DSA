#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Furqan_lab05{
public:
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int csize = 1; csize <= n - 1; csize = 2 * csize) {
        for (int lstart = 0; lstart < n - 1; lstart += 2 * csize) {
            int mid = min(lstart + csize - 1, n - 1);
            int rstart = min(lstart + 2 * csize - 1, n - 1);
            merge(arr, lstart, mid, rstart);
        }
    }
}
};
int main() {
    Furqan_lab05 obj;
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    obj.mergeSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}