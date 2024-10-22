#include <bits/stdc++.h>

class Solution {
public:
    int maximumSwap(int num) {
        string nmbr = to_string(num);
        
        for (int k = 0; k < nmbr.size(); k++) {
            char max = nmbr[k];
            int i = k;
            for (int l = k+1; l<nmbr.size(); l++) {
                if (max < nmbr[l]) {
                    max = nmbr[l];
                    i = l;
                }else if (max == nmbr[l] && l > i) {
                    i = l;
                }
            }
            if (i != k && nmbr[i] != nmbr[k]) {
                char tmp = nmbr[k];
                nmbr[k] = nmbr[i];
                nmbr[i] = tmp;
                break;
            }
        }
        
        return stoi(nmbr);
    }
};

int main() {
    Solution s;
    cout<<s.maximumSwap(1993);
}