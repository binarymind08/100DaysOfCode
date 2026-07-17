#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); 
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
int main() {
    Solution sol;

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Input: coins = [1,2,5], amount = 11" << endl;
    cout << "Output: " << sol.coinChange(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "\nInput: coins = [2], amount = 3" << endl;
    cout << "Output: " << sol.coinChange(coins2, amount2) << endl;

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "\nInput: coins = [1], amount = 0" << endl;
    cout << "Output: " << sol.coinChange(coins3, amount3) << endl; 
    return 0;
}
