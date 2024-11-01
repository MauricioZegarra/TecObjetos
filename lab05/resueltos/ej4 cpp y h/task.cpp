#include "task.h"

Task::Task(QWidget *parent) : QWidget(parent) {
    checkbox = new QCheckBox("Tarea");
    QPushButton *editButton = new QPushButton("Editar");
    removeButton = new QPushButton("Quitar");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(checkbox);
    layout->addWidget(editButton);    // Agrega el botón "Editar"
    layout->addWidget(removeButton);

    // Conectar el botón de quitar a la función que emite la señal de eliminación
    connect(removeButton, &QPushButton::clicked, this, &Task::onRemoveClicked);
}

void Task::onRemoveClicked() {
    emit removeTask(this);
}
