#ifndef __IMPERIAL_FLEET_H__
#define __IMPERIAL_FLEET_H__

#include <vector>
#include <list>

using ShieldPoints = int;
using AttackPower = int;

class ImperialStarship {
  protected:
    ShieldPoints shieldPoints;
    AttackPower attackPower;
  
  public:
    ImperialStarship (ShieldPoints shield, AttackPower attack);
    
    virtual ShieldPoints getShield() const;
    virtual AttackPower getAttackPower() const;
    virtual void takeDamage(AttackPower damage);
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
    std::list<ImperialStarship> imperialShips;
  public:
    Squadron (std::vector<ImperialStarship> ships);
    Squadron (std::initializer_list<ImperialStarship> ships);
    void takeDamage(AttackPower damage) override;
};

#endif /* __IMPERIAL_FLEET_H__ */
