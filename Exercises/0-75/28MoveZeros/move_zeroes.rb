# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
    a = []
    b = []
    nums.each do |n|
      if n == 0
        b.push(0)
      else
        a.push(n)
      end
    end
    a.concat(b)
    a.each_with_index do |v,i|
        nums[i] = v
    end
end

nums = [0,1,0,3,12]
exp = [1,3,12,0,0]
move_zeroes(nums)
puts "expect #{exp} #{nums}"

nums = [0]
exp = [0]
move_zeroes(nums)
puts "expect #{exp} #{nums}"

nums = [0,0,1]
exp = [1,0,0]
move_zeroes(nums)
puts "expect #{exp} #{nums}"