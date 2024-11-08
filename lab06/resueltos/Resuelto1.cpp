#include <stdlib.h>
#include <pthread.h>
#include <ctime>
#include <QDebug>

void* procesoHilo(void* dato) {
    struct timespec tm = {1, 0};

    while (true) {
        qDebug() << "proceso";
        nanosleep(&tm, NULL);
    }

    return nullptr;
}

int main() {
    pthread_t proceso1;
    pthread_t proceso2;


    pthread_create(&proceso1, NULL, procesoHilo, NULL);
    pthread_create(&proceso2, NULL, procesoHilo, NULL);


    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);

    return 0;
}
