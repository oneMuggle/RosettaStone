/*************************************************************************
> File Name: AgentStructure.h
> Project Name: Hearthstone++
> Author: Young-Joong Kim
> Purpose: Agent Data Structure for Interact with Interface
> Created Time: 2017/10/24
> Copyright (c) 2017, Young-Joong Kim
*************************************************************************/
#ifndef HEARTHSTONEPP_AGENT_STRUCTURES_H
#define HEARTHSTONEPP_AGENT_STRUCTURES_H

#include <Models/Card.h>
#include <Models/Cards.h>
#include <Models/Entities/Hero.h>
#include <Models/Entities/HeroPower.h>
#include <Models/Entities/Weapon.h>
#include <Models/Player.h>

namespace Hearthstonepp
{
	using BYTE = unsigned char;

	struct User
	{
		User(Player* player, int deckID);

		int id;
		int mana;

		std::string userID;
		Hero* hero;
		HeroPower* power;
		Weapon* weapon;

		std::vector<Card> cardDeck;

		std::vector<Card*> deck;
		std::vector<Card*> field;
		std::vector<Card*> hand;
		std::vector<Card*> usedSpell;
		std::vector<Card*> usedMinion;
	};

	struct GameResult
	{

	};

	struct DrawStructure
	{
		DrawStructure(BYTE drawID, BYTE userID, BYTE numDraw, Card** cards);

		BYTE id;
		BYTE userID;
		BYTE numDraw;
		Card** cards;
	};

	struct ModifyManaStructure
	{
		ModifyManaStructure(BYTE userID, BYTE mana);

		BYTE id = static_cast<BYTE>(Action::MANA_MODIFICATION);
		BYTE userID;
		BYTE mana;
	};

	struct BeginFirstStructure
	{
		BeginFirstStructure(std::string& userFirst, std::string& userLast);

		BYTE id = static_cast<BYTE>(Step::BEGIN_FIRST);
		std::string& userFirst;
		std::string& userLast;
	};

	struct BeginShuffleStructure
	{
		BeginShuffleStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::BEGIN_SHUFFLE);
		BYTE userID;
	};

	struct BeginMulliganStructure
	{
		BeginMulliganStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::BEGIN_MULLIGAN);
		BYTE userID;
	};

	struct MainMenuStructure
	{
		MainMenuStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_START);
		BYTE userID;
	};

	struct MainUseCardStructure
	{
		MainUseCardStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_ACTION);
		BYTE userID;
	};

	struct MainCombatStructure
	{
		MainCombatStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_COMBAT);
		BYTE userID;
	};

	struct MainEndStructure
	{
		MainEndStructure(BYTE userID);

		BYTE id = static_cast<BYTE>(Step::MAIN_END);
		BYTE userID;
	};
}

#endif