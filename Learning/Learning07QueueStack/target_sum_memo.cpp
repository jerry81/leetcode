class Solution {
public:


    int solve(int i,int target,vector<int>& nums,vector<vector<int>>& dp)
    {


        if(i<0)
        {
            if(target==0)
                return 1;
            else
                return 0;
        }

        if(dp[i][target+2000]!=-1)
            return dp[i][target+2000]; // feels like there is lots of unused space

        //+1

        // do this if not memoized

        int pos=solve(i-1,target-nums[i],nums,dp); // this is like mine



        //-1

        int neg=solve(i-1,target+nums[i],nums,dp);

      return   dp[i][target+2000]=pos+neg;

    }




    int findTargetSumWays(vector<int>& nums, int target) {


        int n=nums.size();


        vector<vector<int>> dp(n+1,vector<int> (40001,-1)); // memo is a vector of int vectors...
        // initialize them to -1


        return solve(n-1,target,nums,dp); // start the recursion
    }
};