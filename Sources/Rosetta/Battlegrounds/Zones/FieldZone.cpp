// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Battlegrounds/Zones/FieldZone.hpp>

#include <stdexcept>

namespace RosettaStone::Battlegrounds
{
Minion& FieldZone::operator[](int zonePos)
{
    return m_minions.at(zonePos).value();
}

const Minion& FieldZone::operator[](int zonePos) const
{
    return m_minions.at(zonePos).value();
}

void FieldZone::Add(Minion& minion, int zonePos)
{
    if (zonePos > m_count)
    {
        throw std::invalid_argument("Zone position isn't in a valid range.");
    }

    const int pos = zonePos < 0 ? m_count : zonePos;

    if (IsFull())
    {
        return;
    }

    if (pos < 0 || pos == m_count)
    {
        m_minions[m_count] = minion;
    }
    else
    {
        for (int i = m_count - 1; i >= pos; --i)
        {
            m_minions[i + 1] = m_minions[i];
        }

        m_minions[pos] = minion;
    }

    ++m_count;

    m_minions[pos].value().SetZoneType(m_type);

    Reposition(pos);
}

const Minion FieldZone::Remove(Minion& minion)
{
    if (minion.GetZoneType() != m_type)
    {
        throw std::logic_error("Couldn't remove entity from zone.");
    }

    const int pos = minion.GetZonePosition();
    int count = m_count;

    Minion result = m_minions.at(pos).value();

    if (pos < count--)
    {
        for (int i = pos + 1; i < MAX_FIELD_SIZE; ++i)
        {
            m_minions[i - 1] = m_minions[i];
        }

        m_minions[MAX_FIELD_SIZE - 1].reset();
    }

    m_count = count;

    Reposition(pos);

    return result;
}

void FieldZone::Reposition(int zonePos)
{
    if (zonePos < 0)
    {
        m_minions[m_count - 1].value().SetZonePosition(m_count - 1);
        return;
    }

    for (int i = m_count - 1; i >= zonePos; --i)
    {
        m_minions[i].value().SetZonePosition(i);
    }
}

void FieldZone::Move(int curPos, int newPos)
{
    Minion minion = Remove(m_minions[curPos].value());
    Add(minion, newPos);
}

int FieldZone::GetCount() const
{
    return m_count;
}

bool FieldZone::IsEmpty() const
{
    return m_count == 0;
}

bool FieldZone::IsFull() const
{
    return m_count == MAX_FIELD_SIZE;
}
}  // namespace RosettaStone::Battlegrounds
