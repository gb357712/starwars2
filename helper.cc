//
// Created by gabriel on 13.01.19.
//

#include "helper.h"


Ship::Ship(ShieldPoints shieldPoints) : shieldPoints(shieldPoints) {}

void Ship::takeDamage(AttackPower damage) {
  shieldPoints = (shieldPoints < damage) ? 0 : shieldPoints - damage;
}

ShieldPoints Ship::getShield() const {
  return shieldPoints;
}


bool Ship::isDestroyed() {
  return shieldPoints==0;
}

AttackPower Ship::getAttackPower() {
  return 0;
}

Clock::Clock(Time startTime, Time t1): current_time(startTime), t1(t1) {}

bool DefaultClock::isAttackTime() const {
  return (current_time % 2 == 0 || current_time % 3 == 0 )&& current_time % 5 != 0;
}

void DefaultClock::tick(Time timestamp) {
  current_time= current_time=(current_time+timestamp)%(t1+1);
}

DefaultClock::DefaultClock(Time startTime, Time t1) : Clock(startTime, t1) {}

