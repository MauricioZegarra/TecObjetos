#include "mainwindow.h"
#include <QInputDialog>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Crear el widget central y el layout principal
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    // Crear el layout horizontal superior para "Lista de países" y "Agregar país"
    QHBoxLayout *topLayout = new QHBoxLayout();

    // Crear el QLabel "Lista de países" y el botón "Agregar país"
    QLabel *listLabel = new QLabel("Lista de países", this);
    addCountryButton = new QPushButton("Agregar país", this);

    // Añadir el QLabel y el botón al layout horizontal
    topLayout->addWidget(listLabel);
    topLayout->addStretch();  // Añade un espacio flexible para separar los elementos
    topLayout->addWidget(addCountryButton);

    // Añadir el layout superior al layout principal
    mainLayout->addLayout(topLayout);

    // Conectar el botón "Agregar país" a su slot correspondiente
    connect(addCountryButton, &QPushButton::clicked, this, &MainWindow::on_addCountryButton_clicked);
}

MainWindow::~MainWindow() {
    delete addCountryButton;
    delete mainLayout;
    delete centralWidget;
}

void MainWindow::on_addCountryButton_clicked() {
    // Crea una nueva fila con checkbox, texto de país-capital, y botones Editar y Quitar
    QWidget *countryWidget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(countryWidget);

    QCheckBox *checkBox = new QCheckBox();
    QLabel *label = new QLabel("Perú - Lima");
    QPushButton *editButton = new QPushButton("Editar");
    QPushButton *removeButton = new QPushButton("Quitar");

    layout->addWidget(checkBox);
    layout->addWidget(label);
    layout->addWidget(editButton);
    layout->addWidget(removeButton);

    countryWidget->setLayout(layout);
    mainLayout->addWidget(countryWidget);

    // Conectar señales para los botones
    connect(editButton, &QPushButton::clicked, this, [=]() { on_editButton_clicked(countryWidget); });
    connect(removeButton, &QPushButton::clicked, this, [=]() { on_removeButton_clicked(countryWidget); });
}

void MainWindow::on_editButton_clicked(QWidget *countryWidget) {
    // Permitir editar el nombre de país y capital
    QLabel *label = countryWidget->findChild<QLabel *>();
    if (label) {
        QString text = label->text();
        QStringList parts = text.split(" - ");
        QString country = parts.value(0, "País");
        QString capital = parts.value(1, "Capital");

        // Obtener nueva entrada de usuario
        bool ok;
        QString newCountry = QInputDialog::getText(this, "Editar País", "Nombre del País:", QLineEdit::Normal, country, &ok);
        if (ok && !newCountry.isEmpty()) {
            QString newCapital = QInputDialog::getText(this, "Editar Capital", "Nombre de la Capital:", QLineEdit::Normal, capital, &ok);
            if (ok && !newCapital.isEmpty()) {
                label->setText(newCountry + " - " + newCapital);
            }
        }
    }
}

void MainWindow::on_removeButton_clicked(QWidget *countryWidget) {
    // Remover la fila de país-capital
    mainLayout->removeWidget(countryWidget);
    countryWidget->deleteLater();
}
