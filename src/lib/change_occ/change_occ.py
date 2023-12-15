from tools import ChangeOccString, GetFile

class ChangeOcc:
    """
    Classe pour changer les occurrences dans un fichier.
    """

    def __init__(self, file_path=""):
        """
        Constructeur de la classe ChangeOcc.

        Parameters
        ----------
        file_path : str, optional
            Chemin vers le fichier dans lequel changer les occurrences, par défaut une chaîne vide.
        """
        self.is_begin = False
        self.m_file_path = file_path
        self.m_file_origin = {}
        self.m_file_new = {}

    def SetFilePath(self, file_path):
        """
        Définit le chemin vers le fichier sur lequel opérer.

        Parameters
        ----------
        file_path : str
            Chemin vers le fichier.
        """
        self.m_file_path = file_path

    def Begin(self, index=0):
        """
        Commence le processus en obtenant le fichier original et le nouveau fichier.

        Parameters
        ----------
        index : int, optional
            Index à utiliser pour obtenir le fichier, par défaut 0.
        """
        self.m_file_origin, self.m_file_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory):
        """
        Duplique le fichier dans le répertoire et change les occurrences.

        Parameters
        ----------
        directory : str
            Répertoire dans lequel dupliquer le fichier.
        """
        if not self.is_begin:
            self.Begin(0)
        for file_new in self.m_file_new:
            for file_origin in self.m_file_origin:
                with open(directory + file_origin, "r") as f:
                    text = f.read()
                    a = ChangeOccString(text, self.m_file_origin[file_origin], self.m_file_new[file_new])
                    with open(directory + file_new, "w") as g:
                        g.write(a)

# Exemple d'utilisation de la classe ChangeOcc
# a = ChangeOcc("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/")
