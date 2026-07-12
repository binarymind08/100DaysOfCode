#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Test 1 (expected order may vary, values {1, 2}): ";
    printVector(sol.topKFrequent(nums1, k1));

    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Test 2 (expected: [1]): ";
    printVector(sol.topKFrequent(nums2, k2));

    vector<int> nums3 = {4, 1, 1, 2, 2, 3, 3, 3};
    int k3 = 2;
    cout << "Test 3 (expected values {3, 1 or 2}): ";
    printVector(sol.topKFrequent(nums3, k3));

    return 0;
}
