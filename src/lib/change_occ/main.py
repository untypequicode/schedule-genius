#from change_occ import FileChangeOcc
from terminal import Terminal
from cd import Cd

def main():
    # file = FileChangeOcc("change_occ.csv")
    # file.GetGroup()
    # for groupe in file.m_group:
    #     print(groupe)

    terminal = Terminal()
    cd = Cd()
    response = terminal.GetInput(cd.GetPath())
    file_load = []

    while response != "exit":
        response = response.split(" ")
        if response[0] == "help":
            with open("help", "r") as help:
                lignes = help.read().split("\n")
                help_content = [[],[]]
                for i in range(len(lignes)):
                    lignes[i] = lignes[i].split(" : ")
                    help_content[0].append(lignes[i][0])
                    help_content[1].append(lignes[i][1])
                terminal.Print(help_content[0],help_content[1])

        elif response[0] == "ls":
            ls_sort = cd.Ls()
            if len(ls_sort["dir"]) >= len(ls_sort["file"]):
                terminal.Print(ls_sort["dir"], ls_sort["file"])
            elif len(ls_sort["file"]) > len(ls_sort["dir"]):
                terminal.Print(ls_sort["file"], ls_sort["dir"])

        elif response[0] == "cd" and len(response) >= 2:
            cd.Cd(response[1])
            if cd.GetPath() == False:
                print(f'Emplacement "{response[1]}" incorrect')

        elif response[0] == "load" and len(response) >= 2:
            if (response[1] == "mount" or response[1] == "mnt") and len(response) >= 3:
                if response[2] == "-a":
                    ls = cd.LsFile()
                    for file in ls:
                        file_load.append(cd.GetPath() + file)
                else:
                    file_path = cd.GetPath() + response[2]
                    if cd.IsFile(file_path):
                        file_load.append(file_path)
                if len(response) >= 5 and response[3] == "\\":
                    for file_unmount in response[4:]:
                        file_path = cd.GetPath() + file_unmount
                        if cd.Exist(file_path) and file_path in file_load :
                            file_load.remove(file_path)
            elif (response[1] == "unmount" or response[1] == "umnt") and len(response) >= 3:
                if response[2] == "-a" and len(response) >= 3:
                    file_load = []
                else:
                    file_path = cd.GetPath() + response[2]
                    if cd.Exist(file_path):
                        file_load.remove(file_path)
                if len(response) >= 5 and response[3] == "\\":
                    for file_mount in response[4:]:
                        file_load.append(cd.GetPath() + file_mount)
            elif response[1] == "list" or response[1] == "ls":
                if len(file_load) == 0:
                    print("Aucun fichier n'est chargé.")
                else:
                    for file in file_load:
                        print(file)

            else:
                print(f'Commande "{response[1]}" inconnue.')





        else:
            print(f'Commande "{response[0]}" inconnue.')

        response = terminal.GetInput(cd.GetPath())

    print("Fin du programme.")

    return 0

if __name__ == '__main__':
    main()