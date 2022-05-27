#pragma once

#include <string>
#include <vector>

enum class ActionReqType {
  NONE,
  MANA
};

struct ActionReq {
  ActionReqType type;
  float amount;
};

struct ActionEffect {

};

struct PlayerAction {
  std::string title;
  std::string desc;
  ActionReq req;
  std::vector<ActionEffect> effects;
};

namespace ActionEffects {
#ifdef ACTION_HH_IMPL
  ActionEffect ACT_NONE = {

  };
#else
  extern ActionEffect ACT_NONE;
#endif
}

namespace PlayerActions {
#ifdef ACTION_HH_IMPL
  PlayerAction ATK_SWORD = {
    "Attack with Sword",
    "Deal 4-5 damage with a sword.",
    {
      ActionReqType::NONE,
      0
    },
    {ActionEffects::ACT_NONE}
  };
  PlayerAction ATK_PUNCH = {
    "Punch",
    "Deal 1-2 damage with a punch.",
    {
      ActionReqType::NONE,
      0
    },
    {ActionEffects::ACT_NONE}
  };
  PlayerAction HEA_HEAL = {
    "Heal",
    "Heal a unit 4-5 health.",
    {
      ActionReqType::NONE,
      0
    },
    {ActionEffects::ACT_NONE}
  };
#else
  extern PlayerAction ATK_SWORD;
  extern PlayerAction ATK_PUNCH;
  extern PlayerAction HEA_HEAL;
#endif
}
