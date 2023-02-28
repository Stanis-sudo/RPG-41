//Put your name(s) here:
//What bullet points did you do:
//Delete this next line to let the code compile
//#error Delete This!
#include "map.h"
#include <unistd.h>
#include "aux.h"
#include "actor.h"
#include <memory>

const int MAX_FPS = 90; //Cap frame rate 
const unsigned int TIMEOUT = 10; //Milliseconds to wait for a getch to finish
const int UP = 65; //Key code for up arrow
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
const int TREASURE_AMOUNT = 10;

//Turns on full screen text mode
void turn_on_ncurses() {
	initscr();//Start curses mode
	start_color(); //Enable Colors if possible
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Set up some color pairs
	init_pair(2,COLOR_CYAN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	init_pair(5,COLOR_RED,COLOR_BLACK);
	init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
	clear();
	noecho();
	cbreak();
	timeout(TIMEOUT); //Set a max delay for key entry
}



//Exit full screen mode - also do this if you ever want to use cout or gtest or something
void turn_off_ncurses() {
	clear();
	endwin(); // End curses mode
	if (system("clear")) {}
}

bool combat_mode(std::vector<std::shared_ptr<Hero>>& heroes){
	turn_off_ncurses();
	print_battle();
	usleep(2'000'000);
	for (auto i = 0; i < HEROES_SUM; ++i) {
    std::cout << "Name: " << heroes[i]->get_name() << std::endl;
    std::cout << "Speed: " << heroes[i]->get_speed() << std::endl;
    std::cout << "Health: " << heroes[i]->get_health() << std::endl;
    std::cout << "Attack: " << heroes[i]->get_attack() << std::endl;
    std::cout << "Defence: " << heroes[i]->get_defence() << std::endl;
    std::cout << "Dead: " << heroes[i]->get_dead() << std::endl;
    std::cout << "Super Power: " << heroes[i]->get_super_power() << std::endl << std::endl;
  }
	usleep(6'000'000);
	if (system("clear")) {}
	print_battle();
	print_win();
	usleep(2'000'000);
	if (system("clear")) {}
	//turn_off_ncurses();
	turn_on_ncurses();
	//clear();
	//refresh();
	return true;
}

bool obstacle(int x, int y, const Map& map) {
	char ch = map.get_character(x, y);
	if ( ch == '~' or ch == '#') return true;
	return false;
}

int main() {
	turn_on_ncurses(); //DON'T DO CIN or COUT WHEN NCURSES MODE IS ON
	Map map;
	vector<shared_ptr<Hero>> heroes;
	init_heroes(heroes);
	vector<shared_ptr<Actor>> actors;
	
	int x = Map::SIZE / 2, y = Map::SIZE / 2; //Start in middle of the world
	int old_x = -1, old_y = -1;
	int money = 0;
	int combat = 0;
	while (true) {
		int ch = getch(); // Wait for user input, with TIMEOUT delay
		if (ch == 'q' || ch == 'Q') break;
		else if (ch == RIGHT) {
			x++;
			if (x >= Map::SIZE) x = Map::SIZE - 1; //Clamp value
		}
		else if (ch == LEFT) {
			x--;
			if (x < 0) x = 0;
		}
		else if (ch == UP) {
			/* If you want to do cin and cout, turn off ncurses, do your thing, then turn it back on
			turn_off_ncurses();
			string s;
			cin >> s;
			cout << s << endl;
			sleep(1);
			turn_on_ncurses();
			*/
			y--;
			if (y < 0) y = 0;
		}
		else if (ch == DOWN) {
			y++;
			if (y >= Map::SIZE) y = Map::SIZE - 1; //Clamp value
		}
		else if (ch == 'R' or ch == 'r') { 
			map.init_map();
			x = Map::SIZE / 2; y = Map::SIZE / 2;
			init_heroes(heroes);
			money = 0;
			combat = 0;
		}
		else if (ch == 'S' or ch == 's') { 
			map.save_game(map.get_map(), x, y, money, combat, "map1.txt", "mapA.txt"); //works just fine
		}
		else if (ch == 'L' or ch == 'l') {
			turn_off_ncurses; //for testing
			map.set_map(map.load_game("map1.txt"), map, "mapA.txt"); //weird loading, and haven't done mapA yet, but its simple
			turn_on_ncurses; //''
		}
		else if (ch == ERR) { //No keystroke
			; //Do nothing
		}

		if (obstacle(x, y, map)) {
			x = old_x;
			y = old_y;
		} 
		
		if (map.get_character(x, y) == '$') {
			money += TREASURE_AMOUNT;
			increase_s_power(heroes, money);
		}
		if (map.get_character(x, y) == 'M') {
			if (!combat_mode(heroes)) {

				break;
			}
			combat++;
			increase_defence(heroes, combat);
			increase_attack(heroes, combat);
		}
		if (x != old_x or y != old_y) {
			map.set_open(x, y);
			map.draw(x,y);
			mvprintw(Map::DISPLAY+1,0,"X: %i Y: %i Score: %i Combat: %i\n",x, y, money, combat);
			refresh();
		}
		old_x = x;
		old_y = y;
		usleep(1'000'000/MAX_FPS);
	}
	turn_off_ncurses();
}
