def ChangeOccString(content: str, origin: list, new: list) -> str:
    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i], new[i])
    return new_content

def GetFile(file_path, index):
    with open(file_path, "r") as file:
        content = file.read().split("\n")
        for i in range(len(content) - 1, -1, -1):
            if content[i] == [] or content[i][0] == "#":
                content.pop(i)
            else:
                content[i] = content[i].split(",")
        file_origin = {content[index][0]: content[index][1:]}
        file_new = {}
        for i in range(len(content)):
            if i != index:
                file_new[content[i][0]] = content[i][1:]
        return file_origin, file_new