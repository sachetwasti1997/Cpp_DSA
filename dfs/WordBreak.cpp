#include<bits/stdc++.h>

class Solution {
private:
    bool segmentWords(string s, vector<vector<optional<bool>>> &arr, int i, int j,
    unordered_set<string> wrds) {
        if(i > j)
            return false;
        if(arr[i][j].has_value())
            return arr[i][j].value();
        if (wrds.find(s.substr(i, j-i+1)) != wrds.end()) {
            return true;
        }
        bool b = false;
        for (int k = i; k <= j; k++)
        {
            if (wrds.find(s.substr(i, k-i+1)) != wrds.end()) {
                b = b || segmentWords(s, arr, k+1, j, wrds);
            }
        }
        arr[i][j] = b;
        return b;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<optional<bool>>> arr(s.length()+1, vector<optional<bool>>(s.length()+1));
        unordered_set<string> wrds;
        for (string i: wordDict)
        {
            wrds.emplace(i);
        }
        return segmentWords(s, arr, 0, s.length() - 1, wrds);
    }
};

int main() {
    Solution s;
    vector<string> wrd {"leet","code"};
    cout<<s.wordBreak("leetscode", wrd)<<endl;
}
