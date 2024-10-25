#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Crear elementos gráficos
    setWindowTitle("Ejercicio GUI");
    resize(400, 200);

    addTaskButton = new QPushButton("Agregar tarea", this);
    addTaskButton->setGeometry(50, 50, 100, 30);
    statusLabel = new QLabel("Status: Esperando...", this);
    statusLabel->setGeometry(50, 100, 300, 30);

    persona1 = new Comunicacion("Persona 1", this);
    persona2 = new Comunicacion("Persona 2", this);

    // Conectar señal y slot para comunicación
    connect(addTaskButton, &QPushButton::clicked, this, &MainWindow::handleButtonClicked);
    connect(persona1, &Comunicacion::enviarMensaje, persona2, &Comunicacion::recibirMensaje);
    connect(persona2, &Comunicacion::enviarMensaje, this, &MainWindow::updateStatus);

    qDebug() << "MainWindow creada";
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow destruida";
    delete addTaskButton;
    delete statusLabel;
}

void MainWindow::handleButtonClicked() {
    persona1->enviar("Hola desde Persona 1");
}

void MainWindow::updateStatus(const QString &message) {
    statusLabel->setText("Status: " + message);
}
