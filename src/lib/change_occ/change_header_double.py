from tools import ChangeOccString, GetFile

class ChangeHeaderDouble:
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

    def Change(self, directory, file_path_origin, index_origin, file_path_new, index_new, replace_origin = [], replace_new = []):
        if not self.is_begin:
            self.Begin(0)
        with open(directory + file_path_origin, "r") as f:
            print(directory + file_path_origin)
            text = f.read().split("/* SPLIT */")
            text_origin = text[index_origin]
            for file_new in self.m_header_new:
                file_path = file_new.split("/")[-1]
                for i in range(min(len(replace_origin), len(replace_new))):
                    file_path = file_path.replace(replace_origin[i], replace_new[i])
                with open(directory + file_path_new + file_path, "r") as g:
                    print(directory + file_path_new + file_path)
                    text_new = g.read().split("/* SPLIT */")
                    with open(directory + file_path_new + file_path, "w") as h:
                        for i in range(len(text_new)):
                            if i == index_new:
                                for file_origin in self.m_header_origin:
                                    h.write(ChangeOccString(text_origin, self.m_header_origin[file_origin],self.m_header_new[file_new]))
                            else:
                                h.write(text_new[i])
                            if i < len(text_new) - 1:
                                h.write("/* SPLIT */")

                    # print(ChangeOccString(text, self.m_header_origin[file_origin], self.m_header_new[file_new]))


# a = ChangeHeader("load_file/tab_dyn_basic")
# a.Change("../tab_dyn/", "tab_dyn.h")