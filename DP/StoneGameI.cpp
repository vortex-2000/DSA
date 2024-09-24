//Problem link: https://leetcode.com/problems/stone-game-ii/description/?envType=problem-list-v2&envId=50wob6ze

class Solution {
public:
    int worker(int m,bool turn,int curr,vector<int>&piles,vector<vector<vector<int>>>&dp)
    {
        int n = piles.size();
        if(curr>=n)
            return 0;
        
        int op = turn ? INT_MIN : INT_MAX;
        if(dp[m][curr][turn]>-1) return dp[m][curr][turn];
        if(!turn)
        {
            for(int i=1;i<=2*m && curr+i-1<n;i++)
            {
                op = min(op, worker(max(i,m),!turn, curr+i,piles,dp));
            } 
        }
        else
        {
            int s =0;
             for(int i=1;i<=2*m && curr+i-1<n;i++)
            {
                s += piles[curr + i - 1];  // Accumulate the stones taken in this move
                op = max(op,s+ worker(max(i,m),!turn, curr+i,piles,dp));
            } 
        }
        
        dp[m][curr][turn] = op;

        return dp[m][curr][turn];
    }

    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n,vector<int>(2,-1)));
        return worker(1,true,0,piles,dp);
    }
};