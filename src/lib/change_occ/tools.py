def ChangeOccString(content: str, origin: list, new: list) -> str:
    """
    Cette fonction remplace dans la chaîne 'content' toutes les occurrences des éléments
    de la liste 'origin' par les éléments correspondants de la liste 'new'.
    Elle s'arrête dès qu'elle atteint la fin de la liste la plus courte.

    Input:
        content (str): La chaîne originale.
        origin (list): Liste des éléments à remplacer dans 'content'.
        new (list): Liste des éléments par lesquels remplacer dans 'content'.

    Return:
        new_content (str): La chaîne 'content' après remplacement des occurrences.
    """
    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i], new[i])
    return new_content


def GetFile(file_path: str, index: int) -> tuple:
    """
    Cette fonction lit un fichier dont chaque ligne est séparée par des virgules
    ('file_path') et retourne un tuple de deux dictionnaires.
    Le premier dictionnaire contient la ligne d'index donné du fichier comme clé
    et le reste des données de la ligne comme valeurs.
    Le second dictionnaire contient le reste du fichier de la même manière.

    Input:
        file_path (str): Le chemin vers le fichier à lire.
        index (int): L'index de la ligne à utiliser pour le premier dictionnaire.

    Return:
        file_origin (dict): Dictionnaire contenant la ligne d'index donnée.
        file_new (dict): Dictionnaire contenant le reste du fichier.
    """
    with open(file_path, "r") as file:
        content = file.read().split("\n")
        for i in range(len(content) - 1, -1, -1):
            if content[i] == [] or content[i][0] == "#":
                content.pop(i)
            else:
                content[i] = content[i].split(",")
        file_origin = {content[index][0]: content[index][1:]}
        file_new = {}
        for i in range(len(content)):
            if i != index:
                file_new[content[i][0]] = content[i][1:]
        return file_origin, file_new