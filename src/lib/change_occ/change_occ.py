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
                        g.write(a)

# a = ChangeOcc("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/")