// https://leetcode.com/problems/house-robber/
// instructor's code
/*
class Solution {
public:
    int dp[10000];
    int rec(int n, vector<int>& nums)
    {
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int op1 = nums[n] + rec(n-2, nums);
        int op2 = rec(n-1, nums);
        return dp[n] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sz = nums.size();
        return rec(sz-1, nums);
    }
};
*/