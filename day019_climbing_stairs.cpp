#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
int climbstaires(int n){
    if(n<=2){
        int prev2=1;
        int  prev1=1;
        for(int i=3;i>=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
    }
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1; 
        int prev1 = 2; 

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
            prev1=curr;
            
        }

        return prev1;
    }
};
class climestar(int n){
    if()
}

int main() {
    Solution sol;

    int n1 = 2;
    cout << "n = " << n1 << " -> " << sol.climbStairs(n1) << " ways" << endl; 

    int n2 = 3;
    cout << "n = " << n2 << " -> " << sol.climbStairs(n2) << " ways" << endl;

    int n3 = 5;
    cout << "n = " << n3 << " -> " << sol.climbStairs(n3) << " ways" << endl; 

    return 0;
}
