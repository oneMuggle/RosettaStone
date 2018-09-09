#ifndef HEARTHSTONEPP_HERO_H
#define HEARTHSTONEPP_HERO_H

#include <Cards/Character.h>
#include <Cards/Weapon.h>

namespace Hearthstonepp
{
//!
//! \brief Hero structure.
//!
//! This structure inherits from Character structure.
//! Also, it stores weapon that can attack to enemy.
//!
struct Hero : public Character
{
    //! Constructs hero with given \p pCard.
    //! \param pCard A pointer to the card.
    Hero(const Card* pCard);

    Weapon* weapon;
};
}

#endif