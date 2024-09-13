#include <iostream>
using namespace std;

void columnMajorOrder(int arr[][3],int row,int col){
    int arr1[row*col];
    int ind=0;
    for(int i=0;i<col;++i){
        for(int j=0;j<row;++j){
            arr1[ind]=arr[j][i];
            ind++;
        }
    }
    for(int k=0;k<row*col;k++){
            cout<<arr1[k]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[3][3]={{1,2,3},
                 {4,5,6},
                 {7,8,9}};
    cout<<endl;
    cout<<"2D array in Column major order is:"<<endl;
    columnMajorOrder(a,3,3);
    return 0;
}


