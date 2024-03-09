#pragma once

#include "npc.h"

struct OutlawVisitor : public Visitor 
{
    bool visit(const std::shared_ptr<Ork>&) const override;
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Outlaw>&) const override;
};  

class Outlaw final : public Heroes {
public:
    Outlaw(std::string hName, short int x, short int y);
    Outlaw(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Outlaw & sq);
    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) override;
};