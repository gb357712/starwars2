#ifndef __REBEL_FLEET_H__
#define __REBEL_FLEET_H__

#include "imperialfleet.h"

typedef int Speed;

class RebelStarship {
private:
  ShieldPoints shieldPoints;
  Speed speed;

public:
  RebelStarship (ShieldPoints shield, Speed speed);

  virtual ShieldPoints getShield() const;
  virtual Speed getSpeed() const;
  virtual void takeDamage(AttackPower damage);
};



class AttackingRebelStarship : public RebelStarship {
private:
  AttackPower attackPower;

public:
  AttackingRebelStarship (ShieldPoints shield, Speed speed, AttackPower attackPower);
  virtual AttackPower getAttackPower() const;
};

class Explorer: public RebelStarship {
public:
  Explorer (ShieldPoints shield, Speed speed);
};

class StarCruiser: public AttackingRebelStarship {
public:
  StarCruiser (ShieldPoints shield, Speed speed, AttackPower attackPower);
};

class XWing: public AttackingRebelStarship {
public:
  XWing (ShieldPoints shield, Speed speed, AttackPower attackPower);
};

#endif /* __REBEL_FLEET_H__ */