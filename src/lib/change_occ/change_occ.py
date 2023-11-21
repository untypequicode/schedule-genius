from tools import ChangeOccString, GetFile

class ChangeOcc:
    def __init__(self, file_path=""):
        self.is_begin = False
        self.m_file_path = file_path
        self.m_file_origin = {}
        self.m_file_new = {}

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index=0):
        self.m_file_origin, self.m_file_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory):
        ''' duplicate the file in the directory '''
        if not self.is_begin:
            self.Begin(0)
        for file_new in self.m_file_new:
            for file_origin in self.m_file_origin:
                with open(directory + file_origin, "r") as f:
                    text = f.read()
                    a = ChangeOccString(text, self.m_file_origin[file_origin], self.m_file_new[file_new])
                    with open(directory + file_new, "w") as g:
                        print(directory + file_new)
                        g.write(a)

        # with open(file, "r") as f:
        #     content = f.read
        #     for key in self.m_dict.keys():
        #         with open(directory + "\\" + key, "w") as g:
        #             content = f.read()
        #             content = ChangeOccString(content, self.m_dict[self.origin_key], self.m_dict[key])
        #             print(self.m_dict[self.origin_key], self.m_dict[key])
        #             f.write(content)



# change_pass = ChangeOcc(os.getcwd() + "\\load_file\\tab_dyn_basic")
# change_pass.Begin()
# print(os.getcwd())
# change_pass.Change(os.getcwd() + "\\load_file", "C:\\L1\\Projets CMI OPTIM\\Schedule-Genius\\src\\lib\\tab_dyn\\tab_dyn_char.cpp")

a = ChangeOcc("load_file/tab_dyn_basic")
a.Begin()
print(a.m_file_origin)
print(a.m_file_new)
a.Change("../tab_dyn/")