import os
def ChangeOccString(content:str, origin:list, new:list)->str:
    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i],new[i])
    return new_content

class ChangeOcc:

    def __init__(self, file_path=""):
        self.as_begin = False
        self.m_file_path = file_path

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index = 0)->dict:
        ''' create a dict of change occurence \n it's take a name of file and a index of group '''
        self.as_begin = True
        self.m_index = index
        self.m_dict = {}
        with open(self.m_file_path, "r") as f:
            i_temp = 0
            for groupe in f.read().split("\n"):
                if groupe != "" and index == i_temp:
                    origin = {groupe.split(",")[0] :groupe.split(",")[1:]}
                    return origin
                i_temp += 1

    def Change(self, directory, file):
        ''' duplicate the file in the directory '''
        if not self.as_begin:
            self.Begin(0)
            index = 0
        with open(self.m_file_path, "r") as f:
            for groupe in f.read().split("\n"):
                if groupe != "":
                    origin = groupe.split(",")[0]
                    new = groupe.split(",")[1:]
                    new_content = ChangeOccString(file, origin, new)
                    with open(directory + "\\" + str(index) + ".txt", "w") as f:
                        f.write(new_content)



change_pass = ChangeOcc(os.getcwd() + "\\load_file\\tab_dyn_basic")
change_pass.Begin()