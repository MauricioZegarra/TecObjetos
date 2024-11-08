#include <thread>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>
#include <QDebug>
#include <QCoreApplication>
#include <vector>

// Función de procesamiento secuencial
void FindPrimesWithoutThreads(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            } else if ((y + 1) == x) {
                vect.push_back(x);
            }
        }
    }
}

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start, unsigned int end) {
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            } else if ((y + 1) == x) {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads) {
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }

    for (auto& t : threadVect) {
        t.join();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // SIN HILOS
    std::vector<unsigned int> primeVect;

    int startTime = clock();
    FindPrimesWithoutThreads(1, 1000000, primeVect);
    int endTime = clock();
    qDebug() << "Execution Time :" << (endTime - startTime) / double(CLOCKS_PER_SEC) << Qt::endl;

    // CON HILOS
    startTime = clock();
    FindPrimesWithThreads(1, 1000000, 8);
    endTime = clock();
    qDebug() << "Execution Time :" << (endTime - startTime) / double(CLOCKS_PER_SEC) << Qt::endl;

    return a.exec();
}
