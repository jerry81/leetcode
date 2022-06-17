# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def rotate(nums, k)
    res = nums.clone

    res.each_with_index do |x,i|
        nums[(i+k) % res.size] = x
    end
    nums
end

nums = [1,2,3,4,5,6,7]
# 0,1,2,3,4,5,6
k = 3
expect = [5,6,7,1,2,3,4]
# 4,5,6,0,1,2,3
puts "expect #{expect} #{rotate(nums,k)}"
puts "nums is now #{nums}"
nums = [-1,-100,3,99] 
k = 2
expect = [3,99,-1,-100]
puts "expect #{expect} #{rotate(nums,k)}"
puts "nums is #{nums}"