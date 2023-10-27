import os
class Cd:
    def __init__(self, path = ""):
        if path == "":
            self.m_path = os.getcwd() + "/"
        else:
            self.m_path = path
    def Set_path(self, path):
        self.m_path = path
    def Get_path(self)-> str:
        return self.m_path

    def Get_actual_path(self)-> str:
        return os.getcwd() + '/'
    def Ls(self, path) -> list:
        """ return the list of directories """
        assert isinstance(path, str), " Le chemin doit être un string "
        return os.listdir(self.m_path + path)
    def __Split_path(self, path):
        """ Split the path """
        list_element_in_path = self.__Borned_by(self.m_path, "/")
        new_path = ""
        indice_max = len(list_element_in_path - 1)
        while path[2:] == "../":
            path = path[2:]
            indice_max -= 1
        for i in range(indice_max):
            new_path.append(list_element_in_path[i])
        new_path.append(path)
        return new_paths

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

    def Cd(self, actual_path, path) -> str :
        """ return False if  """
        assert isinstance(path, str), " Le chemin doit être un string "
        assert isinstance(actual_path, str) or actual_path is None, "Le chemin doit être un string ou un objet de type None"
        if actual_path is not None:
            self.m_path = actual_path
        path = self.__Split_path(path)
        if not os.path.exists(path):
            return False
        else:
            return path

test = Cd()
print(test.Get_path())