from tools import ChangeOccString, GetFile

class ChangeOcc:
    """
    Classe pour changer les occurrences dans un fichier.
    """

    def __init__(self, file_path=""):
        """
        Constructeur de la classe ChangeOcc.

        :param file_path: Chemin vers le fichier dans lequel changer les occurrences, par défaut une chaîne vide.
        :type file_path: str
        """
        self.is_begin = False
        self.m_file_path = file_path
        self.m_file_origin = {}
        self.m_file_new = {}

    def SetFilePath(self, file_path):
        """
        Définit le chemin vers le fichier sur lequel opérer.

        :param file_path: Chemin vers le fichier.
        :type file_path: str
        """
        self.m_file_path = file_path

    def Begin(self, index=0):
        """
        Commence le processus en obtenant le fichier original et le nouveau fichier

        :param index: Index à utiliser pour obtenir le fichier, par défaut 0.
        :type index: int
        """
        self.m_file_origin, self.m_file_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory):
        """
        Duplique le fichier dans le répertoire et change les occurrences.

        :param directory: Répertoire dans lequel dupliquer le fichier.
        :type directory: str
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

# a = ChangeOcc("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/")