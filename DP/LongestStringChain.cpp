//Problem link: https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
    static bool sorter(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }

    bool canForm(string& a, string& b) {
        if (b.length() - a.length() != 1) return false;

        int i = 0, j = 0;
        bool found = false;

        while (i < a.length() && j < b.length()) {
            if (a[i] != b[j]) {
                if (found) return false;
                found = true;
                j++;  // Skip one character in the longer string
            } else {
                i++;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), sorter);

        int n = words.size();
        vector<int> dp(n, 1);  // dp[i] will store the longest chain ending at words[i]
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (canForm(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
