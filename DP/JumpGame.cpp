//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool worker(vector<int>& nums, int i,vector<int>&dp)
    {
        if(i > nums.size())
            return false;

        if(i == nums.size()-1)
            return true;
        
        if(dp[i] > -1) return dp[i];
        
        for(int j=1;j<=nums[i];j++)
        {
            if(worker(nums,i+j,dp))
                return true;
        }

        dp[i] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return worker(nums,0,dp);
    }
};

//Approach 2

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int n = nums.size();
        dp[n - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {

            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size() && dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};