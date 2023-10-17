change_list = []

with open("change_occ.csv", "r") as f:
    for groupe in f.read().split("exit"):
        change_list.append([])
        for line in groupe.split("\n"):
            line = line.replace("\n", "")
            change_list[-1].append([])
            split = line.split(",")
            for i in split:
                if i != "":
                    change_list[-1][-1].append(i)
            if change_list[-1][-1] == []:
                change_list[-1].pop(-1)

# print(change_list)

for groupe in change_list:
    # print(groupe)
    path = input(f'Nom du dossier des fichiers pour {groupe[0][0]} : ')
    with open(path + groupe[0][0], "r") as f:
        lignes = f.readlines()
        for fichier in groupe[1:-1]:
            print(fichier[0], end=" ")
            with open(path + fichier[0], "w") as g:
                for line in lignes:
                    for i in range(1, len(groupe[0])):
                        line = line.replace(groupe[0][i], fichier[i])
                    g.write(line)
                    print(".", end="")
            print()
    if len(groupe[-1]) == 1:
        with open(path + groupe[-1][0] + ".h", "r") as f:
            text = f.read().split("/* SPLIT */")
            with open(groupe[-1][0] + ".h", "w") as g:
                g.write(text[0])
                g.write("/* SPLIT */\n")
                g.write(text[1])
                g.write("/* SPLIT */\n")

                lignes = text[1].split("\n")
                for fichier in groupe[1:-1]:
                    print(fichier[0], end=" ")
                    for line in lignes:
                        for i in range(1, len(groupe[0])):
                            line = line.replace(groupe[0][i], fichier[i])
                        # g.write(line + "\n")
                        print(".", end="")
                    print()

                g.write("/* SPLIT */\n")
                g.write(text[3])

print()

print("Fin du programme")