#include "comunicacion.h"

Comunicacion::Comunicacion(const QString &nombre, QObject *parent)
    : QObject(parent), nombre(nombre) {}

void Comunicacion::enviar(const QString &mensaje) {
    qDebug() << nombre << "envía:" << mensaje;
    emit enviarMensaje(nombre + " dice: " + mensaje);
}

void Comunicacion::recibirMensaje(const QString &mensaje) {
    qDebug() << nombre << "recibe:" << mensaje;
}


