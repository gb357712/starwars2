#include "imperialfleet.h"

ImperialStarship::ImperialStarship (ShieldPoints shield, AttackPower attack) 
  : shieldPoints(shield), attackPower(attack)
  {}
  
DeathStar::DeathStar (ShieldPoints shield, AttackPower attack) 
  : ImperialStarship(shield, attack)
  {}
  
ImperialDestroyer::ImperialDestroyer (ShieldPoints shield, AttackPower attack) 
  : ImperialStarship(shield, attack)
  {}
  
TIEFighter::TIEFighter (ShieldPoints shield, AttackPower attack) 
  : ImperialStarship(shield, attack)
  {}
  
ShieldPoints ImperialStarship::getShield() const {
  return shieldPoints;
}

void ImperialStarship::takeDamage(AttackPower damage) {
  shieldPoints = (shieldPoints < damage) ? 0 : shieldPoints - damage;
}

AttackPower ImperialStarship::getAttackPower() const {
  return attackPower;
}

Squadron::Squadron (std::vector<ImperialStarship> ships) : ImperialStarship(0, 0) {
  for (auto it = ships.begin(); it != ships.end(); ++it) {
    imperialShips.emplace_back(*it);
    shieldPoints += it -> getShield();
    attackPower += it -> getAttackPower();
  }
}

Squadron::Squadron (std::initializer_list<ImperialStarship> ships) : ImperialStarship(0, 0) {
  for (auto it = ships.begin(); it != ships.end(); ++it) {
    imperialShips.emplace_back(*it);
    shieldPoints += it -> getShield();
    attackPower += it -> getAttackPower();
  }
}

void Squadron::takeDamage(AttackPower damage) {
  auto it = imperialShips.begin();
  while (it != imperialShips.end()) {
    if (it -> getShield() <= damage) {
      attackPower -= it -> getAttackPower();
      shieldPoints -= it -> getShield();
      it = imperialShips.erase(it);
    }
    else {
      it -> takeDamage(damage);
      shieldPoints -= damage;
      ++it;
    }
  }
}
