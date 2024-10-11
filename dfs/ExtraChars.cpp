#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define ep emplace_back

struct TrieNode {
    unordered_map<char, TrieNode *> child;
    bool isEnd = false;
};

class Solution {
private:
    void insert(TrieNode* &root, string word) {
        TrieNode* tmp = root;
        for (char i: word) {
            if (tmp->child.find(i) == tmp->child.end()) {
                tmp->child[i] = new TrieNode();
            }
            tmp = tmp->child[i];
        }
        tmp->isEnd = true;
    }

    bool search(TrieNode* &root, string word) {
        auto tmp = root;
        for (char i: word) {
            if (tmp->child.find(i) == tmp->child.end())
                return false;
            tmp = tmp->child[i];    
        }
        return tmp->isEnd;
    }

    bool findPrfx(TrieNode* root, string word) {
        
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {

    }
};

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}