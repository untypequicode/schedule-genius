import os
def ChangeOccString(content:str, origin:list, new:list)->str:
    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i],new[i])
    return new_content

class ChangeOcc:

    def __init__(self, file_path=""):
        self.as_begin = False
        self.index = None
        self.m_file_path = file_path

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index = 0)->dict:
        ''' create a dict of change occurence \n it's take a name of file and a index of group '''
        self.index = index
        self.as_begin = True
        self.m_index = index
        self.m_dict = {}
        with open(self.m_file_path, "r") as f:
            i_temp = 0
            for groupe in f.read().split("\n"):
                if groupe != ""  :
                    if index == i_temp:
                        self.origin_key = groupe.split(",")[0]
                    self.m_dict[str(groupe.split(",")[0])] = groupe.split(",")[0:]
                i_temp += 1
            print(self.m_dict)
            return self.m_dict

    def Change(self, directory, file):
        ''' duplicate the file in the directory '''
        if not self.as_begin:
            self.Begin(0)
            self.index = 0
        with open(file, "r") as f:
            content = f.read()
            for key in self.m_dict.keys():
                with open(directory + "\\" + key, "w") as f:
                    content = ChangeOccString(content, self.m_dict[self.origin_key], self.m_dict[key])
                    print(self.m_dict[self.origin_key], self.m_dict[key])
                    f.write(content)



change_pass = ChangeOcc(os.getcwd() + "\\load_file\\tab_dyn_basic")
change_pass.Begin()
print(os.getcwd())
change_pass.Change(os.getcwd() + "\\load_file", "C:\\L1\\Projets CMI OPTIM\\Schedule-Genius\\src\\lib\\tab_dyn\\tab_dyn_char.cpp")