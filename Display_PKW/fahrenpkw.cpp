#include "fahrenpkw.h"

FahrenPKW::FahrenPKW()
{

}

FahrenPKW::FahrenPKW(bool s, int g, int d, float k, int gk, QString sS)
    : motor(s),
      geschwindigkeit(g),
      drehzahl(d),
      kraftstoffverbrauch(k),
      gesamtkilometerzahl(gk),
      status(sS)
{

}

bool FahrenPKW::getMotor()
{
    return motor;
}

void FahrenPKW::setMotor(bool s)
{
    motor = s;
}

int FahrenPKW::getGeschw()
{
    return geschwindigkeit;
}

int FahrenPKW::geschwErhoehen(QString g)
{
    if (g == "N")
    {
        geschwindigkeit = 0;
    } else if (g == "R")
    {
        geschwindigkeit = 10;
    }

    switch (g.toInt()) {
    case 1:
        geschwindigkeit = 10;
        break;
    case 2:
        geschwindigkeit = 20;
        break;
    case 3:
        geschwindigkeit = 30;
        break;
    case 4:
        geschwindigkeit = 40;
        break;
    case 5:
        geschwindigkeit = 50;
        break;
    default:
        geschwindigkeit = 0;
    }

    return geschwindigkeit;
}

int FahrenPKW::geschwReduzieren(QString gang)
{
    geschwindigkeit -= 10;
    return geschwindigkeit;
}

int FahrenPKW::getDrehzahl()
{
    return drehzahl;
}

void FahrenPKW::drehzahlAendern(QString g)
{
    switch (g.toInt()) {
    case 1:
        drehzahl = _DREHZAHL_1_;
        break;
    case 2:
        drehzahl = _DREHZAHL_2_;
        break;
    case 3:
        drehzahl = _DREHZAHL_3_;
        break;
    case 4:
        drehzahl = _DREHZAHL_4_;
        break;
    case 5:
        drehzahl = _DREHZAHL_5_;
        break;
    default:
        drehzahl = _DREHZAHL_DEFAULT_;
    }
}

float FahrenPKW::getKraftS()
{
    return kraftstoffverbrauch;
}

int FahrenPKW::kraftstoffVerbrauch()
{
    kraftstoffverbrauch += 10;
    return kraftstoffverbrauch;
}

int FahrenPKW::getGesamtK()
{
    return gesamtkilometerzahl;
}

int FahrenPKW::gesamtKilometerZahl()
{
    gesamtkilometerzahl += 1;
    return gesamtkilometerzahl;
}

QString FahrenPKW::getStatus()
{
    return status;
}

void FahrenPKW::getStatus(QString s)
{
    status = s;
}

void FahrenPKW::bildRueckfahrZeigen()
{

}

void FahrenPKW::setDisplayPKW(QString gang, bool gas, bool bremse,
                              int g, float k, int gk, QString sS, Ui::MainWindow* ui)
{
    geschwindigkeit = g;

    drehzahlAendern(gang);

    status = sS;
    if (kraftstoffverbrauch >= 100)
    {
        kraftstoffverbrauch = 100;
        ui->label_Info->setText("Kraftstoff leer!!!");
    } else
    {
       kraftstoffverbrauch = k;
       ui->label_Info->setText(status);
    }

    gesamtkilometerzahl = gk;


    ui->label->setText(gang);
    ui->lcdNumber_Geschw->display(geschwindigkeit);
    ui->dial_Geschw->setValue(geschwindigkeit);
    ui->dial_Drehzahl->setValue(drehzahl);
    ui->dial_KraftstoffV->setValue(kraftstoffverbrauch);
    ui->lcdNumber_GesamtK->display(gesamtkilometerzahl);
    // 3 Status einstellen
    if (motor)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText, Qt::red);
        ui->label_start->setPalette(pe);
    } else if (gas)
    {
        ;
    } else if (bremse)
    {
        ;
    }
}

void FahrenPKW::startInit(Bremse* b, Gang* g, Gaspedal* gas)
{
    motor = true;
    b->setBremse(true);
    g->setGang("1");
    gas->setGaspedal(false);
}

void FahrenPKW::rueckFahren()
{
    ;
}

void FahrenPKW::vorfahrenMitGang(QString)
{
    ;
}






