
#include "BulletFactory.h"

int main() {
    BulletFactory bulletFactory;

    auto bullet = bulletFactory.createBullet(SIMPLE);
    bullet->fire(90);

    bullet = bulletFactory.createBullet(GOOD);
    bullet->fire(100);

    return 0;
}
