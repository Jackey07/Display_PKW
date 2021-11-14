#ifndef FAHRENPKW_H
#define FAHRENPKW_H

#include <QString>

class FahrenPKW
{
    bool start = false;     // Staten oder Parken
    int geschwindigkeit = 0;
    int drehzahl = 0;
    int kraftstoffverbrauch = 0;
    int gesamtkilometerzahl = 0;
    QString status = "Alles gut.";

public:
    FahrenPKW();
    bool getStart();
    void setStart(bool);
    void geschwErhoehen();
    void geschwReduzieren();
    void drehzahlAendern();
    void kraftstoffVerbrauch();
    void gesamtKilometerZahl();
};

#endif // FAHRENPKW_H
