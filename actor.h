#pragma once
#include <random>
#include <memory>

const int HEROES_SUM = 5;
const int MONSTERS_SUM = 5;

class Actor {
    protected:
    std::string name;
    int speed;
    int health;
    int attack;
    int defence;
    bool dead;

    public:
    Actor() {
        name = "NONAME";
        speed = 0;
        health = 100;
        attack = 10;
        defence = 10;
        dead = false;
    }

    void set_name(std::string new_name) {
        name = new_name;
    }
    std::string get_name() const {
        return name;
    }
    void set_speed(int new_speed) {
        speed = new_speed;
    }
    int get_speed() const {
        return speed;
    }
    void set_health(int new_health) {
        health = new_health;
    }
    int get_health() const {
        return health;
    }
    void set_attack(int new_attack) {
        attack = new_attack;
    }
    int get_attack() const {
        return attack;
    }
    void set_defence(int new_defence) {
        defence = new_defence;
    }
    int get_defence() const {
        return defence;
    }
    void set_dead() {
        dead = true;
    }
    bool get_dead() {
        return dead;
    }
};

class Hero : public Actor {
    int super_power = 0;

    public:
    void set_super_power(int new_s_power) {
        super_power = new_s_power;
    }
    int get_super_power() {
        return super_power;
    }
    
};

class Monster : public Actor {
    int super_defence;

    public:
    Monster() {
        super_defence = 0;
    }
    Monster(std::string new_name) {
        name = new_name;
        super_defence = 0;
        speed = 1;
        health = 100;
        attack = 50;
        defence = 50;
    }
    void set_super_power(int new_s_defence) {
        super_defence = new_s_defence;
    }
    int get_super_defence() {
        return super_defence;
    }
};

void init_heroes(std::vector<std::shared_ptr<Hero>>& heroes){
  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(1, 20);
  heroes.clear();
  for (auto i = 0; i < HEROES_SUM; ++i) {
    Hero hero;
    heroes.push_back(std::make_shared<Hero>(hero));
    heroes[i]->set_speed(distrib(gen));
  }
  heroes[0]->set_name("Hercules");
  heroes[1]->set_name("Perseus");
  heroes[2]->set_name("Hector");
  heroes[3]->set_name("Aeneas");
  heroes[4]->set_name("Prometheus");
  }

  void increase_s_power(std::vector<std::shared_ptr<Hero>>& heroes, int money){
    for (auto &a : heroes) {
    a->set_super_power(money * 2 / 10);
  }
  }

  void increase_defence(std::vector<std::shared_ptr<Hero>>& heroes, int battle){
    for (auto &a : heroes) a->set_defence(battle * 2 + a->get_defence());
  }

  void increase_attack(std::vector<std::shared_ptr<Hero>>& heroes, int battle){
    for (auto &a : heroes) a->set_attack(battle * 3 + a->get_attack());
  }