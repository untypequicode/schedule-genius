from terminal import Terminal
from cd import Cd
from load import Load
from change_occ import ChangeOcc
from change_header import ChangeHeader
from change_header_double import ChangeHeaderDouble

# Définition de la fonction principale
def main():
    # Initialiser les instances pour le Terminal, Cd et Load
    terminal = Terminal()
    cd = Cd()
    load = Load()

    # Obtenez l'entrée de l'utilisateur et initialisez la réponse
    load.SetInput("key __terminal__ mnt terminal".split(" "), cd)
    response = "load key __terminal__ run"

    # Boucle tant que l'utilisateur n'entre pas 'exit'
    while response != "exit":
        response = response.split(" ")
        # S'il entre 'help', ouvrez et lisez le fichier d'aide et l'imprimez dans le terminal
        if response[0] == "help":
            with open("help", "r") as help:
                lignes = help.read().split("\n")
                help_content = [[], []]
                # Décomposez les lignes en commandes et explications respectives et imprimez-les pour l'utilisateur
                for i in range(len(lignes)):
                    lignes[i] = lignes[i].split(" : ")
                    help_content[0].append(lignes[i][0])
                    help_content[1].append(lignes[i][1])
                terminal.Print(help_content[0], help_content[1])

        # Si l'utilisateur entre 'ls', trie les dossiers et les fichiers et les imprime dans le terminal
        elif response[0] == "ls":
            ls_sort = cd.Ls()
            if len(ls_sort["dir"]) >= len(ls_sort["file"]):
                terminal.Print(ls_sort["dir"], ls_sort["file"])
            elif len(ls_sort["file"]) > len(ls_sort["dir"]):
                terminal.Print(ls_sort["file"], ls_sort["dir"])

        # Si l'utilisateur entre 'cd' suivi d'un nom de répertoire, changez le répertoire actuel
        elif response[0] == "cd" and len(response) >= 2:
            cd.Cd(response[1])
            if cd.GetPath() == False:
                print(f'Emplacement "{response[1]}" incorrect')

        # Si l'utilisateur entre 'load', charger et exécuter les commandes de l'utilisateur
        elif response[0] == "load" and len(response) >= 2:
            load_return = load.SetInput(response[1:], cd)
            if 'run' in response and len(load_return) >= 2:
                if load_return[0] == '__terminal__':
                    terminal.AddTerminal(load_return[1])
                if '__.cpp__' in  load_return[0]:
                    print(load_return)
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


        # Si l'utilisateur entre une commande inconnue, imprime une alerte
        else:
            print(f'Commande "{response[0]}" inconnue.')

        # Obtenez l'entrée de l'utilisateur pour la prochaine boucle
        response = terminal.GetInput(cd.GetPath())

    # Imprime un message de fin de programme lorsque la boucle se termine
    print("Fin du programme.")

    return 0

# Point d'entrée de Python pour exécuter le script principal
if __name__ == '__main__':
    main()