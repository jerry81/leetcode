
struct Compare {
 public:
  const vector<int>& conv;  // Use a reference to avoid copying

  Compare(const vector<int>& c) : conv(c) {}

  bool operator()(int a, int b) const { return conv[a] < conv[b]; }
};

class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<int> converted;
    converted.reserve(nums.size()); // Reserve memory for converted vector

    vector<int> sorted_indexes(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      sorted_indexes[i] = i;
    }

    // Convert each number in nums using the mapping
    for (int num : nums) {
      int mapped_num = 0;
      int multiplier = 1;
      int temp = num;

      // Convert number directly using the mapping
      while (temp > 0) {
        int digit = temp % 10;
        mapped_num = mapped_num + (mapping[digit] * multiplier);
        multiplier *= 10;
        temp /= 10;
      }

      if (num == 0) {  // Handle the case when num is 0
        mapped_num = mapping[0];
      }

      converted.push_back(mapped_num);
    }

    // Sort the indices based on the converted values
    sort(sorted_indexes.begin(), sorted_indexes.end(), Compare(converted));

    // Construct the result using the sorted indices
    vector<int> res;
    res.reserve(nums.size()); // Reserve memory for the result vector
    for (int i : sorted_indexes) {
      res.push_back(nums[i]);
    }

    return res;
  }
};