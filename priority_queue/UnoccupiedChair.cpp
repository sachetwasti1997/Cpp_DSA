#include <bits/stdc++.h>

struct Member {
    int memberNum;
    int chairNum;
    int incoming;
    int leaving;
};

class Solution {
private:
    int mergeChairs(vector<vector<int>>& times, int target) {
        for (int i=0; i<times.size(); i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end(), [ ](auto & lhs, auto & rhs) {
            return lhs[0] < rhs[0];
        });
        stack<Member> memberStk;
        vector<int> memberPosition(times.size(), 0);
        int chairNm = 0;
        for (int i=0; i<times.size(); i++) {
            if (!memberStk.empty() && memberStk.top().leaving <= times[i][0]) {
                int num = 0;
                while (!memberStk.empty() && memberStk.top().leaving <= times[i][0]) {
                    num = memberStk.top().chairNum;
                    memberStk.pop();
                }
                Member m{times[i][2], num, times[i][0], times[i][1]};
                memberPosition[times[i][2]] = num;
                memberStk.push(m);
            }else {
                Member m {times[i][2], chairNm, times[i][0], times[i][1]};
                memberPosition[times[i][2]] = chairNm++;
                memberStk.push(m);
            }
        }
        return memberPosition[target];
    }
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        auto target = times[targetFriend];
        return mergeChairs(times, targetFriend);

    }
};

class UnoccupiedChairs {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0; i<times.size(); i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for(int i=0; i<times.size(); i++) {
            availableChairs.push(i);
        }
        int currentPos = 0;
        int res[times.size()];
        for(auto& i: times) {
            while (!pq.empty() && i[0] >= pq.top().first) {
                availableChairs.push(pq.top().second);
                pq.pop();
            }
            int chairNm = availableChairs.top();
            pair<int, int> p = {i[1], chairNm};
            pq.push(p);
            availableChairs.pop();

            if (i[2] == targetFriend) {
                return chairNm;
            }
        }
        return -1;
    }
};

int main() {
    UnoccupiedChairs s;
    vector<vector<int>> times = {
        {33889,98676},
        {80071,89737},
        {44118,52565}, 
        {52992,84310}, 
        {78492,88209}, 
        {21695,67063},
        {84622,95452}, 
        {98048,98856}, 
        {98411,99433}, 
        {55333,56548}, 
        {65375,88566}, 
        {55011,62821}, 
        {48548,48656}, 
        {87396,94825},
        {55273,81868}, 
        {75629,91467}
    };
    // vector<vector<int>> times = {{1,4},{2,3},{4,6}};
    // vector<vector<int>> times = {{3,10},{1,5},{2,6}};
    cout<<s.smallestChair(times, 3)<<endl;
}