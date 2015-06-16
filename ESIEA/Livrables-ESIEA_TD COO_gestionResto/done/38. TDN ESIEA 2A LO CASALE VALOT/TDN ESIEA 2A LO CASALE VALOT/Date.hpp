#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED


using namespace std;

class Date
{
private:
    unsigned int jour, mois, annee;
    unsigned int heure, minute;
public:
    Date();
    Date(unsigned int he,unsigned int mi,unsigned int jo,unsigned int mo,unsigned int an){
        heure=he;
        minute=mi;
        jour=jo;
        mois=mo;
        annee=an;
    }

    void set_jour(unsigned int j)
    {
        jour=j;
    }
    void set_mois(unsigned int m)
    {
        mois=m;
    }
    void set_annee(unsigned int a)
    {
        annee=a;
    }
    void set_heure(unsigned int h)
    {
        heure=h;
    }
    void set_minute(unsigned int m)
    {
        minute=m;
    }
};

#endif // DATE_HPP_INCLUDED
