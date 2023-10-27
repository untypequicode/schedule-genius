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
                lignes = help.read().split("\n")
                nb_espace = 0
                for i in range(len(lignes)):
                    lignes[i] = lignes[i].split(" : ")
                    nb_espace = max(nb_espace, len(lignes[i][0]))
                nb_espace += 5
                for ligne in lignes:
                    print(ligne[0] + " "*(nb_espace-len(ligne[0])) + ligne[1])

        elif response[0] == "ls":
            print(cd.Ls(cd.GetPath()))

        elif response[0] == "cd" and len(response) >= 2:
            cd.Cd(cd.GetPath(), response[1])
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

        response = terminal.GetInput()

    print("Fin du programme.")

    return 0

if __name__ == '__main__':
    main()