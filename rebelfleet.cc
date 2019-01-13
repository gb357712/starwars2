//
// Created by gabriel on 13.01.19.
//

#include "rebelfleet.h"

RebelStarship::RebelStarship(ShieldPoints shield, Speed speed) : Ship(shield), speed(speed) {}

Speed RebelStarship::getSpeed() const {
  return speed;
}

bool RebelStarship::isImperialShip() {
  return false;
}

size_t RebelStarship::getCount() {
  return isDestroyed() ? 0 : 1;
}


AttackPower AttackingRebelStarship::getAttackPower() {
  return attackPower;
}


AttackingRebelStarship::AttackingRebelStarship(ShieldPoints shield, Speed speed, AttackPower attackPower)
  : RebelStarship(shield, speed), attackPower(attackPower) {}


Explorer::Explorer(ShieldPoints shield, Speed speed)
  : RebelStarship(shield, speed) {
  assert (speed >= 299796 && speed <= 2997960);
}

StarCruiser::StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack)
  : AttackingRebelStarship(shield, speed, attack) {
  assert (speed >= 99999 && speed <= 299795);
}

XWing::XWing(ShieldPoints shield, Speed speed, AttackPower attack)
  : AttackingRebelStarship(shield, speed, attack) {
  assert (speed >= 299796 && speed <= 2997960);
}

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attackPower) {
  std::shared_ptr<RebelStarship> ship = std::make_shared<XWing>(shield, speed, attackPower);
  return ship;
}

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attackPower) {
  std::shared_ptr<RebelStarship> ship = std::make_shared<StarCruiser>(shield, speed, attackPower);
  return ship;
}

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed) {
  std::shared_ptr<RebelStarship> ship = std::make_shared<Explorer>(shield, speed);
  return ship;
}