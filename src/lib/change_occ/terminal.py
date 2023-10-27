class Terminal:
    def __init__(self):
        self.__m_path = ""
    def GetInput(self):
        return input(f'{self.__m_path} >>> ')

    def GetPath(self):
        return self.__m_path

    def SetPath(self, path):
        self.__m_path = path



    def __str__(self):
        return f""