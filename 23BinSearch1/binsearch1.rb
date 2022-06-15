# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
    head = 0
    tail = nums.size 
    puts "head is #{head} tail is #{tail}"
    mid = ((tail - head) / 2).to_i
    puts "mid is #{mid}"
    while (tail - head) > 2
      mid = ((tail - head) / 2).to_i
      if nums[mid] > target
          tail = mid - 1 
      elsif nums[mid] == target 
          return mid 
      else
          head = mid + 1
      end
    end
    puts "nums is #{nums}"
    suba = nums[head..tail]
    puts "suba is #{suba}"
    suba.each_with_index do |x,i| 
        puts "num #{suba[x]} target #{target}"
        if x == target
            return head+i
        end
    end
    -1
end

nums = [-1,0,3,5,9,12]
target = 9
output = 4
puts "expect #{output} #{search(nums,target)}"

nums = [-1,0,3,5,9,12]
target = 2
output = -1
puts "expect #{output} #{search(nums,target)}"