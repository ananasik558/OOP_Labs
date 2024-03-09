#pragma once

#include "NPC.hpp"
#include "Outlaw.hpp"
#include "Orc.hpp"
#include "Werewolf.hpp"

inline const int MAX_TIME = 30;

inline int timer = 0;

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
    private:
        std::queue<FightEvent> events;
        // std::shared_mutex mtx;
        std::mutex* mtx;

        FightManager(std::mutex* _mtx);
    public:

        static FightManager& get(std::mutex* _mtx);
        void add_event(FightEvent&& event);
        void operator()();
};