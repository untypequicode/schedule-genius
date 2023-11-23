from tools import ChangeOccString, GetFile

class ChangeHeader:
    def __init__(self, file_path = ""):
        self.is_begin = False
        self.m_file_path = file_path
        self.m_header_origin = {}
        self.m_header_new = {}

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index = 0):
        self.m_header_origin, self.m_header_new = GetFile(self.m_file_path, index)
        self.is_begin = True

    def Change(self, directory, file, index_origin, index_new):
        if not self.is_begin:
            self.Begin(0)
        with open(directory + file, "r") as f:
            text = f.read().split("/* SPLIT */")
            with open(directory + file, "w") as g:
                for i in range(len(text)):
                    if i == index_origin:
                        text_origin = text[i]
                        g.write(text[i])
                    elif i == index_new:
                        for file_new in self.m_header_new:
                            for file_origin in self.m_header_origin:
                                g.write(ChangeOccString(text_origin, self.m_header_origin[file_origin],self.m_header_new[file_new]))
                    else:
                        g.write(text[i])
                    if i < len(text) - 1:
                        g.write("/* SPLIT */")

                    # print(ChangeOccString(text, self.m_header_origin[file_origin], self.m_header_new[file_new]))


# a = ChangeHeader("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/", "tab_dyn.h")