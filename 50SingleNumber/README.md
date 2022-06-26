136. Single Number
Easy

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

# Key learning

Use Xor/Bit Manipulation
Intuition:
Xor of any two num gives the difference of bit as 1 and same bit as 0.
Thus, using this we get 1 ^ 1 == 0 because the same numbers have same bits.
So, we will always get the single element because all the same ones will evaluate to 0 and 0^single_number = single_number.
Time: O(n)
Space: O(1)