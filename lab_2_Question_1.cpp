#include<iostream>
#include<vector>
using namespace std;

class BinarySearch{
    private:
    vector<vector<int>> arr;
    int rows, cols, target;

    public:
    BinarySearch(vector<vector<int>> arr, int t) : arr(arr), target(t) {
        rows = arr.size();
        cols = arr[0].size();
    }

   
    pair<int, int> binarySearch(){
        int left = 0, right = rows - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            
            if(arr[mid][0] <= target && arr[mid][cols - 1] >= target){
                int l = 0, r = cols - 1;
                
            
                while(l <= r){
                    int m = l + (r - l) / 2;
                    if(arr[mid][m] == target){
                        return {mid, m}; 
                    }
                    else if(arr[mid][m] < target){
                        l = m + 1;
                    }
                    else{
                        r = m - 1;
                    }
                }
                return {-1, -1}; 
            }
            else if(arr[mid][0] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int target = 13;

    BinarySearch bs(arr, target);
    pair<int, int> result = bs.binarySearch();

    if(result.first != -1){
        cout << "Element found at row: " << result.first << " and column: " << result.second << endl;
    }
    else{
        cout << "Element not found" << endl;
    }

    return 0;
}