#from change_occ import FileChangeOcc
from terminal import Terminal
from cd import Cd,os

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
            print("help : affiche ce message")
            print("exit : quitte le programme")
            print("set : change le fichier .csv")
            print("get : affiche le fichier .csv")

        elif response[0] == "ls":
            print(cd.Ls(terminal.GetPath()))

        elif response[0] == "cd" and len(response) >= 2:
            terminal.SetPath(cd.Cd(terminal.GetPath(), response[1]))

        elif response[0] == "load" and len(response) >= 2:
            file_path = terminal.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.append(file_path)

        elif response[0] == "unload" and len(response) >= 2:
            file_path = terminal.GetPath() + response[1]
            if cd.Exist(file_path):
                file_load.remove(file_path)



        else:
            print(f'Commande "{response[0]}" inconnue')

        response = terminal.GetInput()

    return 0

if __name__ == '__main__':
    main()