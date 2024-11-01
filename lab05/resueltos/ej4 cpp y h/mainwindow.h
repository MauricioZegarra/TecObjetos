#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include "task.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void removeTask(Task *task);

private:
    QLabel *statusLabel;
    QPushButton *addTaskButton;
    QVBoxLayout *tasksLayout;
    QVector<Task*> mTasks;
};

#endif // MAINWINDOW_H

