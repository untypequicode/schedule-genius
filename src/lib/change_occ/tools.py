def ChangeOccString(content: str, origin: list, new: list) -> str:
    """
    Remplace toutes les occurrences des éléments de la liste 'origin' par les éléments correspondants de la liste 'new' dans la chaîne 'content'.
    S'arrête lorsque la fin de la liste la plus courte est atteinte.

    Parameters:
        content (str): La chaîne originale.
        origin (list): Liste des éléments à remplacer dans 'content'.
        new (list): Liste des éléments par lesquels remplacer dans 'content'.

    Returns:
        str: La chaîne 'content' après le remplacement des occurrences.
    """

    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i], new[i])
    return new_content


def GetFile(file_path: str, index: int) -> tuple:
    """
    Lit un fichier où chaque ligne est séparée par des virgules ('file_path') et renvoie un tuple de deux dictionnaires.
    Le premier dictionnaire contient la ligne à l'index donné du fichier en tant que clé et le reste des données de la ligne en tant que valeurs.
    Le second dictionnaire contient le reste du fichier de la même manière.

    Parameters:
        file_path (str): Le chemin vers le fichier à lire.
        index (int): L'index de la ligne à utiliser pour le premier dictionnaire.

    Returns:
        tuple: Deux dictionnaires - file_origin et file_new.
               file_origin contient la ligne à l'index donné.
               file_new contient le reste du fichier.
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
