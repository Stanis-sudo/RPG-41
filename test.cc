#include <iostream>
#include "actor.h"
#include <vector>
#include <memory>

std::unique_ptr<Hero[]> heroes = std::make_unique<Hero[]>(HEROES_SUM);
//std::vector<Hero> heroes;
//std::vector<Monster> monsters;

//void init_heroes() {
  //      for (int i = 0; i < HEROES_SUM; ++i){
    //        Hero* new_hero = new Hero("Hero #" + std::to_string(i + 1));
      //      //Hero new_hero("Hero #" + std::to_string(i + 1));
        //    heroes.push_back(*new_hero);
        //}
   // }

int main() {
  //init_heroes();
  for (auto i = 0; i < HEROES_SUM; ++i) {
    std::cout << "Name: " << heroes[i].get_name() << std::endl;
    std::cout << "Health: " << heroes[i].get_health() << std::endl;
    std::cout << "Attack: " << heroes[i].get_attack() << std::endl;
    std::cout << "SUper Attack: " << heroes[i].get_super_power() << std::endl;
  }
  //for (auto i : heroes) delete &i;
}