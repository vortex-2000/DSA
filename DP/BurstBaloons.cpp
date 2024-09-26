//Problem link: https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int worker(vector<int>& nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        
        int ans = INT_MIN;

        if(dp[i][j]>-1)
            return dp[i][j];

        for(int k=i; k<=j;k++)
        {
           int s = nums[i-1] * nums[k] * nums[j+1] 
           + worker(nums,i,k-1,dp) + worker(nums,k+1,j,dp);

           ans = max(s,ans);
        }
        dp[i][j] = ans;
        return ans;
    }

    int maxCoins(vector<int>& vec) {
        int n = vec.size();
        vec.insert(vec.begin(), 1);
        vec.push_back(1);

        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

        return worker(vec,1,n,dp);
    }
};