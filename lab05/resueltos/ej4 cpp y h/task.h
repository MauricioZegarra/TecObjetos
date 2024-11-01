#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>

class Task : public QWidget {
    Q_OBJECT
public:
    explicit Task(QWidget *parent = nullptr);

signals:
    void removeTask(Task *task);

private slots:
    void onRemoveClicked();

private:
    QCheckBox *checkbox;
    QPushButton *removeButton;
};

#endif // TASK_H
