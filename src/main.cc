#include <iostream>
#include <memory>

#define ACTION_HH_IMPL
#include "action.hh"
#include "player.hh"
#define MAP_HH_IMPL
#include "map.hh"

std::shared_ptr<Player> makePlayer() {
  std::cout << "Choose your class (1: Fighter, 2: Healer): ";
  
  int chose;

  std::cin >> chose;

  std::cout << "\n";

  std::shared_ptr<Player> player;

  if (chose == 1) {
    player = std::make_shared<Fighter>();
  } else if (chose == 2) {
    player = std::make_shared<Healer>();
  } else {
   return player;
  }

  player->position.x = 0;
  player->tile.x = 0;
  player->position.y = 0;
  player->tile.y = 0;

  map[0][0].insert(std::shared_ptr<Player>(player));

  return player;
}

/* FIXME: Fix cache issues, and rewrite to use curses.
 *
 * The  current  way  that this is required to be implemented is that  it  loops
 * through tiles left to right, top to bottom, left to right. In order for it to
 * be  able to render without the cursor moving,  it needs to loop through every
 * horizontal  tile (on a row)  and position within for every vertical tile  and
 * position within. To my knowledge of computers, they don't like it when you do
 * this, and thus it needs to be rewritten.
 *
 * Also, it should also look better with curses because of colors.
 */
void DrawMap() {
  // mmm yum, cache misses

  int t = 0;

  int seen = 0;

  for (int y = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
      seen += map[x][y].size();
    }
    for (int yt = 0; yt < TILE_HEIGHT; ++yt) {
      for (int x = 0; x < MAP_WIDTH; ++x) {
        for (int xt = 0; xt < TILE_WIDTH; ++xt) {
          t = 0;
          for (const auto& unit: map[x][y]) {
            if ((int)unit->position.x == xt &&
                (int)unit->position.y == yt) {
              std::cout << unit->chr;
              ++t;
              if (t == 2)
                break;
            }
          }
          if (!t) {
            std::cout << ".";
          }
          if (t != 2) std::cout << " ";
        }
      }
      std::cout << "\n";
    }
  }

  // Debug to make sure Unit::MoveTo(2) removes properly.
  std::cout << "Seen: " << seen << "\n\n";

  std::cout << "Act:\n";
}

void ListActions(std::shared_ptr<Player>& player) {
  // Movement
  {
    std::cout << "w,a. Move\n" <<
                 "s,d) Move "/* TODO: Implement movespeedup to " << player->movespeed << " tile */"in a direction.\n";
  }
  
  // Real Actions
  {
    int x = 0;
    for (const auto& action: player->actions) {
      std::cout << (x + 1) << ") " << action->title <<
                "\n   " << action->desc << "\n";
      
      ++x;
    }
  }
}

/* FIXME: Reads only one character.
 *
 * Not really an issue,  but the fact that it reads in a line but then only acts
 * on  the first character could be confusing.  I  need to either explain  this,
 * just wait until we can use getch with ncurses, or use windows.h's _Getch.
 */
void ProcessAction(std::shared_ptr<Player>& player) {
  while (true) {
    unsigned char act;
    std::cin >> act;

    std::cout << "In: " << act << ".\n";

    // Movement

    if (act == 'w') {
      player->MoveRel( 0,-1);
      return;
    } if (act == 'a') {
      player->MoveRel(-1, 0);
      return;
    } if (act == 's') {
      player->MoveRel( 0, 1);
      return;
    } if (act == 'd') {
      player->MoveRel( 1, 0);
      return;
    }

    // Player Actions

    if (act < '0') continue;

    // Convert to number
    act -= '0';
    // Insure in range
    if (act < 1) continue;
    if (act > 9) continue;

    if (act > player->actions.size()) continue;

    PlayerAction* action = player->actions[act - 1];

    std::cout << "You used " << action->title << "!\n";

    return;
  }
}

void DebugMap() {
  for (int y = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
      std::cout << "map[" << x << "][" << y << "]\n";
      std::cout << map[x][y].size() << "\n";
      for (const auto& unit: map[x][y]) {
        std::cout << unit->chr << ": " << unit->tile.x << " " <<
                     unit->tile.y << " " << unit->position.x << " " <<
                     unit->position.y << "\n";
      }
    }
  }
}

int main() {
  std::shared_ptr<Player> player = makePlayer();

  while (true) {
    // DebugMap();

    DrawMap();

    ListActions(player);

    ProcessAction(player);
  }
}
