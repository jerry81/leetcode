
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mod_count;
        mod_count[0] = 1;  // to handle the case where the prefix sum itself is divisible by k
        int sum = 0;
        int res = 0;

        for (int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k;  // handle negative mods
            if (mod_count.find(mod) != mod_count.end()) {
                res += mod_count[mod];
            }
            mod_count[mod]++;
        }

        return res;
    }
};