# @param {Integer[]} nums
# @return {Integer[]}
def search_insert(nums, target)
    if nums.size == 0
        return 0 
    end
    if nums.size == 1
        if nums[0] >= target 
            return 0
        else 
            return 1
        end
    end
    head = 0
    tail = nums.size 
    while (tail - head) > 1
      mid = ((tail + head) / 2).to_i
      # puts "mid is now #{mid}"
      if nums[mid] > target
          tail = mid 
      elsif nums[mid] == target 
          return mid 
      else
          head = mid
      end
    end
    suba = nums[head..tail]
    suba.each_with_index do |x,i| 
        if x == target 
            return head 
        end
        if x > target
            return head+i
        end
    end
    head+1
end

def sorted_squares(nums)
    nums.map do |x|
        x**2 
    end.sort
end

def sorted_squares_fail(nums)
    if nums.size == 1
        return nums.map do |n|
            n**2 
        end
    end
    ins = search_insert(nums, 0)
    neg = []
    pos = []
    
    ins-=1

    neg = nums[..ins]
    pos = nums[ins+1..]
    neg.each do |n|
        pos.insert(search_insert(pos,n.abs), n.abs)
    end
    pos.map do |p|
        p**2
    end
end

nums = [-4,-1,0,3,10]
output = [0,1,9,16,100]
puts "expect #{output} #{sorted_squares(nums)}"

nums = [-7,-3,2,3,11]
output = [4,9,9,49,121]
puts "expect #{output} #{sorted_squares(nums)}"

nums = [-5,-3,-2,-1]
output = [1,4,9,25]
puts "expect #{output} #{sorted_squares(nums)}"