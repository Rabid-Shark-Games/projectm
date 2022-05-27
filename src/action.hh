#pragma once

#include <string>

struct PlayerAction {
  std::string title;
  std::string desc;
};

namespace PlayerActions {
#ifdef ACTION_HH_IMPL
  PlayerAction ATK_SWORD = {
    "Attack with Sword",
    "Deal 4-5 damage with a sword."
  };
  PlayerAction ATK_PUNCH = {
    "Punch",
    "Deal 1-2 damage with a punch."
  };
  PlayerAction HEA_HEAL = {
    "Heal",
    "Heal a unit 4-5 health."
  };
#else
  extern PlayerAction ATK_SWORD;
  extern PlayerAction ATK_PUNCH;
  extern PlayerAction HEA_HEAL;
#endif
}
