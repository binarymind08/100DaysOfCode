#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen; 
    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];

        if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
            left = lastSeen[c] + 1; // shrink window from the left
        }

        lastSeen[c] = right; // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "";

    cout << "Input: " << s1 << " -> Longest: " << lengthOfLongestSubstring(s1) << end;
    cout << "Input: " << s2 << " -> Longest: " << lengthOfLongestSubstring(s2) << endl; 
    cout << "Input: " << s3 << " -> Longest: " << lengthOfLongestSubstring(s3) << endl; 
    cout << "Input: (empty) -> Longest: " << lengthOfLongestSubstring(s4) << endl; 

    return 0;
}
