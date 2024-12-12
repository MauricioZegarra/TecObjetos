
#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <memory>
#include <string>
using namespace std;

/** Bullet is the base Prototype */
class Bullet {
protected:
    string _bulletName;
    float _speed;
    float _firePower;
    float _damagePower;
    float _direction;

public:
    Bullet(string bulletName, float speed, float firePower, float damagePower)
        : _bulletName(bulletName), _speed(speed), _firePower(firePower), _damagePower(damagePower) {}

    virtual ~Bullet() = default;

    virtual unique_ptr<Bullet> clone() = 0;

    void fire(float direction) {
        _direction = direction;
        cout << "Name       : " << _bulletName << endl
             << "Speed      : " << _speed << endl
             << "FirePower  : " << _firePower << endl
             << "DamagePower: " << _damagePower << endl
             << "Direction  : " << _direction << endl;
    }
};

#endif // BULLET_H
