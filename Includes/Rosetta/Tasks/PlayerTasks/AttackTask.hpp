// This code is based on Sabberstone project.
// Copyright (c) 2017-2018 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef HEARTHSTONEPP_ATTACK_TASK_HPP
#define HEARTHSTONEPP_ATTACK_TASK_HPP

#include <Rosetta/Tasks/Tasks.hpp>

namespace Hearthstonepp::PlayerTasks
{
//!
//! \brief AttackTask class.
//!
//! This class represents the task for attacking target.
//!
class AttackTask : public ITask
{
 public:
    //! Construct task with given \p source and \p target.
    //! \param source A pointer to source character.
    //! \param target A pointer to target character.
    AttackTask(Entity* source, Entity* target);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player& player) override;
};
}  // namespace Hearthstonepp::PlayerTasks

#endif  // HEARTHSTONEPP_ATTACK_TASK_HPP
