#include <bits/stdc++.h>

class Solution {
private:
    char solve(int n, int k) {
        if (n == 1 || k == 1)
            return '0';
        if (n == 2 && (k == 2 || k == 3))
            return '1';
        
        int mid = 1 + (int)((pow(2.0, n) - 1) / 2);

        if (k < mid) {
            return solve(n-1, k);
        }else if (k == mid) {
            return '1';
        }else if (k == mid + (int)(pow(2, n-2))) {
            return '0';
        } else {
            return solve(n-1, k - mid);
        }
    }
public:
    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};

int main() {
    Solution s;
    //0111001
    char res =s.findKthBit(3, 7); 
    cout<<res;
}