#ifndef STARWARS22_REBELFLEET_H
#define STARWARS22_REBELFLEET_H

#include "helper.h"
#include <cassert>
#include <memory>


class RebelStarship : public Ship {
private:
  Speed speed;

public:
  RebelStarship(ShieldPoints shield, Speed speed);

  bool isImperialShip() override;

  virtual Speed getSpeed() const;

  size_t getCount() override;
};

class AttackingRebelStarship : public RebelStarship {
private:
  AttackPower attackPower;

public:
  AttackingRebelStarship(ShieldPoints shield, Speed speed, AttackPower attackPower);

  virtual AttackPower getAttackPower() override;

};

class Explorer : public RebelStarship {
public:
  Explorer(ShieldPoints shield, Speed speed);
};

class StarCruiser : public AttackingRebelStarship {
public:
  StarCruiser(ShieldPoints shield, Speed speed, AttackPower attackPower);
};

class XWing : public AttackingRebelStarship {
public:
  XWing(ShieldPoints shield, Speed speed, AttackPower attackPower);
};

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attackPower);

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attackPower);

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed);

#endif //STARWARS22_REBELFLEET_H
