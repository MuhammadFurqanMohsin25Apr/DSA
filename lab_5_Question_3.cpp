#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Furqan_lab05{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.size() == 0) {
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        for (auto it : intervals) {
            if (it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]);
            } else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};

int main() {
    Furqan_lab05 obj;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = obj.merge(intervals);
    for (auto it : mergedIntervals) {
        cout << "[" << it[0] << ", " << it[1] << "]" << endl;
    }
    return 0;
}
