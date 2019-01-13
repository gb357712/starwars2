//
// Created by gabriel on 13.01.19.
//

#include "imperialfleet.h"

ImperialStarship::ImperialStarship (ShieldPoints shield, AttackPower attack)
  : Ship(shield), attackPower(attack)
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


bool ImperialStarship::isImperialShip() {
  return true;
}

size_t ImperialStarship::getCount() {
  return 1;
}

AttackPower ImperialStarship::getAttackPower() {
  return isDestroyed()? 0 : attackPower;
}

Squadron::Squadron(std::vector<std::shared_ptr<ImperialStarship>> ships) :ImperialStarship(0,0), imperialShips(std::move(ships)) {
  for (auto const &ship : imperialShips)
    attackPower += ship->getAttackPower();
}

ShieldPoints Squadron::getShield() const {
  ShieldPoints sum_of_shields = 0;

  for (auto const &ship : imperialShips)
    sum_of_shields += ship->getShield();

  return sum_of_shields;
}

AttackPower Squadron::getAttackPower() {
  attackPower=0;
  for (auto const &ship : imperialShips)
    attackPower += ship->getAttackPower();
  return attackPower;
}

void Squadron::takeDamage(AttackPower damage) {
  for (auto const &ship : imperialShips)
    ship->takeDamage(damage);
}

bool Squadron::isDestroyed() {
  for(const auto &it : imperialShips)
    if(!it->isDestroyed())
      return false;
  return true;
}

size_t Squadron::getCount() {
  size_t count = 0;
  for (auto it : imperialShips)
    count += it->getCount();
  return count;
}


std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield, AttackPower attackPower) {
  std::shared_ptr<ImperialStarship> ship = std::make_shared<TIEFighter>(shield, attackPower);
  return ship;
}

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield, AttackPower attackPower) {
  std::shared_ptr<ImperialStarship> ship = std::make_shared<ImperialDestroyer>(shield, attackPower);
  return ship;
}

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield, AttackPower attackPower) {
  std::shared_ptr<ImperialStarship> ship = std::make_shared<DeathStar>(shield, attackPower);
  return ship;
}

std::shared_ptr<ImperialStarship> createSquadron(std::initializer_list<std::shared_ptr<ImperialStarship>> ships) {
  return std::make_shared<Squadron>(ships);
}
