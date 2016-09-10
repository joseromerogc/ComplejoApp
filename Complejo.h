#include <QString>
#ifndef COMPLEJO_H
#define COMPLEJO_H


class Complejo{

public:
    Complejo();
    Complejo(double,double,char);
    ~Complejo();
    void setParteReal(double);
    double getParteReal();
    void setParteImaginaria(double);
    char getSigno();
    void setSigno(const char);
    char getNombre();
    void setNombre(const char);
    double getParteImaginaria();
    const char *Mostrar(bool sinnombre=false);
    QString MostrarParteReal();
    QString MostrarParteImaginaria();

    Complejo operator +(Complejo c);
    double getParteImaginariaconSigno();
    void setParteImaginariaSigno(double value);
    Complejo Opuesto();
    void CambiarSigno();
    Complejo operator -(Complejo c);

    Complejo operator *(Complejo c);
    Complejo operator /(Complejo c);
private:
    double partereal, parteimaginaria,parteimaginaria_consigno;
    char signo,nombre;
};

#endif // COMPLEJO_H
