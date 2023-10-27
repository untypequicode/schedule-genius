

class FileChangeOcc:
    def __init__(self, file_path):
        self.m_file_path = file_path

    def SetGilePath(self, file_path):
        self.m_file_path = file_path

    def GetGroup(self):
        with open(self.m_file_path, "r") as f:
            lignes = f.readlines()
            group = []
            for line in lignes:
                if line[0] != "#":
                    line = line.replace("\n", "")
                    group.append([])
                    split = line.split(",")
                    for i in split:
                        if i != "":
                            group[-1].append(i)
                    if group[-1] == []:
                        group.pop(-1)
            self.group = group

    def __str__(self):
        return f"{self.m_file_path}"