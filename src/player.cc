#include "player.hh"

Player::Player() {
  chr = '@';
}

Fighter::Fighter() {
  movespeed = 1;
  actions.push_back(&PlayerActions::ATK_SWORD);
  actions.push_back(&PlayerActions::ATK_PUNCH);
}

Healer::Healer() {
  movespeed = 2; // Maybe a higher speed to allow running around & healing.
  actions.push_back(&PlayerActions::ATK_PUNCH);
  actions.push_back(&PlayerActions::HEA_HEAL);
}