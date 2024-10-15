#include <bits/stdc++.h>

class Solution {
public:
    long long minimumSteps(string s) {
        int lastZeroIndx = -1;
        long long res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '0') {
                res += i - lastZeroIndx - 1;
                lastZeroIndx++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.minimumSteps("0111");
}