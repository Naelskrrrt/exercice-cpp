#include <iostream>
#include <ctime>
using namespace std;

class DateHeure
{
private:
    time_t timestamp;

public:
    DateHeure()
    {
        timestamp = time(nullptr);
    }

    DateHeure(int jour, int mois, int annee, int heure, int minute, int seconde)
    {
        struct tm t;
        t.tm_mday = jour;
        t.tm_mon = mois - 1;
        t.tm_year = annee - 1900;
        t.tm_hour = heure;
        t.tm_min = minute;
        t.tm_sec = seconde;
        timestamp = mktime(&t);
    }

    DateHeure(const DateHeure &autre)
    {
        this->timestamp = autre.timestamp;
    }

    void afficher() const
    {
        struct tm *timeinfo = localtime(&timestamp);
        cout << asctime(timeinfo);
    }

    double difference(const DateHeure &autre) const
    {
        return difftime(timestamp, autre.timestamp);
    }
};

int main()
{
    DateHeure maintenant;
    DateHeure dateFixe(14, 10, 2024, 10, 0, 0);

    cout << "Date actuelle : ";
    maintenant.afficher();

    cout << "Date fixe :";
    dateFixe.afficher();

    cout << "Différence en secondes :" << maintenant.difference(dateFixe) << "secondes." << endl;

    return 0;
}