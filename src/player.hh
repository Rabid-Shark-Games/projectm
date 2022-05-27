#pragma once

#include <vector>

#include "unit.hh"
#include "action.hh"

class Player: public Unit {
public:
  int movespeed;

  Player();
  virtual ~Player() = default;

  std::vector<PlayerAction*> actions;
};

class HasMana: public Player {
public:
  float mana;
};

class Fighter: public Player {
public:
  Fighter();
};

class Healer: public HasMana {
public:
  Healer();
};