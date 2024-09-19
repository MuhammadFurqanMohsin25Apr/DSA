#include<iostream>
#include<vector>
using namespace std;

class Furqan_lab4 {
public:
    void reverse(vector<int> &arr, int s, int e) {
        while (s < e) {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int maxind = 0;
            for (int j = 1; j <= i; j++) {
                if (arr[j] > arr[maxind]) {
                    maxind = j;
                }
            }
            if (maxind != i) {
                reverse(arr, 0, maxind);
                ans.push_back(maxind + 1);
                reverse(arr, 0, i);
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {3, 2, 4, 1};
    Furqan_lab4 obj;
    vector<int> ans = obj.pancakeSort(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
