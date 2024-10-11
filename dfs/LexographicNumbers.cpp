#include<bits/stdc++.h>

class Solution {
private:
    void dfs(int start, int end, vector<int> &res,
    int n) {
        if(start > n)
            return;
        for (int i = start; i<=end && i<=n; i++)
        {
            res.emplace_back(i);
            dfs(i*10, i*10+9, res, n);
        }
    }
public:
    // vector<int> lexicalOrder(int n) {
    //     vector<int> res;
    //     dfs(1, 9, res, n);
    //     return res;
    // }
    vector<int> lexicalOrder(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int indx = 1, i = 0, ele = 1;
        while (indx < n) {
            int tmp = ele * 10;
            cout<<"Tmp "<<tmp<<endl;
            for (int k = tmp; k <= n && k <= (tmp+9); k++)
            {
                res[indx++] = k;
                cout<<k<<" ";
            }
            ele ++;
            res[indx++] = ele;
            cout<<endl;
        }
        return res;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    int n;
    cin>>n;
    cout<<n<<endl;
    auto res = s.lexicalOrder(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}