#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMap>
#include "comunicacion.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClicked();
    void updateStatus(const QString &message);

private:
    QPushButton *addTaskButton;
    QLabel *statusLabel;
    Comunicacion *persona1;
    Comunicacion *persona2;
};

#endif // MAINWINDOW_H



