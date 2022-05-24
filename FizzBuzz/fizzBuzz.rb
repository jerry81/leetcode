# @param {Integer} n
# @return {String[]}
def fizz_buzz(n)
    res = []
    for i in 1..n
        if i % 3 == 0 && i % 5 == 0
            res << "FizzBuzz"
        elsif i % 3 == 0
            res << "Fizz"
        elsif i % 5 == 0
            res << "Buzz"
        else 
            res << i.to_s
        end
    end
    res
end

puts "#{fizz_buzz(10)}"