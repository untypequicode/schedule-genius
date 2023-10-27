from change_occ import FileChangeOcc
from cd import Cd

def main():
    # file = FileChangeOcc("change_occ.csv")
    # file.GetGroup()
    # for groupe in file.m_group:
    #     print(groupe)

    terminal = Terminal()
    response = terminal.GetInput()
    while response != "exit":
        response = response.split(" ")
        if response[0] == "help":
            print("help : affiche ce message")
            print("exit : quitte le programme")
            print("set : change le fichier .csv")
            print("get : affiche le fichier .csv")

        elif response[0] == "ls":
            print(cd.ls(terminal.m_path))

        elif response[0] == "cd" and len(response) >= 2:
            terminal.m_path = cd.cd(terminal.m_path, response[1])




        else:
            print("Commande inconnue")

        response = terminal.GetInput()

    return 0

if __name__ == '__main__':
    main()