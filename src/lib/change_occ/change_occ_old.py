

class FileChangeOcc:
    def __init__(self, file_path):
        self.m_file_path = file_path

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def GetGroup(self):
        with open(self.m_file_path, "r") as f:
            file = []
            for groupe in f.read().split("\n\n"):
                groupe = groupe.split("\n")
                for i in range(len(groupe) - 1, -1, -1):
                    groupe[i] = groupe[i].split(",")
                    for j in range(len(groupe[i]) - 1, -1, -1):
                        groupe[i][j] = groupe[i][j].replace("\n", "")
                        if groupe[i][j] == "":
                            groupe[i].pop(j)
                        if groupe[i][j][0] == "#":
                            groupe[i].pop(j)
                    if len(groupe[i]) == 0:
                        groupe.pop(i)
                if len(groupe) > 0:
                    file.append(groupe)
        self.m_group = file



    def __str__(self):
        return f"{self.m_file_path}"