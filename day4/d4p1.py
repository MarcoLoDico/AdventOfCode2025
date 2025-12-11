def main():
    with open('input.txt', 'r') as f:
        input_text = f.read()
    input_text = [line.strip() for line in input_text.split('\n') if line.strip()]
    text = [list(row) for row in input_text]

    rolls = 0
    
    for i in range(len(text)):
        for j in range(len(text[i])):
            if text[i][j] == '.':
                continue

            count = 0

            # Check to the left
            if j > 0:
                # left side
                if text[i][j - 1] != '.':
                    count += 1

                # Left top corner
                if i > 0:
                    if text[i - 1][j - 1] != '.':
                        count += 1

                # Left bottom corner
                if i < len(text) - 1:
                    if text[i + 1][j - 1] != '.':
                        count += 1

            # Check to the top
            if i > 0:
                if text[i - 1][j] != '.':
                    count += 1

            # Check to the right
            if j < len(text[i]) - 1:
                # right side
                if text[i][j + 1] != '.':
                    count += 1

                # Right top corner
                if i > 0:     
                    if text[i - 1][j + 1] != '.':
                        count += 1

                # Right bottom corner
                if i < len(text[i]) - 1:
                    if text[i + 1][j + 1] != '.':
                        count += 1
            
            # Check to the bottom
            if i < len(text) - 1:
                if text[i + 1][j] != '.':
                    count += 1

            if count < 4:
                text[i][j] = 'x'
                rolls += 1

    nice_output = '\n'.join(''.join(row) for row in text)
    print(nice_output)
    print(rolls)

if __name__ == '__main__':
    main()

