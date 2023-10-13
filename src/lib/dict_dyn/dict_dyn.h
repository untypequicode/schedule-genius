#ifndef DEF_DICT_DYN
#define DEF_DICT_DYN

#include "../tab_dyn/tab_dyn.h"

class DictDynIntString : public TabDyn
{
public:
    DictDynIntString();
    DictDynIntString(unsigned int nbElemMax);
    DictDynIntString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
    DictDynIntString(const DictDynIntString& dictDynIntString);
    ~DictDynIntString();

    void Append(int key, std::string value);
    void Add(int key, std::string value);
    std::string Get(int key) const;
    int* GetKeys() const;
    std::string* GetValues() const;
    void Set(int key, std::string value);
    std::string Pop(int key);
    void Remove(int value, int num);
    void Remove(int value);
    void Remove(int value, bool first);

private:
    void AddAppend(int key, std::string value, bool addition);

    int* m_keys;
    std::string* m_values;
};

#endif