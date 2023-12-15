from tools import ChangeOccString, GetFile

class ChangeHeaderDouble:
    """
    Cette classe sert à changer les en-têtes des fichiers doubles.

    Args:
        file_path (str): Chemin vers le fichier des en-têtes de départ et d'arrivée.
    """

    def __init__(self, file_path=""):
        """
        Constructeur de la classe ChangeHeaderDouble.

        Parameters
        ----------
        file_path : str, optional
            Chemin vers le fichier des en-têtes de départ et d'arrivée (par défaut est une chaîne vide).
        """
        self.is_begin = False
        self.m_file_path = file_path
        # Les dictionnaires pour stocker les en-têtes d'origine et les nouveaux
        self.m_header_origin = {}
        self.m_header_new = {}

    def SetFilePath(self, file_path):
        """
        Méthode pour définir le chemin d'accès au fichier des en-têtes.

        Parameters
        ----------
        file_path : str
            Chemin vers le fichier.
        """
        self.m_file_path = file_path

    def Begin(self, index=0):
        """
        Méthode pour commencer le processus de modification d'en-tête. Récupère les en-têtes
        de départ et d'arrivée en fonction de l'index.

        Parameters
        ----------
        index : int, optional
            Index pour choisir les en-têtes (par défaut est 0).
        """
        self.m_header_origin, self.m_header_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory, file_path_origin, index_origin, file_path_new, index_new, replace_origin=[], replace_new=[]):
        """
        Méthode pour changer les en-têtes des fichiers.

        Parameters
        ----------
        directory : str
            Répertoire du fichier.
        file_path_origin : str
            Chemin du fichier contenant l'en-tête d'origine.
        index_origin : int
            Index pour choisir l'en-tête de départ.
        file_path_new : str
            Chemin du répertoire contenant les fichiers avec les nouveaux en-têtes.
        index_new : int
            Index pour choisir le nouvel en-tête.
        replace_origin : list, optional
            Liste des chaînes à remplacer dans le chemin de l'en-tête d'origine (par défaut est une liste vide).
        replace_new : list, optional
            Liste des chaînes de remplacement pour chaque élément de replace_origin (par défaut est une liste vide).
        """
        # Si la lecture n'a pas commencé, commencez par la première en-tête
        if not self.is_begin:
            self.Begin(0)

        # Ouvrez le fichier contenant l'en-tête d'origine, lisez-le et stockez chaque partie dans une liste
        with open(directory + file_path_origin, "r") as f:
            text = f.read().split("/* SPLIT */")
            text_origin = text[index_origin]

            # Pour chaque nouvel en-tête, remplacez l'ancien par le nouveau dans le texte
            for file_new in self.m_header_new:
                file_path = file_new.split("/")[-1]

                # Remplacer les correspondances dans replace_origin par replace_new
                for i in range(min(len(replace_origin), len(replace_new))):
                    file_path = file_path.replace(replace_origin[i], replace_new[i])

                # Ouvrez le fichier avec le nouvel en-tête et remplacez l'ancien en-tête par le nouveau
                with open(directory + file_path_new + file_path, "r") as g:
                    text_new = g.read().split("/* SPLIT */")

                    # Ecrivez le texte résultant dans le fichier
                    with open(directory + file_path_new + file_path, "w") as h:
                        for i in range(len(text_new)):
                            if i == index_new:
                                for file_origin in self.m_header_origin:
                                    h.write(ChangeOccString(text_origin, self.m_header_origin[file_origin], self.m_header_new[file_new]))
                            else:
                                h.write(text_new[i])
                            if i < len(text_new) - 1:
                                h.write("/* SPLIT */")
