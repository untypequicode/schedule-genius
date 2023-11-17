from tools import ChangeOccString

class ChangeHeader:
    def __init__(self, file_path = ""):
        self.is_begin = False
        self.m_file_path = file_path

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index = 0):
        self.is_begin = True

    def Change(self, directory, file):
        if not self.is_begin:
            self.Begin(0)