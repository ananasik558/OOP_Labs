#pragma once

#include "NPC.hpp"
#include "Factory.hpp"

struct OutlawVisitor : public FightVisitor {
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Outlaw>&) const override;
    bool visit(const std::shared_ptr<Orc>&) const override;
};

class Outlaw : public NPC {
    public:
        Outlaw();
        Outlaw(int, int);
        Outlaw(std::istream&);

        void save(std::ostream&) override;
        bool accept(const std::shared_ptr<NPC>&) const override;
        friend std::ostream& operator << (std::ostream&, Outlaw&);
        void print() override;

        ~Outlaw() = default;
};