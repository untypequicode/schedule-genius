change_list = []

with open("change_occ.csv", "r") as f:
    for groupe in f.read().split("exit"):
        change_list.append([])
        for line in groupe.split("\n"):
            if len(line) > 0:
                if line[0] != "#":
                    line = line.replace("\n", "")
                    change_list[-1].append([])
                    split = line.split(",")
                    for i in split:
                        if i != "":
                            change_list[-1][-1].append(i)
                    if change_list[-1][-1] == []:
                        change_list[-1].pop(-1)

for groupe in change_list:
    path = input(f'Nom du dossier des fichiers pour {groupe[0][0]} : ')
    with open(path + groupe[0][0], "r") as f:
        lignes = f.readlines()
        if len(groupe[-1]) == 1:
            last_index = -1
        elif len(groupe[-1]) > 1:
            last_index = len(groupe)
        for fichier in groupe[1:last_index]:
            print(fichier[0], end=" ")
            with open(path + fichier[0], "w") as g:
                for line in lignes:
                    for i in range(1, len(fichier)):
                        line = line.replace(groupe[0][i], fichier[i])
                    g.write(line)
                    print(".", end="")
            print()
    if len(groupe[-1]) == 1:
        with open(path + groupe[-1][0] + ".h", "r") as f:
            text = f.read().split("/* SPLIT */")
            with open(path + groupe[-1][0] + ".h", "w") as g:
                g.write(text[0])
                g.write("/* SPLIT */")
                g.write(text[1])
                g.write("/* SPLIT */")

                lignes = text[1].split("\n")
                if len(groupe[-1]) == 1:
                    last_index = -1
                elif len(groupe[-1]) > 1:
                    last_index = len(groupe)
                for fichier in groupe[1:last_index]:
                    print(fichier[0], end=" ")
                    for line in lignes:
                        for i in range(1, len(fichier)):
                            line = line.replace(groupe[0][i], fichier[i])
                        g.write(line + "\n")
                        print(".", end="")
                    print()

                g.write("/* SPLIT */")
                g.write(text[3])
    elif len(groupe[-1]) > 1:
        h_file = input("Nom du fichier .h (sans le .h) : ")
        h_path = input("Chemin du fichier .h : ")
        split_location = ""
        while split_location != "1" and split_location != "2":
            split_location = input("Emplacement du split dans le fichier .h (1 ou 2): ")
        split_location = int(split_location)
        h_name = fichier[0].replace(".cpp", ".h").replace(h_file, "")
        h_name_exclude = input("Partie à exclure du nom du fichier .h (séparé par ' ') : ")
        for i in h_name_exclude.split(" "):
            h_name = h_name.replace(i, "")
        while h_name[0] == "_":
            h_name = h_name[1:]
        with open(path + h_file + ".h", "r") as f:
            text = f.read().split("/* SPLIT */")
            if len(groupe[-1]) == 1:
                last_index = -1
            elif len(groupe[-1]) > 1:
                last_index = len(groupe)
            for fichier in groupe[1:last_index]:
                with open(h_path + h_name, "r") as g:
                    text_h = g.read().split("/* SPLIT */")
                    with open(h_path + h_name, "w") as h:
                        h.write(text_h[0])
                        h.write("/* SPLIT */")
                        if split_location == 2:
                            h.write(text_h[1])
                            h.write("/* SPLIT */")

                        lignes = text[split_location].split("\n")
                        print(fichier[0], end=" ")
                        for line in lignes:
                            for i in range(1, len(fichier)):
                                line = line.replace(groupe[0][i], fichier[i])
                            h.write(line + "\n")
                            print(".", end="")

                        if split_location == 1:
                            h.write(text_h[2])
                            h.write("/* SPLIT */")
                        h.write("/* SPLIT */")
                        h.write(text[3])
                print()




print()

print("Fin du programme")