

class FileChangeOcc:
    def __init__(self, file_path, line, change_type, change):
        self.file_path = file_path
        self.line = line
        self.change_type = change_type
        self.change = change

    def __str__(self):
        return f"{self.file_path}:{self.line}: {self.change_type} {self.change}"