#include<iostream>
using namespace std;
class Furqan_lab4{

public:
 void bubblesort(int arr[], int size) {
    int n=size;
    bool flag=false;
    int swaps=0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
                swaps++;
            }
            if(!flag) {
                break;
            }
        }
    }
    cout<<"Number of swaps: "<<swaps<<endl;
}

};  
int main(){
    Furqan_lab4 obj;
    int arr[]={1,2,3,4,5};
    int n=5;
    obj.bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}




