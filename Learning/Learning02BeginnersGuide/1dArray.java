class Solution {
    public int[] runningSum(int[] nums) {
        int[] res = new int[nums.length];
        int sum = 0;
        for (int i=0; i < nums.length; i++) {
          int cur = nums[i];
          res[i] = cur + sum;
          sum+=cur;
        }
        return res;
    }
}