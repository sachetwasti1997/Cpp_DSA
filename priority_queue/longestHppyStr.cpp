#include <bits/stdc++.h>

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0)maxHeap.push({a, 'a'});
        if (b > 0)maxHeap.push({b, 'b'});
        if (c > 0)maxHeap.push({c, 'c'});
        while (!maxHeap.empty()) {
            auto charCount = maxHeap.top();
            maxHeap.pop();
            if (res.size() > 1 && res[res.size()-1] == res[res.size()-2] && 
                    res[res.size()-1] == charCount.second) {
                
                if (maxHeap.size() == 0)
                    break;
                auto charCnt2 = maxHeap.top();
                maxHeap.pop();
                charCnt2.first -= 1;
                res += (charCnt2.second);
                if (charCnt2.first > 0) {
                    maxHeap.push(charCnt2);
                }
            }else {
                charCount.first -= 1;
                res += charCount.second;
            }
            if (charCount.first > 0) {
                maxHeap.push(charCount);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.longestDiverseString(7, 1, 0);
}