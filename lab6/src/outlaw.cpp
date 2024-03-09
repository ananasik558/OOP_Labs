#include "../include/outlaw.h"

bool OutlawVisitor::visit(const std::shared_ptr<Outlaw>& attacker) const {
    return 0;
}

bool OutlawVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return 1;
}

bool OutlawVisitor::visit(const std::shared_ptr<Ork>& attacker) const {
    return 0;
}

Outlaw::Outlaw(std::string hName, short int x, short int y) : Heroes(OUTLAW, hName, x, y) {}

Outlaw::Outlaw(std::istream & is) : Heroes(OUTLAW, is) {}

void Outlaw::print()
{
    std::cout << *this;
}

void Outlaw::save(std::ostream & os)
{
    os << OUTLAW << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Outlaw & sq)
{
    os << "Outlaw: " << *static_cast<Heroes*> (&sq) << std::endl;
    return os;
}

int Outlaw::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Outlaw> defender = std::dynamic_pointer_cast<Outlaw>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fightNotify(defender, result);

    return result;
}
