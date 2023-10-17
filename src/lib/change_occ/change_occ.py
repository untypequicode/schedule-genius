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
    path = input(f'Nom du dossier des fichiers pour {groupe[0][0]} : ')
    with open(path + groupe[0][0]) as f:
        lignes = f.readlines()
        for fichier in groupe[1:]:
            print(fichier[0], end=" ")
            with open(path + fichier[0], "w") as g:
                for line in lignes:
                    for i in range(1, len(groupe[0])):
                        line = line.replace(groupe[0][i], fichier[i])
                    g.write(line)
                    print(".", end="")
            print()
    print()

print("Fin du programme")