#ifndef COMUNICACIÓN_H
#define COMUNICACIÓN_H

#include <QObject>
#include <QString>
#include <QDebug>

class Comunicacion : public QObject {
    Q_OBJECT

public:
    explicit Comunicacion(const QString &nombre, QObject *parent = nullptr);

signals:
    void enviarMensaje(const QString &mensaje);

public slots:
    void enviar(const QString &mensaje);
    void recibirMensaje(const QString &mensaje);

private:
    QString nombre;
};

#endif // COMUNICACION_H

