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

    def Change(self, directory, file):
        if not self.is_begin:
            self.Begin(0)

a = ChangeHeader("load_file/tab_dyn_basic")
a.Begin()
print(a.m_header_origin)
print(a.m_header_new)