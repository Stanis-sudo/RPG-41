#include <iostream>
#include "actor.h"
#include <vector>
#include <memory>

#include "aux.h"


//std::vector<Hero> heroes;
//std::vector<Monster> monsters;

//void init_heroes() {
  //      for (int i = 0; i < HEROES_SUM; ++i){
    //        Hero* new_hero = new Hero("Hero #" + std::to_string(i + 1));
      //      //Hero new_hero("Hero #" + std::to_string(i + 1));
        //    heroes.push_back(*new_hero);
        //}
   // }
//std::unique_ptr<Hero[]> heroes = std::make_unique<Hero[]>(HEROES_SUM);


int main() {

  std::vector<std::shared_ptr<Hero>> heroes;
	init_heroes(heroes);

  //
  /*init_heroes(heroes);
  std::cout << heroes << std::endl;
  for (auto i = 0; i < HEROES_SUM; ++i) {
    std::cout << "Name: " << heroes[i].get_name() << std::endl;
    std::cout << "Speed: " << heroes[i].get_speed() << std::endl;
    std::cout << "Health: " << heroes[i].get_health() << std::endl;
    std::cout << "Attack: " << heroes[i].get_attack() << std::endl;
    std::cout << "Defence: " << heroes[i].get_defence() << std::endl;
    std::cout << "Dead: " << heroes[i].get_dead() << std::endl;
    std::cout << "Super Power: " << heroes[i].get_super_power() << std::endl << std::endl;
  }*/

  //for (auto i : heroes) delete &i;
}