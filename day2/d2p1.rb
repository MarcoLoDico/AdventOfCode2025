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
            half_length = str_num.length / 2
            if str_num.length % 2 == 0 && str_num[0 ... half_length] == str_num[half_length .. half_length * 2]
                true
            else
                false
            end
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
                    puts i
                    sum += i.to_i
                end
            end
        end
        puts sum
    end
end

ans = Solve.new
ans.answer