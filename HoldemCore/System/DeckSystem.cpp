#include <core_pch.h>
#include <System/DeckSystem.h>
#include <Component/Component.h>
#include <random>

void MakeDeck(entt::registry & _reg)
{
	auto view = _reg.view<DeckTag, HandComponent>();
	for (auto entity : view)
	{
		HandComponent& hand = view.get<HandComponent>(entity);
		hand.cardList;
		std::random_device rd;
		std::mt19937 g(rd());

		for (int i = 0; i < static_cast<int>(EnumCard::Max); i++)
		{
			EnumCard card = static_cast<EnumCard>(i);
			hand.cardList.push_back(card);
		}

		std::shuffle(hand.cardList.begin(), hand.cardList.end(), g);
	}
}

EnumCard DrawDeckCard(entt::registry & _reg)
{
	auto view = _reg.view<DeckTag, HandComponent>();
	EnumCard card;
	for (auto entity : view)
	{
		HandComponent& hand = view.get<HandComponent>(entity);
		card = hand.cardList.back();
		hand.cardList.pop_back();
	}

	return card;
}

void SetCardToBoard(entt::registry & _reg, BoardState _state)
{
	auto boardView = _reg.view<BoardTag, HandComponent>();
	auto deckView = _reg.view<DeckTag, HandComponent>();

	std::vector<EnumCard> returnCards;
	for (auto entity : deckView)
	{
		HandComponent& deck = deckView.get<HandComponent>(entity);

		if (_state == BoardState::PreFlop) {
			returnCards.clear();
		}
		else if (_state == BoardState::Flop)
		{
			auto card = deck.cardList.back();
			deck.cardList.pop_back();
			returnCards.push_back(card);

			card = deck.cardList.back();
			deck.cardList.pop_back();
			returnCards.push_back(card);

			card = deck.cardList.back();
			deck.cardList.pop_back();
			returnCards.push_back(card);

		}
		else if (_state == BoardState::Turn || _state == BoardState::River)
		{
			auto card = deck.cardList.back();
			deck.cardList.pop_back();
			returnCards.push_back(card);
		}
	}

	for (auto entity : boardView)
	{
		HandComponent& deck = boardView.get<HandComponent>(entity);
		
		for (auto& card : returnCards)
			deck.cardList.push_back(card);
	}
}


