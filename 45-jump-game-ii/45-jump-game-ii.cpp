class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            int k=nums[i],c=1;
            while(i+c<nums.size() && c<=k)
            {
                dp[i+c]=min(dp[i+c],dp[i]+1);
                c++;
            }
        }
        return dp[nums.size()-1];
    }
};