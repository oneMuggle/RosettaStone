// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_META_DATA_HPP
#define HEARTHSTONEPP_META_DATA_HPP

namespace Hearthstonepp
{
using status_t = unsigned int;

//! Meta data to represent the result of the task.
enum class MetaData : status_t
{
    INVALID,
    NULLPTR,

    PLAYER_SETTING,
    PLAYER_SETTING_REQUEST,
    PLAYER_SETTING_SUCCESS,

    SWAP,
    SWAP_SUCCESS,

    DRAW,
    DRAW_SUCCESS,
    DRAW_EXHAUST,
    DRAW_OVERDRAW,
    DRAW_EXHAUST_OVERDRAW,

    SHUFFLE,
    SHUFFLE_SUCCESS,

    BRIEF,
    BRIEF_EXPIRED,

    MULLIGAN,
    MULLIGAN_SUCCESS,
    MULLIGAN_FLATBUFFER_NULLPTR,
    MULLIGAN_INDEX_OUT_OF_RANGE,
    MULLIGAN_DUPLICATED_INDEX,

    MODIFY_MANA,
    MODIFY_MANA_SUCCESS,

    SELECT_CARD,
    SELECT_POSITION,
    SELECT_TARGET,

    PLAY_CARD,
    PLAY_CARD_SUCCESS,
    PLAY_CARD_FLATBUFFER_NULLPTR,
    PLAY_CARD_IDX_OUT_OF_RANGE,
    PLAY_CARD_NOT_ENOUGH_MANA,
    PLAY_CARD_INVALID_TARGET,
    PLAY_CARD_INVALID_CARD_TYPE,

    PLAY_MINION,
    PLAY_MINION_SUCCESS,
    PLAY_MINION_FIELD_IS_FULL,
    PLAY_MINION_FLATBUFFER_NULLPTR,
    PLAY_MINION_CANNOT_CONVERT_ENTITY,
    PLAY_MINION_POSITION_OUT_OF_RANGE,
    PLAY_MINION_MODIFY_MANA_FAIL,

    PLAY_WEAPON,
    PLAY_WEAPON_DYNAMIC_CAST_FAIL,
    PLAY_WEAPON_SUCCESS,

    PLAY_SPELL,
    PLAY_SPELL_SUCCESS,
    PLAY_SPELL_NO_POWER,
    PLAY_SPELL_FLATBUFFER_NULLPTR,
    PLAY_SPELL_POSITION_OUT_OF_RANGE,
    PLAY_SPELL_INVALID_TARGET,
    PLAY_SPELL_MODIFY_MANA_FAIL,

    DAMAGE,
    DAMAGE_SUCCESS,

    COMBAT,
    COMBAT_SUCCESS,
    COMBAT_FLATBUFFER_NULLPTR,
    COMBAT_SRC_IDX_OUT_OF_RANGE,
    COMBAT_DST_IDX_OUT_OF_RANGE,
    COMBAT_SOURCE_CANT_ATTACK,

    ADD_ENCHANTMENT,
    ADD_ENCHANTMENT_SUCCESS,

    DESTROY,
    DESTROY_WEAPON_SUCCESS,
    DESTROY_MINION_SUCCESS,
    DESTROY_MINION_NOT_FOUND,

    DISCARD,
    DISCARD_MY_HAND_SUCCESS,
    DISCARD_IDX_OUT_OF_RANGE,

    HEAL_FULL,
    HEAL_FULL_SUCCESS,

    HEAL,
    HEAL_SUCCESS,

    INCLUDE,
    INCLUDE_SUCCESS,

    POISONOUS,
    POISONOUS_SUCCESS,

    FREEZE,
    FREEZE_SUCCESS,

    INIT_ATTACK_COUNT,
    INIT_ATTACK_COUNT_SUCCESS,

    CONTROL,
    CONTROL_INVALID_TARGET,
    CONTROL_FIELD_IS_FULL,
    CONTROL_SUCCESS,

    GAME_END
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_META_DATA_HPP
