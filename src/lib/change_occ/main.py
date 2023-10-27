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
    response = terminal.GetInput()
    file_load = []

    while response != "exit":
        response = response.split(" ")
        if response[0] == "help":
            with open("help", "r") as help:
                for ligne in help.read().split("\n"):
                    ligne = ligne.split(" : ")
                    print(ligne[0] + " "*(20-len(ligne[0])) + ligne[1])

        elif response[0] == "ls":
            print(cd.Ls(terminal.GetPath()))

        elif response[0] == "cd" and len(response) >= 2:
            path = cd.Cd(terminal.GetPath(), response[1])
            if path != False:
                terminal.SetPath(path)
            else:
                print(f'Emplacement "{response[1]}" incorrect')

        elif response[0] == "load" and len(response) >= 2:
            file_path = terminal.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.append(file_path)

        elif response[0] == "unload" and len(response) >= 2:
            file_path = terminal.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.remove(file_path)



        else:
            print(f'Commande "{response[0]}" inconnue.')

        response = terminal.GetInput()

    print("Fin du programme.")

    return 0

if __name__ == '__main__':
    main()