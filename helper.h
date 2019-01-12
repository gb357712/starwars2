#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

#include <memory>
#include "rebelfleet.h"
#include "imperialfleet.h"

using Time = int;

class Clock{
private:
  Time current_time;
  Time t1;
public:
  Clock(Time startTime, Time t1);
  bool tick(Time timestamp); //zwraca bool czy mozna wykonac atak i nastepnie przesuwa zegar
};


std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield, Speed speed, AttackPower attackPower);
std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attackPower);
std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield, Speed speed);

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield, AttackPower attackPower);
std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield, AttackPower attackPower);
std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield, AttackPower attackPower);

std::shared_ptr<ImperialStarship> createSquadron(std::initializer_list<std::shared_ptr<ImperialStarship>> ships);





#endif //STARWARS2_HELPER_H
