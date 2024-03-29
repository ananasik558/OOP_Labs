#include "../headers/FightManager.hpp"

FightManager::FightManager(std::mutex* _mtx) {
    mtx = _mtx;
}

FightManager& FightManager::get(std::mutex* _mtx) {
    static FightManager instance(_mtx);
    return instance;
}

void FightManager::add_event(FightEvent&& event) {
    // std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
}

void FightManager::operator()() {
    while (true) {
        {
            if (timer == MAX_TIME) {
                return;
            }
            std::optional<FightEvent> event;

            {
                std::lock_guard<std::mutex> lock(*mtx);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }
            if (event) {
                if (event->attacker->isAlive() && event->defender->isAlive() &&
                (event->attacker->throwDice() > event->defender->throwDice()) &&
                event->defender->accept(event->attacker)) {
                    event->defender->mustDie();   
                }
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
}