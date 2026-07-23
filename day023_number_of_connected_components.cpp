#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]]; 
                x = parent[x];
            }
            
            return x;
        };

        int components = n; 

        for (auto& edge : edges) {
            int rootA = find(edge[0]);
            int rootB = find(edge[1]);

            if (rootA != rootB) {
                parent[rootA] = rootB;
                components--;
            }
        }

        return components;
    }
};
