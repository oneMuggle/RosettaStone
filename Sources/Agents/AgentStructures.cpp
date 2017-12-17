/*************************************************************************
> File Name: AgentStructure.cpp
> Project Name: Hearthstone++
> Author: Young-Joong Kim
> Purpose: Agent Data Structure for Interact with Interface
> Created Time: 2017/10/24
> Copyright (c) 2017, Young-Joong Kim
*************************************************************************/
#include <Agents/AgentStructures.h>
#include <Commons/Constants.h>
#include <Enums/EnumsToString.h>

namespace Hearthstonepp
{
	User::User(Player* player, int deckID) :
		mana(0), userID(player->GetID()) , weapon(nullptr)
	{
		Cards* cards = Cards::GetInstance();

		Deck* tmpDeck = player->GetDeck(deckID);
		const CardClass cardclass = tmpDeck->GetClass();

		const Card* heroCard = cards->FindCardByID(std::move(ConvertFromCardClassToHeroID.at(cardclass)));
		const Card* powerCard = cards->FindCardByID(std::move(ConvertFromCardClassToHeroPowerID.at(cardclass)));

		cardDeck.reserve(sizeof(Card) * (MAXIMUM_NUM_CARDS_IN_DECK + 2));
		for (auto& ptrCard : tmpDeck->GetPrimitiveDeck())
		{
			cardDeck.emplace_back(Card(*ptrCard));
			deck.emplace_back(&cardDeck.back());
		}

		cardDeck.emplace_back(Hero(*reinterpret_cast<const Hero*>(heroCard)));
		hero = reinterpret_cast<Hero*>(&cardDeck.back());

		cardDeck.emplace_back(HeroPower(*reinterpret_cast<const HeroPower*>(powerCard)));
		power = reinterpret_cast<HeroPower*>(&cardDeck.back());
	}

	DrawStructure::DrawStructure(BYTE drawID, BYTE userID, BYTE numDraw, Card** cards) :
		id(drawID), userID(userID), numDraw(numDraw), cards(cards)
	{
		// Do Nothing
	}

	ModifyManaStructure::ModifyManaStructure(BYTE userID, BYTE mana) :
		userID(userID), mana(mana)
	{
		// Do Nothing
	}

	BeginFirstStructure::BeginFirstStructure(std::string& userFirst, std::string& userLast) :
		userFirst(userFirst), userLast(userLast)
	{
		// Do Nothing
	}

	BeginShuffleStructure::BeginShuffleStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}

	BeginMulliganStructure::BeginMulliganStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}

	MainMenuStructure::MainMenuStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}

	MainUseCardStructure::MainUseCardStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}

	MainCombatStructure::MainCombatStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}

	MainEndStructure::MainEndStructure(BYTE userID) : userID(userID)
	{
		// Do Nothing
	}
}