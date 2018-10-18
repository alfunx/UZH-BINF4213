#include "playfield.h"
#include "random_player.h"
#include "game.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_help()
{
	cout << "usage: connect4 [-i | -r]" << endl;
}

int main(int argc, char** argv)
{
	vector<string> args(argv, argv + argc);

	if (argc < 2) {
		print_help();
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		if ("-i" == args[i]) {
			game<playfield> g;
			g.play();
		} else if ("-r" == args[i]) {
			game<playfield, random_player<playfield>> g;
			g.play();
		} else if ("-h" == args[i]) {
			print_help();
			return 0;
		} else {
			print_help();
			return 1;
		}
	}

	return 0;
}
