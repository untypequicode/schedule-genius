class Load:
    def __init__(self, path):
        self.m_path = path

    def SetPath(self, path):
        self.m_path = path

    def SetInput(self, path, input):
        self.m_path = path
        self.m_input = input


    def __Mount(self):
        pass

    def __MountAll(self):
        pass

    def __MountExcept(self):
        pass

    def __Unmount(self):
        pass

    def __UnmountAll(self):
        pass

    def __UnmountExcept(self):
        pass

    def __List(self):
        pass

