#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <cmath>
#include <memory>
#include <set>
#include <vector>
#include <ctime>

class Heroes;
class HeroesPair;
class Ork;
class Outlaw;
class Werewolf;
using set_t = std::set<std::shared_ptr<Heroes>>;


#define DISTANCE_FIGHT 100

enum HeroesClass{
    UNDEFIEND, WEREWOLF, OUTLAW, ORK 
};

const std::string OrkName[10] = {
    "Scrat", "Hoodwink", "Arriel", 
    "Mortra", "Jarry", "Shtorm",
    "Arsi", "Mexa", "Arta", "Shi"
};

const std::string OutlawName[10] = {
    "Lycan", "Shay", "Oskar",
    "Lovel", "Arald", "Beorn",
    "Victor", "Mara", "Greg", "Amon"
};

const std::string WerewolfName[10] = {
    "Phurion", "Trent", "Malith",
    "Tris", "Valrai", "Barlius",
    "Daspira", "Dayis", "Savari", "Naphi"
};

std::string getRandNameWerewolf();
std::string getRandNameOutlaw();
std::string getRandNameOrk();

class IFightObserver 
{
public:
    virtual void onFight(
        const std::shared_ptr<Heroes> attacker, 
        const std::shared_ptr<Heroes> defender, bool win
    ) = 0;
};

struct Visitor 
{
    virtual bool visit(const std::shared_ptr<Ork>&) const = 0;
    virtual bool visit(const std::shared_ptr<Werewolf>&) const = 0;
    virtual bool visit(const std::shared_ptr<Outlaw>&) const = 0;
};

class Heroes : public std::enable_shared_from_this<Heroes>
{
public:
    Heroes() = default;
    Heroes(HeroesClass hClass, std::string hName, short int x, short int y);
    Heroes(HeroesClass hClass, std::istream & is);

    virtual ~Heroes() = default;

    std::string getName() const;
    HeroesClass & getType();

    void subscribe(std::shared_ptr<IFightObserver> obs);
    void fightNotify(const std::shared_ptr<Heroes> defender, bool win);
    virtual bool isClose(const std::shared_ptr<Heroes> & other) const;
    
    virtual void print() = 0;
    virtual void save(std::ostream & os);
    friend std::ostream & operator<<(std::ostream & os, Heroes & heroes);

    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) = 0;

protected:
    short int _x {0};
    short int _y {0};
    HeroesClass _type;
    std::string _name;
    std::vector<std::shared_ptr<IFightObserver>> _obs;
};
