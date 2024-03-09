#include "../include/ork.h"

bool OrkVisitor::visit(const std::shared_ptr<Ork>& attacker) const {
    return 0;
}

bool OrkVisitor::visit(const std::shared_ptr<Outlaw>& attacker) const {
    return 1;
}

bool OrkVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return 0;
}

Ork::Ork(std::string hName, short int x, short int y) : Heroes(ORK, hName, x, y) {}

Ork::Ork(std::istream & is) : Heroes(ORK, is) {}

void Ork::print()
{
    std::cout << *this;
}

void Ork::save(std::ostream & os)
{
    os << ORK << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Ork & sq)
{
    os << "Ork: " << *static_cast<Heroes*> (&sq) << std::endl;
    return os;
}

int Ork::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Ork> defender = std::dynamic_pointer_cast<Ork>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fightNotify(defender, result);

    return result;
}
