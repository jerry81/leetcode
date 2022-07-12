class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        for (int i = 0; i < accounts.length; ++i) {
          int[] acct = accounts[i];
          int sum = 0;
          for (int j = 0; j < acct.length; ++j) {
            int cash = acct[j];
            sum += cash;
          }
          if (sum > max) {
            max = sum;
          }
        }
        return max;
    }
}