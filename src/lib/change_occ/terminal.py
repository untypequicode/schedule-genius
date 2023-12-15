class Terminal:
    """
    La classe Terminal représente un terminal d'ordinateur simplifié.

    Attributes
    ----------
    m_list_cmd : list
        Stocke les commandes saisies par l'utilisateur.

    Methods
    -------
    GetInput(path)
        Obtient une saisie utilisateur.
    Print(ls_first, ls_second)
        Imprime deux listes côte à côte, alignées en colonnes.
    AddTerminal(path)
        Ajoute une liste de commandes à partir d'un fichier texte.
    __str__()
        Renvoie une chaîne de caractères représentant l'objet Terminal.
    """

    def __init__(self):
        """
        Initialise la classe Terminal.
        """
        self.m_list_cmd = []

    def GetInput(self, path):
        """
        Obtient une saisie utilisateur.

        Parameters
        ----------
        path : str
            Le chemin à afficher avant l'entrée de l'utilisateur.

        Returns
        -------
        str
            Entrée utilisateur.
        """
        if len(self.m_list_cmd) == 0:
            return input(f'{path} >>> ')
        else:
            print(f'{path} >>> {self.m_list_cmd[0]}')
            return self.m_list_cmd.pop(0)

    def Print(self, ls_first, ls_second=[]):
        """
        Imprime deux listes côte à côte, alignées en colonnes.

        Parameters
        ----------
        ls_first : list
            La première liste à imprimer.
        ls_second : list, optional
            La deuxième liste à imprimer (par défaut, c'est une liste vide).
        """
        nb_espace = 0
        for elem in ls_first:
            nb_espace = max(nb_espace, len(elem))
        nb_espace += 5

        for i in range(len(ls_first)):
            if i < len(ls_second):
                print(ls_first[i] + " " * (nb_espace - len(ls_first[i])) + ls_second[i])
            else:
                print(ls_first[i])

    def AddTerminal(self, path: list) -> None:
        """
        Ajoute une liste de commandes à partir d'un fichier texte.

        Parameters
        ----------
        path : list
            Liste des chemins des fichiers à lire.
        """
        assert isinstance(path, list), "path must be a list"

        for elem in path:
            with open(elem, "r") as f:
                for line in f.read().split("\n"):
                    if line != "":
                        self.m_list_cmd.append(line)

    def __str__(self):
        """
        Renvoie une chaîne de caractères représentant l'objet Terminal.

        Returns
        -------
        str
            Une chaîne représentant l'objet Terminal.
        """
        return f""
