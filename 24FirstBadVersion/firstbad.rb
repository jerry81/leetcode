# The is_bad_version API is already defined for you.
# @param {Integer} version
# @return {boolean} whether the version is bad
def is_bad_version(version)
    version == 4
end

# @param {Integer} n
# @return {Integer}
def first_bad_version(n)
    if n == 1
        return n
    end
    low = 0
    high = n 
    mid = -1
    while (high-low) > 1
      mid = ((low + high)/2).to_i
      is_bad = is_bad_version(mid)
      if is_bad
          high = mid 
      else 
          low = mid 
      end
    end
    mid
end

n = 5
output = 4
puts "expect #{output} #{first_bad_version(n)}"
n = 1
output = 1
puts "expect #{output} #{first_bad_version(n)}"