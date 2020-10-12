#pragma once
#include <entt/entt.hpp>

enum class EventType
{
	None = 0,
	Call, HandView, Raise, Check, Die, Allin, CardDraw, GameStart, GameResult
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

class HandViewEvent : public Event
{
public:
	HandViewEvent(entt::entity _id)
		:id(_id) {}

	entt::entity id;
	EVENT_CLASS_TYPE(HandView)
};

class CallEvent : public Event
{
public:
	CallEvent(entt::entity _id, size_t _money)
		:id(_id), callMoneny(_money) {}

	size_t callMoneny;
	entt::entity id;
	EVENT_CLASS_TYPE(Call)
};

class RaiseEvent : public Event
{
public:
	RaiseEvent(entt::entity _id, size_t _raiseMoneny)
		:id(_id), raiseMoneny(_raiseMoneny) {}
	EVENT_CLASS_TYPE(Raise)

	entt::entity id;
	size_t raiseMoneny;
};

class CheckEvent : public Event
{
public:
	CheckEvent(entt::entity _id)
		:id(_id)
	{}

	entt::entity id;
	EVENT_CLASS_TYPE(Check)
};

class DieEvent : public Event
{
public:
	DieEvent(entt::entity _id) 
		:id(_id)
	{}

	entt::entity id;
	EVENT_CLASS_TYPE(Die)
};

class AllinEvent : public Event
{
public:
	AllinEvent(entt::entity _id, size_t _allinMoneny)
		:id(_id), allinMoneny(_allinMoneny) {}
	
	size_t allinMoneny;
	entt::entity id;
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
	EVENT_CLASS_TYPE(GameStart)
};

class GameResultEvent : public Event
{
public:
	EVENT_CLASS_TYPE(GameResult)
};