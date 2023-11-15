def ChangeOccString(content:str, origin:list, new:list)->str:
    new_content = content
    for i in range(min(len(new), len(origin))):
        new_content = new_content.replace(origin[i],new[i])
    return new_content