#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addCountryButton_clicked();
    void on_editButton_clicked(QWidget* countryWidget);
    void on_removeButton_clicked(QWidget* countryWidget);

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;  // Layout para las filas de país-capital
    QPushButton *addCountryButton;
};

#endif // MAINWINDOW_H
