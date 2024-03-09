#include "../headers/Outlaw.hpp"

bool OutlawVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return true;
}

bool OutlawVisitor::visit(const std::shared_ptr<Outlaw>& attacker) const {
    return false;
}

bool OutlawVisitor::visit(const std::shared_ptr<Orc>& attacker) const {
    return false;
}

Outlaw::Outlaw() : NPC(OutlawType, 0, 0) {
    killDistance = 10, moveDistance = 10;
}

Outlaw::Outlaw(int x, int y) : NPC(OutlawType, x, y) {
    killDistance = 10, moveDistance = 10;
}

Outlaw::Outlaw(std::istream& in) : NPC(OutlawType, in) {
    killDistance = 10, moveDistance = 10;
}

void Outlaw::save(std::ostream& out) {
    out << OutlawType << std::endl;
    NPC::save(out);
}

bool Outlaw::accept(const std::shared_ptr<NPC>& attacker) const {
    auto attacker_visitor = VisitorFactory::Create(attacker->gettype());

    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Outlaw> defender = std::dynamic_pointer_cast<Outlaw>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fight_notify(defender, result);

    return result;
}

std::ostream& operator << (std::ostream& out, Outlaw& Outlaw) {
    out << "Outlaw: " << *static_cast<NPC*>(&Outlaw) << std::endl;
    return out;
}

void Outlaw::print() {
    std::cout << *this;
}