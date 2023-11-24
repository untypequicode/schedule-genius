class Load:
    def __init__(self):
        self.m_file_load = {"default": []}
        
    def GetList(self):
        return self.m_file_load

    def SetInput(self, input, cd):
        key = "default"
        if len(input) > 0:
            if input[0] == "key" and len(input) >= 2:
                if input[1] not in self.m_file_load:
                    self.m_file_load[input[1]] = []
                key = input[1]
                input = input[2:]
        if len(input) > 0:
            if (input[0] == "mount" or input[0] == "mnt") and len(input) >= 2:
                if input[1] == "-a":
                    self.__MountAll(input[2:], cd, key)
                else:
                    self.__Mount(input[1:], cd, key)
                return self.m_file_load
            elif (input[0] == "unmount" or input[0] == "umnt") and len(input) >= 2:
                if input[1] == "-a":
                    self.__UnmountAll(input[2:], cd, key)
                else:
                    self.__Unmount(input[1:], cd, key)
                return self.m_file_load
            elif input[0] == "list" or input[0] == "ls":
                self.__List(key)
                return self.m_file_load
            elif input[0] == "key":
                self.__ListKey()
                return None
            elif input[0] == "run":
                if key == "__terminal__":
                    return key, self.m_file_load[key]
                elif "__.cpp__" in key or "__.h__" in key or "__.h2__" in key:
                    if (len(input) >= 3 and "__.h__" in key) or (len(input) >= 4 and "__.h2__" in key):
                        return key, self.m_file_load[key], input[1:]
                    return key, self.m_file_load[key]
            print(f'Commande "{input[0:]}" inconnue.')
            return None
        print("Error: input empty")
        return None

    def __Mount(self, input, cd, key = "default"):
        ls = cd.LsFile()
        for file in input:
            if file in ls and cd.GetPath() + file not in self.m_file_load[key]:
                self.m_file_load[key].append(cd.GetPath() + file)

    def __MountAll(self, input, cd, key = "default"):
        ls = cd.LsFile()
        if len(input) >= 2:
            if input[0] == "\\":
                for exclude in input[1:]:
                    if exclude in ls:
                        ls.remove(exclude)
        for file in ls:
            if cd.GetPath() + file not in self.m_file_load[key]:
                self.m_file_load[key].append(cd.GetPath() + file)

    def __Unmount(self, input, cd, key = "default"):
        ls = cd.LsFile()
        for file in input:
            if file in ls and cd.GetPath() + file in self.m_file_load[key]:
                self.m_file_load[key].remove(cd.GetPath() + file)

    def __UnmountAll(self, input, cd, key = "default"):
        ls = cd.LsFile()
        if len(input) >= 2:
            if input[0] == "\\":
                for exclude in input[1:]:
                    if exclude in ls:
                        ls.remove(exclude)
        for file in ls:
            if cd.GetPath() + file in self.m_file_load[key]:
                self.m_file_load[key].remove(cd.GetPath() + file)

    def __List(self, key = "default"):
        if len(self.m_file_load[key]) == 0:
            print("Aucun fichier n'est chargé.")
        else:
            for file in self.m_file_load[key]:
                print(file)

    def __ListKey(self):
        for key in self.m_file_load:
            print(key)