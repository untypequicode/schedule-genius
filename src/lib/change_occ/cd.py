import os
class Cd:
    def __init__(self, path = ""):
        if path == "":
            self.m_path = os.getcwd() + "/"
        else:
            self.m_path = path
    def SetPath(self, path):
        self.m_path = path
    def GetPath(self)-> str:
        return self.m_path

    def GetActualPath(self)-> str:
        return os.getcwd() + '/'
    def Ls(self, path) -> list:
        """ return the list of directories """
        assert isinstance(path, str), " Le chemin doit être un string "
        return os.listdir(self.m_path + path)

    def __Split_path(self, path):
        """ Split the path """
        copy_self_path = self.m_path
        list_element_in_path = self.__Borned_by(copy_self_path, "/")
        new_path = ""
        indice_max = len(list_element_in_path) - 1
        while path[2:] == "../":
            path = path[2:]
            indice_max -= 1
        for i in range(indice_max):
            new_path += list_element_in_path[i]
            self.m_path += list_element_in_path[i]
        new_path += path
        return new_path

    def __Borned_by(self, string, separator)-> str:
        new_list = []
        string_temp = ""
        for element in string:
            if separator == str(element):
                new_list.append(string_temp)
                string_temp = ""
            if string_temp != "":
                string_temp.append(element)
        return new_list

    def Exist(self, path) -> bool:
        assert isinstance(path, str), " Le chemin doit être un string "
        """ Return a bool"""
        up_list, path = self.__Split_path(path)
        return os.path.exists(up_list + path)

    def Cd(self, path) -> str :
        """ return False if  """
        print(self.Get_path())
        assert isinstance(path, str), " Le chemin doit être un string "
        path = self.__Split_path(path)
        print(path,"hello", self.m_path)
        if not os.path.exists(path):
            return False
        return path

# test = Cd()
# print(test.Get_path())