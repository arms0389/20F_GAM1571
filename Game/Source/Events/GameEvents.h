#pragma once

class RemoveFromGameEvent : public fw::Event
{
public:
    RemoveFromGameEvent(fw::GameObject* pObject)
    {
        m_EventType = "RemoveFromGameEvent";
        m_pObject = pObject;
    }
    ~RemoveFromGameEvent() {}

    fw::GameObject* GetGameObject() { return m_pObject; }

protected:
    fw::GameObject* m_pObject;
};
