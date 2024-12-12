
#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <unordered_map>
#include "SimpleBullet.h"
#include "GoodBullet.h"

enum BulletType {
    SIMPLE,
    GOOD
};

class BulletFactory {
private:
    unordered_map<BulletType, unique_ptr<Bullet>, hash<int>> m_Bullets;

public:
    BulletFactory() {
        m_Bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
        m_Bullets[GOOD] = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
    }

    unique_ptr<Bullet> createBullet(BulletType type) {
        return m_Bullets[type]->clone();
    }
};

#endif // BULLETFACTORY_H
