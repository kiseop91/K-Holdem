#pragma once
#include <entt/entt.hpp>

enum class EventType
{
	None = 0,
	Call, Raise, Die, Allin, CardDraw, GameStart, GameResult
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

class Event
{
public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
};

class CallEvent : public Event
{
public:

	EVENT_CLASS_TYPE(Call)
};

class RaiseEvent : public Event
{
	EVENT_CLASS_TYPE(Raise)
};

class DieEvent : public Event
{
public:
	EVENT_CLASS_TYPE(Die)
};

class AllinEvent : public Event
{
public:
	EVENT_CLASS_TYPE(Allin)
};

class CardDrawEvent : public Event
{
public:
	EVENT_CLASS_TYPE(CardDraw)
};

class GameStartEvent : public Event
{
public:
	int a;
	EVENT_CLASS_TYPE(GameStart)
};

class GameResultEvent : public Event
{
public:
	EVENT_CLASS_TYPE(GameResult)
};