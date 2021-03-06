#ifndef INTERACTIVE_PLAYER_H_
#define INTERACTIVE_PLAYER_H_

#include "playfield.h"
#include "player.h"
#include "player_factory.h"
#include "alphonse_playfield_traits.h"

typedef alphonse::playfield_traits<playfield> PT;

class interactive_player : public player
{

	int player_id;

public:

	interactive_player(int player_id);
	virtual ~interactive_player();
	virtual int play(const playfield& field);

	static std::shared_ptr<player> make(int id);

};

#endif  // INTERACTIVE_PLAYER_H_
