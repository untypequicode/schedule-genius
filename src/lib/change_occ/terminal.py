class Terminal:
    '''
    La classe Terminal représente un terminal d'ordinateur simplifié.

    Attributs :
      m_list_cmd (list):  stocke les commandes saisies par l'utilisateur (par défaut c'est une liste vide)
    '''

    def __init__(self):
        self.m_list_cmd = []

    def GetInput(self, path):
        '''
        Méthode pour obtenir une saisie utilisateur. Si une commande est stockée dans m_list_cmd, elle est affichée et supprimée de la liste.

        Arguments:
          path (str): Le chemin à afficher avant l'entrée de l'utilisateur

        Returns:
          str: entrée utilisateur
        '''
        if len(self.m_list_cmd) == 0:
            return input(f'{path} >>> ')
        else:
            print(f'{path} >>> {self.m_list_cmd[0]}')
            return self.m_list_cmd.pop(0)

    def Print(self, ls_first, ls_second = []):
        '''
        Méthode pour imprimer deux listes côte à côte, alignées en colonnes.

        Arguments:
          ls_first (list): La première liste à imprimer
          ls_second (list): La deuxième liste à imprimer (par défaut c'est une liste vide)
        '''
        nb_espace = 0
        for elem in ls_first:
            nb_espace = max(nb_espace, len(elem))
        nb_espace += 5
        for i in range(len(ls_first)):
            if i < len(ls_second):
                print(ls_first[i] + " "*(nb_espace-len(ls_first[i])) + ls_second[i])
            else:
                print(ls_first[i])

    def AddTerminal(self, path:list)-> None:
        '''
        Méthode pour ajouter une liste de commandes à partir d'un fichier texte.

        Arguments:
          path (list): Liste des chemins des fichiers à lire.

        Side-effect:
         Peuple la liste m_list_cmd avec des commandes lues à partir des fichiers.
        '''
        assert isinstance(path, list), "path must be a list"
        for elem in path:
            with open(elem, "r") as f:
                for line in f.read().split("\n"):
                    if line != "":
                        self.m_list_cmd.append(line)

    def __str__(self):
        '''
        Méthode qui renvoie une chaîne de caractères qui représente l'objet Terminal, ici c'est une chaîne vide.

        Returns:
          str: une chaîne représentant l'objet Terminal
        '''
        return f""