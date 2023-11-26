#from change_occ import FileChangeOcc
from terminal import Terminal
from cd import Cd
from load import Load
from change_occ import ChangeOcc
from change_header import ChangeHeader
from change_header_double import ChangeHeaderDouble

def main():
    terminal = Terminal()
    cd = Cd()
    load = Load()
    # response = terminal.GetInput(cd.GetPath())
    load.SetInput("key __terminal__ mnt terminal".split(" "), cd)
    response = "load key __terminal__ run"

    while response != "exit":
        response = response.split(" ")
        if response[0] == "help":
            with open("help", "r") as help:
                lignes = help.read().split("\n")
                help_content = [[], []]
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
            load_return = load.SetInput(response[1:], cd)
            if 'run' in response and len(load_return) >= 2:
                if load_return[0] == '__terminal__':
                    terminal.AddTerminal(load_return[1])
                if '__.cpp__' in  load_return[0]:
                    for file in load_return[1]:
                        a = ChangeOcc(file)
                        a.Change(cd.GetPath())
                if '__.h__' in load_return[0] and len(load_return) >= 3:
                    for file in load_return[1]:
                        a = ChangeHeader(file)
                        a.Change(cd.GetPath(), load_return[2][0], int(load_return[2][1]), int(load_return[2][2]))
                elif '__.h2__' in load_return[0] and len(load_return) >= 3:
                    for file in load_return[1]:
                        a = ChangeHeaderDouble(file)
                        b = load_return[2][4:]
                        replace_origin = []
                        replace_new = []
                        if '__' in b:
                            while b[0] != '__':
                                replace_origin.append(b.pop(0))
                            b.pop(0)
                            replace_new = b
                        a.Change(cd.GetPath(), load_return[2][0], int(load_return[2][1]), load_return[2][2], int(load_return[2][3]), replace_origin, replace_new)
                

        else:
            print(f'Commande "{response[0]}" inconnue.')
        response = terminal.GetInput(cd.GetPath())

    print("Fin du programme.")

    return 0

if __name__ == '__main__':
    main()