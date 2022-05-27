#pragma once

#include <memory>

#include "math.hh"

class Unit : public std::enable_shared_from_this<Unit> {
public:
  vec2 position; // Relative to Tile
  ivec2 tile;
  char chr = '?';

  void MoveRel(vec2 pos);
  void MoveRel(float x, float y);
  void MoveTo(vec2 pos);
  void MoveTo(vec2 pos, ivec2 tile);
};