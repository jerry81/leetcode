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
end

nums = [0,1,0,3,12]
exp = [1,3,12,0,0]
puts "expect #{exp} #{move_zeroes(nums)}"

nums = [0]
exp = [0]
puts "expect #{exp} #{move_zeroes(nums)}"