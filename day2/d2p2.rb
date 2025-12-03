require 'set'

class LoadInput
    class << self
        def load
            filename = "input.txt"
            lines = File.read(filename)
            lines.split(",")
        end
    end
end


class Validate
    class << self
        def repeated?(num)
            str_num = num.to_s
            
            str_len = str_num.length

            return false if str_len < 2

            divisors = Set.new([1])
            for i in 2...(str_len-1)
                if str_len % i == 0
                    divisors.add(i)
                end
            end

            # Compute every possible repeating substring.
            substrings = []
            divisors.each do |divisor|
                substrings.push(str_num[0...divisor])
            end

            substrings.each do |substring|
                return true if str_num.gsub(substring, "").length == 0
            end

            false
        end
    end
end


class Solve    
    def answer
        sum = 0
        lines = LoadInput.load
        lines.each do |line|
            start_finish = line.split("-")
            start = start_finish[0].to_i
            finish = start_finish[1].to_i

            for i in start..finish
                if Validate.repeated?(i)
                    sum += i.to_i
                end
            end
        end
        puts sum
    end
end

ans = Solve.new
ans.answer
