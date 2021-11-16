// TODO Beschreibung der Klasse

#ifndef FAHRENPKW_H
#define FAHRENPKW_H

#include <QString>
#include <QTime>
#include "ui_mainwindow.h"
#include "bremse.h"
#include "gang.h"
#include "gaspedal.h"

#define _DEFAUTGESCHW_DEFAULT_ 0
#define _DEFAUTGESCHW_1_ 10
#define _DEFAUTGESCHW_2_ 20
#define _DEFAUTGESCHW_3_ 30
#define _DEFAUTGESCHW_4_ 40
#define _DEFAUTGESCHW_5_ 50
#define _MAXGESCHW_ 220

#define _DREHZAHL_DEFAULT_ 0
#define _DREHZAHL_1_ 2500
#define _DREHZAHL_2_ 2000
#define _DREHZAHL_3_ 2000
#define _DREHZAHL_4_ 3000
#define _DREHZAHL_5_ 3500

class FahrenPKW
{
    bool motor = false;     // Staten oder Parken
    int geschwindigkeit = 0;
    int drehzahl = 0;
    // KraftstoffVerbrauch rechnet mit Prozent (0 - 100)%
    float kraftstoffverbrauch = 0.0;
    int gesamtkilometerzahl = 0;
    QString status = "Alles gut.";

    // QTime vorhergehendzeit;

public:
    FahrenPKW();
    FahrenPKW(bool, int, int, float, int, QString);

    bool getMotor();
    void setMotor(bool);

    int getGeschw();
    int geschwErhoehen(QString);
    int geschwReduzieren();
    int getDefautGeschwMitGang(QString);

    int getDrehzahl();
    void drehzahlAendern(QString);

    float getKraftS();
    int kraftstoffVerbrauch();

    int getGesamtK();
    int gesamtKilometerZahl();

    QString getStatus();
    void getStatus(QString);

    void bildRueckfahrZeigen();

/*     Status von Dislay PKW einstellen
       gang, bremse, gas, geschw, drehZahl, kraftstoffV, gesamtK, status, ui
       void setDisplayPKW(QString, bool, bool,
                       int, int, float, int, QString, Ui::MainWindow*);
*/
    // Status von Dislay PKW einstellen
    // gang, bremse, gas, geschw, kraftstoffV, gesamtK, status, ui
    void setDisplayPKW(QString, bool, bool,
                       int, float, int, QString, Ui::MainWindow*);

    void startInit(Bremse*, Gang*, Gaspedal*);

    void rueckFahren();
    void vorfahrenMitGang(QString, Bremse*, Gaspedal*);
};

#endif // FAHRENPKW_H
