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

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n[5];
    for (int i=0; i<5; i++) {
        cin>>n[i];
    }
    for(int i=0; i<5; i++) {
        cout<<n[i]<<" ";
    }
    cout<<endl;
}