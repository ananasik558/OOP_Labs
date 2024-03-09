#include "../include/factory.h"


std::shared_ptr<Heroes> Factory::createHero(HeroesClass hClass, short int x, short int y) {
    std::string hName;
    std::shared_ptr<Heroes> res;
    switch (hClass) {
        case HeroesClass::ORK:
            hName = getRandNameWerewolf();
            res = std::make_shared<Ork>(hName, x, y);
            break;
        case HeroesClass::WEREWOLF:
            hName = getRandNameOutlaw();
            res = std::make_shared<Werewolf>(hName, x, y);
            break;
        case HeroesClass::OUTLAW:
            hName = getRandNameOrk();
            res = std::make_shared<Outlaw>(hName, x, y);
            break;
        default:
            throw std::invalid_argument("Error! createHero to param : invalid HeroesClass");
            break;
    }

    if (res) {
        res->subscribe(TextObserver::get());
        res->subscribe(FileObserver::get());
    }

    return res;
}

std::shared_ptr<Heroes> Factory::createHero(std::istream & is) {
    int hClass{0};
    std::shared_ptr<Heroes> res;
    if (is >> hClass) {
        switch (hClass) {
            case ORK:
                res = std::make_shared<Ork>(is);
                break;
            case WEREWOLF:
                res = std::make_shared<Werewolf>(is);
                break;
            case OUTLAW:
                res = std::make_shared<Outlaw>(is);
                break;
            default:
                throw std::invalid_argument("Error! createHero to file : invalid HeroesClass");
                break;
        }
    } else {
        std::cout <<"Huy\n";
        throw std::invalid_argument("Error! createHero to file : invalid enter into file");
    }

    if (res) {
        res->subscribe(TextObserver::get());
        res->subscribe(FileObserver::get());
    }

    return res;
}
