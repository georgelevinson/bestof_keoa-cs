

with open('dictionary.txt', 'r+') as file:
    lines = file.readlines()
    file.seek(0)

    for line in lines:
        line = line.split("\n")[0]
        if len(line) < 6:
            print(line)
            file.write(line + "\n")
        file.truncate()