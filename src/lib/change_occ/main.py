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
            print(cd.GetPath())
            if cd.GetPath() == False:
                print(f'Emplacement "{response[1]}" incorrect')

        elif response[0] == "load" and len(response) >= 2:
            file_path = cd.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.append(file_path)

        elif response[0] == "unload" and len(response) >= 2:
            file_path = cd.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.remove(file_path)

        else:
            print(f'Commande "{response[0]}" inconnue.')

        response = terminal.GetInput(cd.GetPath())

    print("Fin du programme.")

    return 0

if __name__ == '__main__':
    main()