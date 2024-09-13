#include<iostream>
using namespace std;
 bool targetFinder(int arr[][4],int row,int col,int target){
    if(row==0 || col==0){return false;}
    int l=0;
    int r=row*col-1;
    while(l<=r){
        int mid = l + (r - l) / 2;
        int value = arr[mid / col][mid % col];

        if (value == target) {
            return true;
        } 
        else if (value < target) {
            l = mid + 1;
        }
         else {
            r = mid - 1;
        }
    }
        return false;}
int main(){
    int arr1[3][4] = {{1, 3, 5, 7},
                     {10, 11, 16, 20},
                     {23, 30, 34, 60}};
    bool is_present=targetFinder(arr1,3,4,3);
    if(is_present){cout<<"True";
    }
    else{cout<<"False";
    }
    return 0;
}