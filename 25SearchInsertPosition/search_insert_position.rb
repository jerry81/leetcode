# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)
    head = 0
    tail = nums.size 
    mid = ((tail + head) / 2).to_i
    puts "mid is #{mid}"
    while (tail - head) > 1
      mid = ((tail + head) / 2).to_i
      # puts "mid is now #{mid}"
      if nums[mid] > target
          puts "nums[mid] #{nums[mid]} target #{target} num > target #{nums[mid] > target}"
          tail = mid 
      elsif nums[mid] == target 
          return mid 
      else
          head = mid
      end
    end
    suba = nums[head..tail]
    suba.each_with_index do |x,i| 
        if x > target
            return head+i
        end
    end
    head+1
end

nums = [1,3,5,6]
target = 5
output = 2
puts "expect #{output} #{search_insert(nums,target)}"

nums = [1,3,5,6]
target = 2
output = 1
puts "expect #{output} #{search_insert(nums,target)}"

nums = [1,3,5,6]
target = 7
output = 4
puts "expect #{output} #{search_insert(nums,target)}"