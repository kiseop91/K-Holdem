#pragma once
#include <entt/entt.hpp>
#include <Component/Component.h>
#include <vector>

void MakeDeck(entt::registry & _reg);

EnumCard DrawDeckCard(entt::registry & _reg);

void SetCardToBoard(entt::registry & _reg, BoardState _state);
