#pragma once

#include "NPC.hpp"
#include "Factory.hpp"

struct WerewolfVisitor : public FightVisitor {
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Outlaw>&) const override;
    bool visit(const std::shared_ptr<Orc>&) const override;
};

class Werewolf : public NPC {
    public:
        Werewolf();
        Werewolf(int, int);
        Werewolf(std::istream&);

        void save(std::ostream&) override;
        bool accept(const std::shared_ptr<NPC>&) const override;
        friend std::ostream& operator << (std::ostream&, Werewolf&);
        void print() override;

        ~Werewolf() = default;
};