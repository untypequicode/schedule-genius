class Terminal:
    def __init__(self):
        self.m_path = ""
    def GetInput(self):
        return input(f'>>> {self.m_path} >>> ')



    def __str__(self):
        return f""