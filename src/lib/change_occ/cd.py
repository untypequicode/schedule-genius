import os

class Cd:
    """
    Une classe qui représente un chemin dans le système de fichiers.

    ...

    Attributes
    ----------
    m_path : str
        un chemin vers un répertoire.

    Methods
    -------
    SetPath(path: str)
        Définit m_path à un nouveau chemin.

    GetPath() -> str
        Retourne m_path.

    GetActualPath() -> str
        Retourne le chemin actuel où se trouve le script.

    Ls() -> dict
        Retourne un dictionnaire avec deux listes de noms: 'dir' pour les dossiers et 'file' pour les fichiers.

    LsFile() -> list
        Retourne une liste des noms de fichiers dans m_path.

    LsDir() -> list
        Retourne une liste des noms de répertoires dans m_path.

    __Split_path(path: str) -> str
        Retourne le chemin relatif à m_path.

    __Borned_by(string: str, separator: str) -> str
        Retourne une liste de sous-chaînes de la chaîne divisée par le séparateur.

    Exist(path: str) -> bool
        Vérifie si le chemin (répertoire ou fichier) existe dans le système de fichiers.

    IsDir(path: str) -> bool
        Vérifie si le chemin est un répertoire dans le système de fichiers.

    IsFile(path: str) -> bool
        Vérifie si le chemin est un fichier dans le système de fichiers.

    Cd(path: str) -> str
        Change m_path au chemin donné, si le chemin existe dans le système de fichiers.
    """

    def __init__(self, path=""):
        """
        Constructeur de la classe Cd. Initialise le chemin vers un répertoire.

        Parameters
        ----------
        path : str, optional
            Un chemin vers un répertoire (par défaut est le répertoire courant du script)
        """
        if path == "":
            self.m_path = os.getcwd().replace("\\", "/") + "/"
        else:
            self.m_path = path.replace("\\", "/")

    def SetPath(self, path):
        """
        Définit m_path à un nouveau chemin.

        Parameters
        ----------
        path : str
            Le nouveau chemin.
        """
        self.m_path = path

    def GetPath(self) -> str:
        """
        Retourne m_path.

        Returns
        -------
        str
            Le chemin actuel.
        """
        return self.m_path

    def GetActualPath(self) -> str:
        """
        Retourne le chemin actuel où se trouve le script.

        Returns
        -------
        str
            Le chemin actuel du script.
        """
        return os.getcwd() + '/'

    def Ls(self) -> dict:
        """
        Retourne la liste des chemins dans m_path.

        Returns
        -------
        dict
            Un dictionnaire avec deux listes de noms: 'dir' pour les dossiers et 'file' pour les fichiers.
        """
        ls = os.listdir(self.m_path)
        ls_sort = {"dir": [], "file": []}
        for elem in ls:
            if os.path.isdir(os.path.join(self.m_path, elem)):
                ls_sort["dir"].append(elem)
        for elem in ls:
            if os.path.isfile(os.path.join(self.m_path, elem)):
                ls_sort["file"].append(elem)
        return ls_sort

    def LsFile(self) -> list:
        """
        Retourne la liste des fichiers dans m_path.

        Returns
        -------
        list
            Une liste des fichiers dans m_path.
        """
        ls = os.listdir(self.m_path)
        ls_file = [elem for elem in ls if os.path.isfile(os.path.join(self.m_path, elem))]
        return ls_file

    def LsDir(self) -> list:
        """
        Retourne la liste des répertoires dans m_path.

        Returns
        -------
        list
            Une liste des répertoires dans m_path.
        """
        ls = os.listdir(self.m_path)
        ls_dir = [elem for elem in ls if os.path.isdir(os.path.join(self.m_path, elem))]
        return ls_dir

    def __Split_path(self, path):
        """
        Retourne le chemin relatif à m_path.

        Parameters
        ----------
        path : str
            Le chemin à diviser.

        Returns
        -------
        str
            Le chemin relatif à m_path.
        """
        list_element_in_path = self.__Borned_by(self.m_path, "/")
        new_path = ""
        indice_max = len(list_element_in_path)
        while path[:3] == "../":
            path = path[3:]
            indice_max -= 1
        for i in range(indice_max):
            new_path += list_element_in_path[i] + '/'
            self.m_path += list_element_in_path[i]
        new_path += path
        return new_path

    def __Borned_by(self, string, separator) -> list:
        """
        Retourne une liste de sous-chaînes de la chaîne divisée par le séparateur.

        Parameters
        ----------
        string : str
            La chaîne à diviser.
        separator : str
            Le séparateur pour diviser la chaîne.

        Returns
        -------
        list
            Une liste de sous-chaînes de la chaîne divisée par le séparateur.
        """
        new_list = []
        string_temp = ""
        for element in string:
            if separator == str(element):
                new_list.append(string_temp)
                string_temp = ""
            else:
                string_temp += element
        return new_list

    def Exist(self, path) -> bool:
        """
        Vérifie si le chemin (répertoire ou fichier) existe dans le système de fichiers.

        Parameters
        ----------
        path : str
            Le chemin à vérifier.

        Returns
        -------
        bool
            True si le chemin existe, False sinon.
        """
        assert isinstance(path, str), " Le chemin doit être un string "
        return self.IsDir(path) or self.IsFile(path)

    def IsDir(self, path) -> bool:
        """
        Vérifie si le chemin est un répertoire dans le système de fichiers.

        Parameters
        ----------
        path : str
            Le chemin à vérifier.

        Returns
        -------
        bool
            True si le chemin est un répertoire, False sinon.
        """
        assert isinstance(path, str), " Le chemin doit être un string "
        return os.path.isdir(path)

    def IsFile(self, path) -> bool:
        """
        Vérifie si le chemin est un fichier dans le système de fichiers.

        Parameters
        ----------
        path : str
            Le chemin à vérifier.

        Returns
        -------
        bool
            True si le chemin est un fichier, False sinon.
        """
        assert isinstance(path, str), " Le chemin doit être un string "
        return os.path.isfile(path)

    def Cd(self, path) -> str:
        """
        Change m_path au chemin donné, si le chemin existe dans le système de fichiers.

        Parameters
        ----------
        path : str
            Le nouveau chemin.

        Returns
        -------
        str
            Le nouveau chemin si le changement a réussi, False sinon.
        """
        assert isinstance(path, str), " Le chemin doit être un string "
        a = self.__Split_path(path)
        if not self.Exist(a):
            return False
        path = a
        self.m_path = path
        return path

# test = Cd()
# print(test.Get_path())
