with open(input('Enter file path of origin file: '), 'r') as f:
    with open(input('Enter file path of new file: '), 'w') as g:
        origine_occ = []
        new_occ = []
        for i in range(int(input('Enter the number of changes you want to make: '))):
            origine_occ.append(input('Enter the original occurence: '))
            new_occ.append(input('Enter the new occurence: '))
        for line in f:
            for i in range(len(origine_occ)):
                line = line.replace(origine_occ[i], new_occ[i])
            g.write(line)