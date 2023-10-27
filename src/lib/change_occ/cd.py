import os
class Cd:
    def __init__(self, path = ""):
        self.m_original_path = path
    def Set_path(self, path):
        self.m_path = path

    def Ls(self, path) -> list:
        """ return the list of directories """
        assert isinstance(path, str), " Le chemin doit être un string "
        return os.listdir(self.m_path + path)
    def __Split_path(self, path):
        """ Split the path """
        up_list = []
        while path[3:] == "../":
            up_list += path[2:]
            path = path[2:]
        return up_list, path

    def Exist(self, path) -> bool:
        assert isinstance(path, str), " Le chemin doit être un string "
        """ Return a bool"""
        up_list, path = self.__Split_path(path)
        return os.path.exists(up_list + path)

    def Cd(self, actual_path, path) -> str :
        """ return False if  """
        assert isinstance(path, str), " Le chemin doit être un string "
        assert isinstance(actual_path, str) or actual_path is None, "Le chemin doit être un string ou un objet de type None"
        if actual_path is not None:
            self.m_path = actual_path
        up_list, path = self.__Split_path(path)
        if not os.path.exists(up_list + self.m_path + path):
            return False
        else:
            return up_list + self.m_path + path