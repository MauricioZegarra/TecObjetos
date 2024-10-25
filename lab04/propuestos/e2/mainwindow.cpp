#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), infoLabel(new QLabel("Seleccione un país", this)), countryList(new QListWidget(this)) {

    // Configuración del centralWidget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Configuración del QListWidget
    countryList->addItem("México");
    countryList->addItem("España");
    countryList->addItem("Francia");
    countryList->addItem("Alemania");
    countryList->addItem("Japón");

    // Configuración de la QLabel
    infoLabel->setAlignment(Qt::AlignCenter);

    // Configuración del layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(countryList);
    layout->addWidget(infoLabel);
    centralWidget->setLayout(layout);

    // Datos de los países
    countryData["México"] = "Idioma: Español, Capital: Ciudad de México";
    countryData["España"] = "Idioma: Español, Capital: Madrid";
    countryData["Francia"] = "Idioma: Francés, Capital: París";
    countryData["Alemania"] = "Idioma: Alemán, Capital: Berlín";
    countryData["Japón"] = "Idioma: Japonés, Capital: Tokio";

    // Conexión de la señal
    connect(countryList, &QListWidget::itemClicked, [=](QListWidgetItem *item) {
        QString country = item->text();
        infoLabel->setText(countryData.value(country, "Información no disponible"));
    });
}

MainWindow::~MainWindow() {
}
