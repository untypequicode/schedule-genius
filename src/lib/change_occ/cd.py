import os
class Cd:
    def __init__(self, path = ""):
        self.m_original_path = path
    def Set_path(self, path):
        self.m_path = path

    def Ls(self, path) -> list:
        """ return the list of directories """
        return os.listdir(m_path + path)
    def __Split_path(self, path):
        up_list = []
        while path[3:] == "../":
            up_list += path[3:]
            path = path[3:]
        return up_list, path

    def Exist(self, path) -> bool:
        """ Return a bool"""
        up_list, path = self.__Split_path(path)
        return os.path.exists(up_list + path)

    def Cd(self, path) -> string :
        """ return  """
        up_list, path = self.__Split_path(path)
        if not os.path.exists(up_list + self.m_path + path):
            return False
        else:
            return up_list + self.m_path + path