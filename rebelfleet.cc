#include "rebelfleet.h"
#include <cassert>

RebelStarship::RebelStarship (ShieldPoints shield, Speed speed) 
  : shieldPoints(shield), speed(speed) 
  {}
  
AttackingRebelStarship::AttackingRebelStarship (ShieldPoints shield, Speed speed, AttackPower attack)
  : RebelStarship(shield, speed), attackPower(attack)
  {}
  
Explorer::Explorer (ShieldPoints shield, Speed speed) 
  : RebelStarship(shield, speed) {
    assert (speed >= 299796 && speed <= 2997960);
}

StarCruiser::StarCruiser (ShieldPoints shield, Speed speed, AttackPower attack) 
  : AttackingRebelStarship(shield, speed, attack) {
    assert (speed >= 99999 && speed <= 299795);
}
  
XWing::XWing (ShieldPoints shield, Speed speed, AttackPower attack)
  : AttackingRebelStarship(shield, speed, attack) {
    assert (speed >= 299796 && speed <= 2997960);
}

ShieldPoints RebelStarship::getShield() const {
  return shieldPoints;
}

Speed RebelStarship::getSpeed() const {
  return speed;
}

void RebelStarship::takeDamage(AttackPower damage) {
  shieldPoints = (shieldPoints < damage) ? 0 : shieldPoints - damage;
}

AttackPower AttackingRebelStarship::getAttackPower() const {
  return attackPower;
}
