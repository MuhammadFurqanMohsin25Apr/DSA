#include <iostream>
using namespace std;
int searchTarget(int arr[],int size,int target){
    int l=0;
    int r=size-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==target){
            return m;
        }
        else if(arr[m]<target){
            l=m+1;
        }else{
            r=m-1;
        }
    }
        return -1;
    
}

int main(){
    int nums[] = {-1, 0, 3, 5, 9, 12};
int size = sizeof(nums) / sizeof(nums[0]); 
int target1 = 9;
int target2 = 2;
int result1 = searchTarget(nums, size, target1);
int result2 = searchTarget(nums, size, target2);
cout<<"Index of "<<target1<<" is "<<result1<<endl;
cout<<"Index of "<<target2<<" is "<<result2;
    return 0;
}