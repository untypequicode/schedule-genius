class Terminal:
    def __init__(self):
        self.m_list_cmd = []
        pass

    def GetInput(self, path):
        if len(self.m_list_cmd) == 0:
            return input(f'{path} >>> ')
        else:
            print(f'{path} >>> {self.m_list_cmd[0]}')
            return self.m_list_cmd.pop(0)

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

    def AddTerminal(self, path:str): -> None
        ''' Add a terminal '''
        with open(path, "r") as f:
            for line in f.read().split("\n"):
                if line != "":
                    self.m_list_terminal.append(line)

    def __str__(self):
        return f""