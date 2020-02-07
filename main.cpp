#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>
#include <numeric>
#include <memory>

using namespace std;

struct NPC {
    int health = 0;
    int armor = 0;
    string type_npc = "empty";
};

struct BasicSoldier : public NPC {
    BasicSoldier(){
        health = 50;
        armor = 50;
        type_npc = "Basic Soldier";
    }
};

struct AdvanceSoldier : public NPC {
    AdvanceSoldier(){
        health = 100;
        armor = 100;
        type_npc = "Advance Soldier";
    }
};
struct Boss : public NPC{
    Boss (){
        health = 500;
        armor = 200;
        type_npc = "Boss";
    }
};
class All_Heroes {
public:
    All_Heroes (const string& name = "Anybody") : type(name){}
    virtual void HitFromAK47 (NPC& first_person) const {};

private:
    string type;
};
class MainHero : public  All_Heroes{
public:
    explicit MainHero(const string& name1): All_Heroes(name1), name_person(name1){
    };
    void HitFromAK47 (NPC& first_person)const override {
        cout << name_person << " damaged " << first_person.type_npc << endl;
        cout << "current health " << first_person.health - 10 << endl;
        cout << "current armor " << first_person.armor - 20 << endl;
    }

private:
    const string name_person;
};
class FriendMainHero : public All_Heroes{
public:
    FriendMainHero(const string& name1) : All_Heroes(name1), name_friend(name1){};
    void HitFromAK47 (NPC& first_person) const override {
        cout << name_friend << " damaged " << first_person.type_npc << endl;
        cout << "current health " << first_person.health - 5 << endl;
        cout << "current armor " << first_person.armor - 10 << endl;
    }
private:
    const string name_friend;
};
void TryKillEnemy (const All_Heroes& hero,NPC& enemy){
    hero.HitFromAK47(enemy);

}
int main() {
    string person,enemy;
    MainHero first("James");
    shared_ptr<All_Heroes> base;



    return 0;
}