from tools import ChangeOccString, GetFile

class ChangeHeader:
    """
    Classe ChangeHeader pour changer les en-têtes d'un fichier.

    Args:
        file_path (str): Chemin vers le fichier des en-têtes de départ et d'arrivée.
    """
    def __init__(self, file_path = ""):
        self.is_begin = False
        self.m_file_path = file_path
        self.m_header_origin = {}  # Dictionnaire contenant les en-têtes de départ
        self.m_header_new = {}  # Dictionnaire contenant les nouveaux en-têtes

    def SetFilePath(self, file_path):
        """
        Méthode pour mettre à jour le chemin vers le fichier des en-têtes.

        Args:
            file_path (str): Chemin vers le fichier.
        """
        self.m_file_path = file_path

    def Begin(self, index = 0):
        """
        Méthode pour commencer le processus de modification d'en-tête. Récupère les en-têtes
        de départ et d'arrivée en fonction de l'index.

        Args:
            index (int): Index pour choisir les en-têtes.
        """
        self.m_header_origin, self.m_header_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory, file, index_origin, index_new):
        """
        Méthode pour modifier les en-têtes dans le fichier spécifié.

        Args:
            directory (str): Répertoire du fichier.
            file (str): Nom du fichier.
            index_origin (int): Index pour choisir l'en-tête de départ.
            index_new (int): Index pour choisir le nouvel en-tête.
        """
        if not self.is_begin:
            self.Begin(0)
        # Ouvre et lit le fichier
        with open(directory + file, "r") as f:
            text = f.read().split("/* SPLIT */")
            # Ouvre et écrit dans le fichier
            with open(directory + file, "w") as g:
                for i in range(len(text)):
                    if i == index_origin:
                        text_origin = text[i]
                        g.write(text[i])
                    elif i == index_new:
                        # Change les occurrences de l'en-tête de départ par le nouvel en tête
                        for file_new in self.m_header_new:
                            for file_origin in self.m_header_origin:
                                g.write(ChangeOccString(text_origin, self.m_header_origin[file_origin],self.m_header_new[file_new]))
                    else:
                        g.write(text[i])
                    # Ajoute un séparateur entre les blocs
                    if i < len(text) - 1:
                        g.write("/* SPLIT */")