
#ifndef GOODBULLET_H
#define GOODBULLET_H

#include "Bullet.h"

/** GoodBullet is the Concrete Prototype */
class GoodBullet : public Bullet {
public:
    GoodBullet(string bulletName, float speed, float firePower, float damagePower)
        : Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override {
        return make_unique<GoodBullet>(*this);
    }
};

#endif // GOODBULLET_H
