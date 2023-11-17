class ChangeOcc:

    def __init__(self, file_path=""):
        self.as_begin = False
        self.m_file_path = file_path

    def SetFilePath(self, file_path):
        self.m_file_path = file_path

    def Begin(self, index = 0):
        self.as_begin = True
        pass

    def Change(self, directory, file):
        if not self.as_begin:
            self.Begin(0)
        pass