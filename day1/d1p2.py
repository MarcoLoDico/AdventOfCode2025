def main():
    f = open("input.txt", "r")
    dial = 50
    answer = 0
    for line in f:
        line = line.rstrip().replace("\n","")

        if line[0] == 'R':
            for i in range(int(line[1:])):
                dial += 1
                if dial == 100:
                    dial = 0
                if dial == 0:
                    answer += 1
        else:      
            for i in range(int(line[1:])):
                dial -= 1
                if dial == -1:
                    dial = 99
                if dial == 0:
                    answer += 1

    print(answer)


if __name__ == '__main__':
    main()