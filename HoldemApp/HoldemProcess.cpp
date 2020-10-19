#pragma once
#include <entt/entt.hpp>
#include "HoldemProcess.h"

RoomProcess::RoomProcess(entt::registry& _reg, int _playerNumber)
	:m_Registry(_reg), m_PlayerNumber(_playerNumber)
{
	initialize();
}


void RoomProcess::initialize()
{
	initPlayer();
	initDeck();
}

void RoomProcess::initPlayer()
{
	for(int i = 0; i < m_PlayerNumber; i++)
		EntityFactory::makePlayerEntity(m_Registry);
}

void RoomProcess::initDeck()
{
	EntityFactory::makeDeckEntity(m_Registry);
}