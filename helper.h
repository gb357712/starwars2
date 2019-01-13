#ifndef STARWARS22_HELPER_H
#define STARWARS22_HELPER_H


#include <cstddef>

using ShieldPoints = int;
using AttackPower = int;
using Speed = int;
using Time = int;

class Ship {
protected:
  ShieldPoints shieldPoints;
public:
  explicit Ship(ShieldPoints shieldPoints);

  virtual void takeDamage(AttackPower damage);

  virtual ShieldPoints getShield() const;

  virtual bool isDestroyed();

  virtual bool isImperialShip() = 0;

  virtual size_t getCount() = 0;

  virtual AttackPower getAttackPower();
};

class Clock {
protected:
  Time current_time;
  Time t1;
public:
  Clock(Time startTime, Time t1);

  virtual bool isAttackTime() const = 0;

  virtual void tick(Time timestamp) = 0; //zwraca bool czy mozna wykonac atak i nastepnie przesuwa zegar
};

class DefaultClock : public Clock {
public:
  bool isAttackTime() const override;

  void tick(Time timestamp) override;

  DefaultClock(Time startTime, Time t1);

};


#endif //STARWARS22_HELPER_H
