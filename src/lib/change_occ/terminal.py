class Terminal:
    def __init__(self):
        pass

    def GetInput(self, path):
        return input(f'{path} >>> ')

    def Print(self, ls_first, ls_second = []):
        nb_espace = 0
        for elem in ls_first:
            nb_espace = max(nb_espace, len(elem))
        nb_espace += 5
        for i in range(len(ls_first)):
            if i < len(ls_second):
                print(ls_first[i] + " "*(nb_espace-len(ls_first[i])) + ls_second[i])
            else:
                print(ls_first[i])

    def __str__(self):
        return f""