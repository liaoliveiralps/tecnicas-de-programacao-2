#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <matriz.h>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCriarMatA_clicked();

    void on_pushButtonCriarMatB_clicked();

    void on_pushButtonAdicionar_clicked();

    void on_pushButton_clicked();

    void on_pushButtonMulti_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonTranspostaB_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonConstanteB_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    lia::Matriz *matA;
    lia::Matriz *matB;
};
#endif // MAINWINDOW_H
