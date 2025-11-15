#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>> 
        > pq;

        for (int i = 0; i < n; i++)
            pq.push({matrix[i][0], {i, 0}});

        while (--k) {
            auto top = pq.top(); 
            pq.pop();
            int r = top.second.first;
            int c = top.second.second;
            if (c + 1 < n)
                pq.push({matrix[r][c+1], {r, c+1}});
        }

        return pq.top().first;
    }
};