#pragma once
#include <vector>
#include <entt/entt.hpp>


// S D H C
enum class EnumCard
{
	SA,S2,S3,S4,S5,S6,S7,S8,S9,S10,SJ,SQ,SK,
	DA,D2,D3,D4,D5,D6,D7,D8,D9,D10,DJ,DQ,DK, 
	HA,H2,H3,H4,H5,H6,H7,H8,H9,H10,HJ,HQ,HK, 
	CA,C2,C3,C4,C5,C6,C7,C8,C9,C10,CJ,CQ,CK, Max
};

enum class BoardState
{
	PreFlop,
	Flop,
	Turn,
	River, Max
};

using PlayerTag = entt::tag<"PlayerTag"_hs>;
using BoardTag = entt::tag<"BoardTag"_hs>;
using DeckTag = entt::tag<"DeckTag"_hs>;

struct MoneyComponent
{
	MoneyComponent(int _chip)
		:chip(_chip)
	{ }

	int chip;
};


struct HandComponent
{
	std::vector<EnumCard> cardList;
};

struct StateComponent
{
	StateComponent(bool _call, bool _fold, bool _raise, bool _die, bool _allIn )
		:call(_call), fold(_fold), raise(_raise), die(_die), allin(_allIn)
	{}

	bool call;
	bool fold;
	bool raise;
	bool die;
	bool allin;
};

struct PlayerComponent
{
	entt::entity id;
};

struct TurnComponent
{
	int turnCount;
};

struct BoardStateComponent
{
	BoardStateComponent(BoardState _state)
		:state(_state) {}
	BoardState state;
};

struct BettingMoneyComponent
{
	BettingMoneyComponent(int _money)
	:money(_money){}
	int money;
};