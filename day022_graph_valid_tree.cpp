#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false;

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]]; 
                x = parent[x];
            }
            return x;
        };

        for (auto& edge : edges) {
            int rootA = find(edge[0]);
            int rootB = find(edge[1]);

            if (rootA == rootB) return false;

            parent[rootA] = rootB;
        }

        return true;
    }
};
