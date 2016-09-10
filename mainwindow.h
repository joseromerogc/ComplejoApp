#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Complejo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool esNumero(QChar c);
    bool esOperador(QChar c);
    void CalcularOperacion();
    void InsertarInicio(QString nombre);
    void InsertarNumero(QString nombre);
    Complejo InsertarNumeroRef(QString nombre);
    void InsertarOperador(QString op);
private slots:
    void on_w_real_valueChanged(double arg1);
    void on_w_img_valueChanged(double arg1);
    void on_w_signo_currentTextChanged(const QString &arg1);
    void on_y_real_valueChanged(double arg1);
    void on_y_img_valueChanged(double arg1);
    void on_y_signo_currentTextChanged(const QString &arg1);
    void on_z_real_valueChanged(double arg1);
    void on_z_img_valueChanged(double arg1);
    void on_z_signo_currentTextChanged(const QString &arg1);

    void on_pushButton_w_clicked();

    void on_operador_suma_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_z_clicked();

    void on_pushButton_limpiar_clicked();

    void on_pushButton_w_neg_clicked();


    void on_operador_resta_clicked();

    void on_pushButton_y_neg_clicked();

    void on_pushButton_z_neg_clicked();

    void on_operador_producto_clicked();

    void on_operador_producto_2_clicked();

private:
    Ui::MainWindow *ui;
    Complejo w,y,z, operando1, operando2, resultado;
    char operador;

};

#endif // MAINWINDOW_H
