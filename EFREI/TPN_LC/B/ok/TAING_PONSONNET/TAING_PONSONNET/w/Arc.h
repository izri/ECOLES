#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED

#include <string>
#include <vector>

class Arc
{
    private:
    int indexInitial;
    int indexFinal;
    std::string type;

    public:
    Arc();
    virtual ~Arc();

    int getIndexInitial();
    int getIndexFinal();
    std::string getType();

    void setIndexInitial(int i);
    void setIndexFinal(int i);
    void setType(std::string i);
};

#endif // ARC_H_INCLUDED
