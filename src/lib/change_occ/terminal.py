class Terminal:
    def __init__(self):
        pass

    def GetInput(self, path):
        return input(f'{path} >>> ')

    def __str__(self):
        return f""