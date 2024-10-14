#include<bits/stdc++.h>

class DivideRanges {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> testHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& ranges: intervals) {
            if (!minHeap.empty() && minHeap.top() < ranges[0]) {
                minHeap.pop();
            }
            minHeap.push(ranges[1]);
        }
        cout<<minHeap.size()<<endl;
        for (int i=0; i<minHeap.size(); i++) {
            cout<<minHeap.top()<<" ";
            minHeap.pop();
        }
        return minHeap.size();
    }
};

int main() {
    DivideRanges r;
    vector<vector<int>> vv{{5,10}, {6,8}, {1,5}, {2,3}, {1,10}};
    r.minGroups(vv);
}