#ifndef STARWARS22_IMPERIALFLEET_H
#define STARWARS22_IMPERIALFLEET_H


#include <vector>
#include "helper.h"
#include <memory>

class ImperialStarship : public Ship {

protected:
  AttackPower attackPower;
public:
  ImperialStarship (ShieldPoints shield, AttackPower attack);
  virtual bool isImperialShip() override;
  virtual size_t getCount() override;
  virtual AttackPower getAttackPower() override;
};

class DeathStar: public ImperialStarship {
public:
  DeathStar (ShieldPoints shield, AttackPower attack);
};

class ImperialDestroyer: public ImperialStarship {
public:
  ImperialDestroyer (ShieldPoints shield, AttackPower attackPower);
};

class TIEFighter: public ImperialStarship {
public:
  TIEFighter (ShieldPoints shield, AttackPower attackPower);
};

class Squadron : public ImperialStarship {
private:
  std::vector<std::shared_ptr<ImperialStarship>> imperialShips;
public:

  explicit Squadron(std::vector<std::shared_ptr<ImperialStarship>> ships);
  void takeDamage(AttackPower damage) override;
  bool isDestroyed() override;
  size_t getCount() override;
  ShieldPoints getShield() const override;
  AttackPower getAttackPower() override;

};

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield, AttackPower attackPower);
std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield, AttackPower attackPower);
std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield, AttackPower attackPower);

std::shared_ptr<ImperialStarship> createSquadron(std::initializer_list<std::shared_ptr<ImperialStarship>> ships);





#endif //STARWARS22_IMPERIALFLEET_H
