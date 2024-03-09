#pragma once

#include "npc.h"

struct OrkVisitor : public Visitor 
{
    bool visit(const std::shared_ptr<Outlaw>&) const override;
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Ork>&) const override;
};  

class Ork final : public Heroes {
public:
    Ork(std::string hName, short int x, short int y);
    Ork(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Ork & sq);
    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) override;
};
