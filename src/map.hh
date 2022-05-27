#pragma once

#include <memory>
#include <set>

#include "unit.hh"

#define TILE_WIDTH  4
#define TILE_HEIGHT 4

#define MAP_WIDTH   2
#define MAP_HEIGHT  2

#ifndef MAP_HH_IMPL
extern
#endif
std::set<std::shared_ptr<Unit>> map[MAP_WIDTH][MAP_HEIGHT];
