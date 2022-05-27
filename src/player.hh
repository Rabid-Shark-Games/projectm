#pragma once

#include <vector>

#include "unit.hh"
#include "action.hh"

class Player: public Unit {
public:
  int movespeed;

  Player();

  std::vector<PlayerAction*> actions;
};

class Fighter: public Player {
public:
  Fighter();
};

class Healer: public Player {
public:
  Healer();
};