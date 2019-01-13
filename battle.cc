#include <iostream>
#include "battle.h"

size_t SpaceBattle::countImperialFleet() {
  size_t num_ships = 0;
  for (const auto &s : imperialStarships)
    num_ships += s->getCount();

  return num_ships;
}

size_t SpaceBattle::countRebelFleet() {
  size_t num_ships = 0;
  for (const auto &s : rebelStarships)
    num_ships += s->getCount();

  return num_ships;
}

void SpaceBattle::tick(Time timeStep) {

  if (countImperialFleet() == 0 && countRebelFleet() == 0) {
    std::cout << "DRAW" << std::endl;
    return;
  }

  if (countImperialFleet() == 0) {
    std::cout << "REBELLION WON" << std::endl;
    return;
  }

  if (countRebelFleet() == 0) {
    std::cout << "IMPERIUM WON" << std::endl;
    return;
  }

  if (clock->isAttackTime()) {
    for (auto const &impShip : imperialStarships) {
      if (!impShip->isDestroyed()) {
        for (auto const &rebShip : rebelStarships) {
          if (!rebShip->isDestroyed()) {
            rebShip->takeDamage(impShip->getAttackPower());
            impShip->takeDamage(rebShip->getAttackPower());
          }

        }
      }
    }
  }

  clock->tick(timeStep);
}

SpaceBattle::SpaceBattle(std::vector<std::shared_ptr<Ship>> rebel_ships,
                         std::vector<std::shared_ptr<Ship>> imperial_ships, std::unique_ptr<Clock> clock) :
  rebelStarships(std::move(rebel_ships)), imperialStarships(std::move(imperial_ships)),
  clock(std::move(clock)) {}

SpaceBattle::Builder &SpaceBattle::Builder::ship(std::shared_ptr<Ship> const &ship) {
  if (ship->isImperialShip())
    imperialStarships.push_back(ship);
  else
    rebelStarships.push_back(ship);

  return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::startTime(Time start_time) {
  assert(start_time >= 0);
  t0 = start_time;
  return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::maxTime(Time max_time) {
  assert(max_time >= 0);
  t1 = max_time;
  return *this;
}

SpaceBattle SpaceBattle::Builder::build() {
  std::unique_ptr<Clock> clockPtr = std::make_unique<DefaultClock>(t0, t1);
  return SpaceBattle{std::move(rebelStarships), std::move(imperialStarships), std::move(clockPtr)};
}

