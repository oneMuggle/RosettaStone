#ifndef HEARTHSTONEPP_SYNCBUFFER_H
#define HEARTHSTONEPP_SYNCBUFFER_H

#include <condition_variable>
#include <mutex>

namespace Hearthstonepp
{
//!
//! \brief SyncBuffer class.
//!
//! This class reads/writes synchronized buffer.
//! \tparam BufferType The type of buffer. (copy-assignable and movable)
//!
template <typename BufferType>
class SyncBuffer
{
 public:
    //! Default constructor.
    SyncBuffer() : m_readable(false)
    {
        // Do Nothing
    }

    //! Deleted copy constructor.
    SyncBuffer(const SyncBuffer&) = delete;

    //! Deleted move constructor.
    SyncBuffer(SyncBuffer&&) = delete;

    //! Deleted copy assignment operator.
    SyncBuffer& operator=(const SyncBuffer&) = delete;

    //! Deleted move assignment operator.
    SyncBuffer& operator=(SyncBuffer&&) = delete;

    //! Writes \p buffer to synchronized buffer.
    void WriteBuffer(BufferType&& buffer)
    {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cond.wait(lock, [=]() { return !m_readable; });

        m_buffer = std::move(buffer);

        m_readable = true;
        m_cond.notify_one();
    }

    //! Writes \p buffer to synchronized buffer.
    void WriteBuffer(const BufferType& buffer)
    {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cond.wait(lock, [=]() { return !m_readable; });

        m_buffer = buffer;

        m_readable = true;
        m_cond.notify_one();
    }

    //! Reads \p buffer from synchronized buffer.
    void ReadBuffer(BufferType& buffer)
    {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cond.wait(lock, [=]() { return m_readable; });

        buffer = std::move(m_buffer);

        m_readable = false;
        m_cond.notify_one();
    }

    //! Returns whether it is readable.
    bool isReadable() const
    {
        return m_readable;
    }

 private:
    bool m_readable;
    BufferType m_buffer;

    std::mutex m_mtx;
    std::condition_variable m_cond;
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_SYNCBUFFER_H
