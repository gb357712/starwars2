#ifndef STARWARS22_BATTLE_H
#define STARWARS22_BATTLE_H

#include <cstddef>
#include "rebelfleet.h"
#include "imperialfleet.h"

class SpaceBattle{


  std::vector<std::shared_ptr<Ship>> rebelStarships;
  std::vector<std::shared_ptr<Ship>> imperialStarships;
  std::unique_ptr<Clock> const clock;

public:
  class Builder {
  public:
    Builder &ship(std::shared_ptr<Ship> const &ship);

    Builder &startTime (Time start_time);

    Builder &maxTime(Time max_time);

    SpaceBattle build();

  private:
    std::vector<std::shared_ptr<Ship>> rebelStarships;
    std::vector<std::shared_ptr<Ship>> imperialStarships;
    Time t0;
    Time t1;
  };


  SpaceBattle(std::vector<std::shared_ptr<Ship>> rebel_ships,
              std::vector<std::shared_ptr<Ship>> imperial_ships,
              std::unique_ptr<Clock> clock);
  SpaceBattle(SpaceBattle &&other) noexcept { std::move(other); }

  size_t countImperialFleet();

  size_t countRebelFleet();

  void tick(Time timeStep);
};




#endif //STARWARS22_BATTLE_H
