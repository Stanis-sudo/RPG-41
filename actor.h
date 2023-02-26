#pragma once

class Actor {
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
        return seeed;
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