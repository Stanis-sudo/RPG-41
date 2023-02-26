#pragma once
#include <vector>

const int HEROES_SUM = 5;
const int MONSTERS_SUM = 5;



class Actor {
    protected:
    std::string name;
    int speed;
    int health;
    int attack;
    int defence;

    public:
    Actor() {
        name = "NONAME";
        speed = 0;
        health = 0;
        attack = 0;
        defence = 0;
    }
    Actor(std::string new_name) {
        name = new_name;
        speed = 1;
        health = 100;
        attack = 50;
        defence = 50;
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

};

class Hero : public Actor {
    int super_power = 0;

    public:
    Hero() {
        //init_heroes();
    }
    Hero(std::string new_name) {
        name = new_name;
        super_power = 0;
        speed = 1;
        health = 100;
        attack = 50;
        defence = 50;
    }
  //  ~Hero(){
  //     delete 
  //  }
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