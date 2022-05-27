#include "unit.hh"
#include "map.hh"

void Unit::MoveTo(vec2 pos) {
  this->position = pos;
  if (this->position.x < 0) {
    this->position.x += TILE_WIDTH;
    ivec2 v;
    v.x = this->tile.x - 1;
    v.y = this->tile.y;
    this->MoveTo(this->position, v);
  }
  if (this->position.y < 0) {
    this->position.y += TILE_HEIGHT;
    ivec2 v;
    v.x = this->tile.x;
    v.y = this->tile.y - 1;
    this->MoveTo(this->position, v);
  }
  if (this->position.x >= TILE_WIDTH) {
    this->position.x -= TILE_WIDTH;
    ivec2 v;
    v.x = this->tile.x + 1;
    v.y = this->tile.y;
    this->MoveTo(this->position, v);
  }
  if (this->position.y >= TILE_HEIGHT) {
    this->position.y -= TILE_WIDTH;
    ivec2 v;
    v.x = this->tile.x;
    v.y = this->tile.y + 1;
    this->MoveTo(this->position, v);
  }
}

void Unit::MoveRel(vec2 pos) {
  this->position.x += pos.x;
  this->position.y += pos.y;
  Unit::MoveTo(this->position);
}

void Unit::MoveRel(float x, float y) {
  this->position.x += x;
  this->position.y += y;
  Unit::MoveTo(this->position);
}

void Unit::MoveTo(vec2 pos, ivec2 tile) {
  auto shrd = shared_from_this();
  this->position = pos;
  map[this->tile.x][this->tile.y].erase(shrd);
  this->tile = tile;
  map[tile.x][tile.y].insert(shrd);
}
