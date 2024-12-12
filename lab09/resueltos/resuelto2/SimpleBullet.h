
#ifndef SIMPLEBULLET_H
#define SIMPLEBULLET_H

#include "Bullet.h"

/** SimpleBullet is the Concrete Prototype */
class SimpleBullet : public Bullet {
public:
    SimpleBullet(string bulletName, float speed, float firePower, float damagePower)
        : Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override {
        return make_unique<SimpleBullet>(*this);
    }
};

#endif // SIMPLEBULLET_H
