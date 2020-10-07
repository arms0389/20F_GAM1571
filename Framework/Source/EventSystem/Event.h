#pragma once

namespace fw {

class Event
{
public:
    Event();
    virtual ~Event();

    std::string GetType() { return m_EventType; }

protected:
    std::string m_EventType = "BaseEvent";
};

} // namespace fw
