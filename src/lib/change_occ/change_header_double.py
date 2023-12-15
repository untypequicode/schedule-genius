from tools import ChangeOccString, GetFile

# Cette classe sert à changer les en-têtes des fichiers doubles
class ChangeHeaderDouble:
    def __init__(self, file_path = ""):
        # Initialise avec un fichier par défaut vide
        self.is_begin = False
        self.m_file_path = file_path
        # Les dictionnaires pour stocker les en-têtes d'origine et les nouveaux
        self.m_header_origin = {}
        self.m_header_new = {}

    # Définit le chemin d'accès au fichier
    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    # Commence à lire le fichier et à stocker les en-têtes dans les dictionnaires
    def Begin(self, index = 0):
        # On utilise la fonction GetFile pour obtenir les en-têtes
        self.m_header_origin, self.m_header_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    # Change les en-têtes des fichiers
    def Change(self, directory, file_path_origin, index_origin, file_path_new, index_new, replace_origin = [], replace_new = []):
        # Si la lecture n'a pas commencé, commencez par la première en-tête
        if not self.is_begin:
            self.Begin(0)
        # Ouvrez le fichier contenant l'en-tête d'origine, lisez-le et stockez chaque partie dans une liste
        with open(directory + file_path_origin, "r") as f:
            print(directory + file_path_origin)
            text = f.read().split("/* SPLIT */")
            text_origin = text[index_origin]
            # Pour chaque nouvel en-tête, remplacez l'ancien par le nouveau dans le texte
            for file_new in self.m_header_new:
                file_path = file_new.split("/")[-1]
                # Remplacer les correspondances dans replace_origin par replace_new
                print(replace_origin, replace_new)
                for i in range(min(len(replace_origin), len(replace_new))):
                    file_path = file_path.replace(replace_origin[i], replace_new[i])
                # Ouvrez le fichier avec le nouvel en-tête et remplacez l'ancien en-tête par le nouveau
                with open(directory + file_path_new + file_path, "r") as g:
                    print(directory + file_path_new + file_path)
                    text_new = g.read().split("/* SPLIT */")
                    # Ecrivez le texte résultant dans le fichier
                    with open(directory + file_path_new + file_path, "w") as h:
                        for i in range(len(text_new)):
                            if i == index_new:
                                for file_origin in self.m_header_origin:
                                    h.write(ChangeOccString(text_origin, self.m_header_origin[file_origin],self.m_header_new[file_new]))
                            else:
                                h.write(text_new[i])
                            if i < len(text_new) - 1:
                                h.write("/* SPLIT */")


# Code pour tester la classe
# a = ChangeHeader("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/", "tab_dyn.h")