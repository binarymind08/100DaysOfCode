class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> segments;
        backtrack(s, 0, segments, result);
        return result;
    }
private:
    bool isValidSegment(const string& seg) {
        if (seg.empty() || seg.size() > 3) return false;
        if (seg.size() > 1 && seg[0] == '0') return false;
        int value = stoi(seg);
        return value >= 0 && value <= 255;
    }

    void backtrack(const string& s, int start, vector<string>& segments, vector<string>& result) {
        int remainingSegments = 4 - (int)segments.size();
        int remainingChars = (int)s.size() - start;
        if (remainingChars < remainingSegments || remainingChars > remainingSegments * 3) return;

        if (segments.size() == 4) {
            if (start == (int)s.size()) {
                result.push_back(segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3]);
            }
            return;
        }

        for (int len = 1; len <= 3 && start + len <= (int)s.size(); ++len) {
            string seg = s.substr(start, len);
            if (!isValidSegment(seg)) continue;
            segments.push_back(seg);
            backtrack(s, start + len, segments, result);
            segments.pop_back();
        }
    }
};
