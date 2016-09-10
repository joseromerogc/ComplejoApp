#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtScript>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),w(1,1,'w'),y(1,1,'y'),z(1,1,'z'),operando1(0,0,'A'),operando2(0,0,'B'),
    resultado(0,0,'r')
{
    ui->setupUi(this);

    ui->w_signo->addItem("+");
    ui->w_signo->addItem("-");
    ui->w_img->setValue(1);
    ui->w_real->setValue(1);
    ui->w->setText(w.Mostrar());
    ui->y_signo->addItem("+");
    ui->y_signo->addItem("-");
    ui->y_img->setValue(1);
    ui->y_real->setValue(1);
    ui->y->setText(y.Mostrar());
    ui->z_signo->addItem("+");
    ui->z_signo->addItem("-");
    ui->z_img->setValue(1);
    ui->z_real->setValue(1);
    ui->z->setText(z.Mostrar());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_w_real_valueChanged(double partereal)
{
    w.setParteReal(partereal);
    ui->w->setText(w.Mostrar());
}

void MainWindow::on_w_img_valueChanged(double parteimaginaria)
{
    w.setParteImaginaria(parteimaginaria);
    ui->w->setText(w.Mostrar());
}

void MainWindow::on_w_signo_currentTextChanged(const QString &signo)
{
    w.setSigno(signo.toStdString().c_str()[0]);
    ui->w->setText(w.Mostrar());
}

void MainWindow::on_y_real_valueChanged(double partereal)
{
    y.setParteReal(partereal);
    ui->y->setText(y.Mostrar());
}

void MainWindow::on_y_img_valueChanged(double parteimaginaria)
{
    y.setParteImaginaria(parteimaginaria);
    ui->y->setText(y.Mostrar());
}

void MainWindow::on_y_signo_currentTextChanged(const QString &signo)
{
    y.setSigno(signo.toStdString().c_str()[0]);
    ui->y->setText(y.Mostrar());
}

void MainWindow::on_z_real_valueChanged(double partereal)
{
    z.setParteReal(partereal);
    ui->z->setText(z.Mostrar());
}

void MainWindow::on_z_img_valueChanged(double parteimaginaria)
{
    z.setParteImaginaria(parteimaginaria);
    ui->z->setText(z.Mostrar());
}

void MainWindow::on_z_signo_currentTextChanged(const QString &signo)
{
    z.setSigno(signo.toStdString().c_str()[0]);
    ui->z->setText(z.Mostrar());
}

void MainWindow::InsertarInicio(QString nombre){
    ui->label_error->setText("");
    if(nombre[0]==QChar('-'))
        ui->operacion->setText("("+nombre+")");
    else
        ui->operacion->setText(nombre);
    resultado=InsertarNumeroRef(nombre);
    resultado.setNombre('r');
    operando1=InsertarNumeroRef(nombre);;
}

void MainWindow::InsertarNumero(QString nombre){
    QString str_operacion=ui->operacion->text();

    ui->label_error->setText("");
    if(nombre[0]==QChar('-'))
        str_operacion.append("("+nombre+")");
    else
        str_operacion.append(nombre);
    ui->operacion->setText(str_operacion);
    operando2=InsertarNumeroRef(nombre);

    if(!ui->ans->text().isEmpty())
        ui->ans->setText(QString("ans")+QString(resultado.Mostrar(true)));

    CalcularOperacion();
    operando1=resultado;
    if(ui->ans->text().isEmpty())
        ui->ans->setText(QString("ans")+QString(resultado.Mostrar(true)));
    ui->resultado->setText(resultado.Mostrar());
}

Complejo MainWindow::InsertarNumeroRef(QString nombre){
    if(nombre[0]==QChar('-')){
    switch (nombre[1].toLatin1()) {
    case 'W':
        return w.Opuesto();
        break;
    case 'Y':
        return y.Opuesto();
        break;
    case 'Z':
        return z.Opuesto();
        break;
    default:
        break;
    }
    }
    else{
        switch (nombre[0].toLatin1()) {
        case 'W':
            return w;
            break;
        case 'Y':
            return y;
            break;
        case 'Z':
            return z;
            break;
        default:
            break;
        }
    }
    return resultado;
}

void MainWindow::on_pushButton_w_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("W");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("W");
            }
        }
}

void MainWindow::InsertarOperador(QString op){

QString str_operacion=ui->operacion->text();

if(str_operacion.isEmpty()){
    ui->label_error->setText("No ha seleccionado un Número");
}else{
    if(ui->resultado->text().isEmpty()){
        if(esOperador(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Número)");
        else{
            ui->label_error->setText("");
            str_operacion.append(op[0].toLatin1());
            ui->operacion->setText(str_operacion);
            operador=op[0].toLatin1();
            }
     }
    else{
        if(esOperador(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Número)");
        else{
            ui->label_error->setText("");
            ui->operacion->setText("ans"+QString(op[0]));
            operador=op[0].toLatin1();
            }
    }
    }
}

void MainWindow::on_operador_suma_clicked()
{
    InsertarOperador("+");
}

bool MainWindow::esNumero(QChar c){
    return c==QChar('r')||c==QChar('W')||c==QChar('(')||c==QChar('Y')||c==QChar('Z');
}
bool MainWindow::esOperador(QChar c){
    return c==QChar('+')||c==QChar('-')||c==QChar('*')||c==QChar('/');
}

void MainWindow::CalcularOperacion(){
    switch (operador) {
    case '+':
        resultado=operando1+operando2;
        resultado.setNombre('r');
        break;
    case '-':
        resultado=operando1-operando2;
        resultado.setNombre('r');
        break;
    case '*':
        resultado=operando1*operando2;
        resultado.setNombre('r');
        break;
    case '/':
        resultado=operando1/operando2;
        resultado.setNombre('r');
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_y_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("Y");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("Y");
            }
        }
}

void MainWindow::on_pushButton_z_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("Z");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("Z");
            }
        }
}


void MainWindow::on_pushButton_limpiar_clicked()
{
    ui->operacion->setText("");
    ui->label_error->setText("");
    ui->resultado->setText("");
    ui->ans->setText("");

    operando2.setParteImaginaria(0);
    operando2.setParteReal(0);
    operando1.setParteImaginaria(0);
    operando1.setParteReal(0);
    resultado.setParteImaginaria(0);
    resultado.setParteReal(0);
}

void MainWindow::on_pushButton_w_neg_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("-W");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("-W");
            }
        }
}


void MainWindow::on_operador_resta_clicked()
{
    InsertarOperador("-");
}

void MainWindow::on_pushButton_y_neg_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("-Y");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("-Y");
            }
        }
}

void MainWindow::on_pushButton_z_neg_clicked()
{
    QString str_operacion=ui->operacion->text();
    if(str_operacion.isEmpty()){
    InsertarInicio("-Z");
    }
    else{
        if(esNumero(str_operacion[str_operacion.size()-1]))
            ui->label_error->setText("Operación no Permitida(Selecciones un Operador)");
        else{
            InsertarNumero("-Z");
            }
        }
}

void MainWindow::on_operador_producto_clicked()
{
    InsertarOperador("*");
}

void MainWindow::on_operador_producto_2_clicked()
{
    InsertarOperador("/");
}
