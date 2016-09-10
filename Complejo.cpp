#include "Complejo.h"
#include <string>
#include <QString>

Complejo::Complejo(){
    partereal=1;
    parteimaginaria=1;
    signo ='+';
    nombre='w';
    parteimaginaria_consigno=parteimaginaria;
}
Complejo::~Complejo(){
}
Complejo::Complejo(double pr,double pi,char nom){
    partereal=pr;
    parteimaginaria=pi;
    nombre=nom;
    if(parteimaginaria<0){
        signo='-';
        parteimaginaria=parteimaginaria*(-1);
    }
    else{
        signo='+';
        parteimaginaria=parteimaginaria;
    }
}

void Complejo::setParteReal(double value){
    partereal=value;
}
double Complejo::getParteReal(){
    return partereal;
}

void Complejo::setNombre(const char nom){
    nombre=nom;
}
char Complejo::getNombre(){
    return nombre;
}

void Complejo::setSigno(const char value){
    signo=value;
    if(signo=='-')
        parteimaginaria_consigno=parteimaginaria*(-1);
    else
        parteimaginaria_consigno=parteimaginaria;
}
char Complejo::getSigno(){
    return signo;
}

void Complejo::setParteImaginaria(double value){

    parteimaginaria=value;

    if(signo=='-')
        parteimaginaria_consigno=parteimaginaria*(-1);
    else
        parteimaginaria_consigno=parteimaginaria;
}

void Complejo::setParteImaginariaSigno(double value){

    parteimaginaria_consigno=value;

    if(value<0){
        signo='-';
        parteimaginaria=value*(-1);
    }
    else{
        signo='+';
        parteimaginaria=value;
    }
}

double Complejo::getParteImaginaria(){
    return parteimaginaria;
}
double Complejo::getParteImaginariaconSigno(){
    return parteimaginaria_consigno;
}
const char* Complejo::Mostrar(bool sinnombre){

    QString str;

    if(sinnombre)
        str="";
    else
        str=QChar(nombre);

    if(partereal==0&&parteimaginaria==0)
        str+="=0";
    else
        str+="="+MostrarParteReal()+MostrarParteImaginaria()+"<i>i</i>";
    return str.toStdString().c_str();
}

QString Complejo::MostrarParteReal(){

    QString str="";
    if(partereal!=0)
       str=QString::number(partereal,'f',2);

    return str;
}

QString Complejo::MostrarParteImaginaria(){

    QString str="";
    if(parteimaginaria!=0){
       if(parteimaginaria==1)
       {
        str=signo;
       }
       else{
        str=signo+QString::number(parteimaginaria,'f',2);
       }
    }
    return str;
}

Complejo Complejo::operator+(Complejo c) {
    Complejo suma;
    suma.setParteImaginariaSigno(this->parteimaginaria_consigno+c.getParteImaginariaconSigno());
    suma.setParteReal(this->partereal+c.getParteReal());
    return suma;
}
Complejo Complejo::operator*(Complejo c) {
    Complejo prod;
    prod.setParteImaginariaSigno(this->partereal*c.getParteImaginariaconSigno()+this->parteimaginaria_consigno*c.getParteReal());
    prod.setParteReal(this->partereal*c.getParteReal()-this->parteimaginaria_consigno*c.getParteImaginariaconSigno());
    return prod;
}

Complejo Complejo::operator/(Complejo c) {
    Complejo div;
    double denominadorcomun=(c.getParteReal()*c.getParteReal()+c.getParteImaginariaconSigno()*c.getParteImaginariaconSigno());
    div.setParteImaginariaSigno((this->parteimaginaria_consigno*c.getParteReal()-this->partereal*c.getParteImaginariaconSigno())/denominadorcomun);
    div.setParteReal((partereal*c.getParteReal()+parteimaginaria_consigno*c.getParteImaginariaconSigno())/denominadorcomun);

    return div;
}

Complejo Complejo::operator-(Complejo c) {
    Complejo resta;
    resta=*this+c.Opuesto();
    return resta;
}

Complejo Complejo::Opuesto() {
    Complejo op;
    op.setParteReal(partereal*-1);
    op.setParteImaginariaSigno(parteimaginaria_consigno*-1);
    return op;
}

void Complejo::CambiarSigno(){
    if(signo=='+')
        signo='-';
    else
        signo='+';
}
