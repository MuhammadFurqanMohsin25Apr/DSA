#include<iostream>
using namespace std;
class Furqan_lab4{

public:
 void bubblesort(int arr[], int n) {
    bool flag=false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
            if(!flag) {
                break;
            }
        }
    }
}
void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
};

int main(){
    int arr[]={1,12,5,111,200,1000,10};
    int n=7;
    int k=50;
    Furqan_lab4 obj;
    obj.bubblesort(arr,n);
    int count=0;
    for(int i=0;i<n;i++){
        if(k<arr[i]){
            count++;
            k=k-arr[i];
        }
    }
    cout<<"The number of toys can we buy is "<<count;
    return 0;
}