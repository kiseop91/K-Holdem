#include "pch.h"

TEST(DeckTest, DeckCount) {

	entt::registry reg;
	auto entity = EntityFactory::makeDeckEntity(reg);
	
	MakeDeck(reg);

	auto view = reg.view<HandComponent>();

	int deckSize = 0;
	for (auto entity : view)
	{
		std::cout << deckSize << std::endl;
		auto deck = view.get<HandComponent>(entity);
		deckSize = deck.cardList.size();
	}
	EXPECT_EQ(deckSize, 52);
}

TEST(DeckTest, DrawCard ) {
	entt::registry reg;
	auto entity = EntityFactory::makeDeckEntity(reg);

	MakeDeck(reg);
	auto view = reg.view<HandComponent>();
	EnumCard drawCard;
	EnumCard backCard;
	for (auto entity : view)
	{
		auto deck = view.get<HandComponent>(entity);
		backCard = deck.cardList.back();
		drawCard = DrawDeckCard(reg);
	}
	
	EXPECT_EQ(backCard, drawCard);
}

TEST(DeckTest, SetCardToBoard) {
	entt::registry reg;
	auto entity = EntityFactory::makeDeckEntity(reg);
	MakeDeck(reg);

	auto view = reg.view<BoardTag, HandComponent>();

	SetCardToBoard(reg, BoardState::Flop);

	int boardHandSize = 0;
	for (auto entity : view)
	{
		auto deck = view.get<HandComponent>(entity);
		boardHandSize = deck.cardList.size();
	}

	EXPECT_EQ(boardHandSize, 3);
}