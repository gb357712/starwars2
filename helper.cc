#include "helper.h"


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
  std::vector<ImperialStarship> temp;
  for (auto it = ships.begin(); it != ships.end(); ++it) {
  temp.push_back(*(*it));
  }
  std::shared_ptr<ImperialStarship> ship = std::make_shared<Squadron>(temp);
}


Clock::Clock(Time startTime, Time t1): current_time(startTime),  t1(t1) {}

bool Clock::tick(Time timestamp) {
  bool result = current_time % 2 == 0 && current_time % 3 == 0 && current_time % 5 != 0;
  current_time=(current_time+timestamp)%(t1+1);
  return result;
}
