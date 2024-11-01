#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Configuración de la ventana principal
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Crear los elementos de la interfaz
    statusLabel = new QLabel("Checklist de tareas");
    addTaskButton = new QPushButton("Agregar tarea");

    // Disposición horizontal para el label y botón
    QHBoxLayout *headerLayout = new QHBoxLayout;
    headerLayout->addWidget(statusLabel);
    headerLayout->addWidget(addTaskButton);

    // Layout vertical principal para todas las tareas
    tasksLayout = new QVBoxLayout;

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addLayout(headerLayout);  // Agrega el header
    mainLayout->addLayout(tasksLayout);   // Agrega las tareas

    // Conexión del botón para añadir tareas
    connect(addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow() {}

void MainWindow::addTask() {
    Task *task = new Task(this);
    tasksLayout->addWidget(task);
    mTasks.append(task);

    // Conectar la señal de quitar tarea al slot de eliminación
    connect(task, &Task::removeTask, this, &MainWindow::removeTask);
}

void MainWindow::removeTask(Task *task) {
    tasksLayout->removeWidget(task);
    mTasks.removeOne(task);
    task->deleteLater();
}
