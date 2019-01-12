#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <cstddef>
#include "rebelfleet.h"
#include "imperialfleet.h"
#include "helper.h"

//niezaimplementowane
class SpaceBattle{
private:
public:
  size_t countImperialFleet() const;
  size_t countRebelFleet() const;
  void tick(Time timestamp);
};



#endif //STARWARS2_BATTLE_H
