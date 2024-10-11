#include<bits/stdc++.h>

class Solution {
private:
    int dfsFindSubTree(int current, int n) {
        int nodes = 0;
        int neighbour = current + 1;
        while (current <= n) {
            nodes += min(n+1, neighbour) - current;
            current *= 10;
            neighbour *= 10;
        }
        return nodes;
    }
public:
    int findKthNumber(int n, int k) {
        int current = 1, i = 1;
        while (i < k)
        {
            int nodes = dfsFindSubTree(current, n);
            if (i + nodes <= k) {
                current = current + 1;
                i += nodes;
            }else {
                i += 1;
                current *= 10;
            }
        }
        return current;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

// int n, k;
// cin>>n>>k;
// Solution s;

// cout<<s.findKthNumber(n, k)<<endl;
    cout<<"Printing in the outer files"<<endl;
    vector<int> v(5, 0);
    for (int i = 0; i < 5; i++){
        cin>>v[i];
    }
    cout<<"Inputs from the external files: "<<endl;
    for(int i: v) {
        cout<<i<<" ";
    }
    cout <<endl;
}