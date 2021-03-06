#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMap>
#include <QTimer>
#include <QMainWindow>

#include <QtSensors/QTiltSensor>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int w = 220, h = 220;
    int rest;

    // + TUTAJ DEFINIUJE SIE ROZDZIELCZOSC
    typedef MatrixXi MyMatrix;
    MyMatrix spinTable, neighTable, tempForShifting;
    QRgb valA, valB;
    QImage imgMono, imgRGB;
    QMap <int, double> boltzmanMap;
    QMap <int, int> tiltMap;

    void initEverything();

    void initNeighBors();
    void initButtons();

    void eigenToQImage(const MyMatrix&, QImage&);
    void eigenToQImageRGB(const MyMatrix&, QImage&);
    void eigenToQImageRGBC(const MyMatrix&, QImage&);

    void initTiltMap();
    void calcProbabilities();

public:
    explicit MainWindow(QWidget *parent = 0);

    void whyNoTest();
    ~MainWindow();
public slots:
    void shiftSomeRows();
    void shiftSomeCols();
    void initFlipMaybe();
    void initSpinTable();

    void increaseHeat();
    void decreaseHeat();
    void increaseCoupling();
    void decreaceCoupling();

private:
    Ui::MainWindow *ui;
    QTimer *timerTest;
    QTimer *shiftingTimerRows;
    QTimer *shiftingTimerCols;
    double J,T;
    int k;
    QTiltSensor *tiltSensor;
    int rotX, rotY;

};

#endif // MAINWINDOW_H
