#include "Monster.h"

Monster Monster::parse(const std::string& fname) {
	std::vector <std::string> keysNeeded {"name", "health_points", "attack_cooldown"};
	JSON returnedJSON = JSON::parseFromFile(fname);
	bool okay = true;
	for (auto key : keysNeeded)
        	if(!returnedJSON.count(key))
			okay = false;

	Damage damage;

	if(returnedJSON.count("damage")) damage.physical = returnedJSON.get<int>("damage");
	else damage.physical = 0;
	
	if(returnedJSON.count("magical-damage")) damage.magical = returnedJSON.get<int>("magical-damage");
	else damage.magical = 0;

	if (okay) 
	    return Monster(returnedJSON.get<std::string>("name"), 
			returnedJSON.get<int>("health_points"),
			damage,
			returnedJSON.get<double>("attack_cooldown"));
	else throw JSON::ParseException("Incorrect attributes in " + fname + "!");
}


void Monster::getHitBy(Hero* other) {
	//itt két ütés között is lehet szintlépés, vagy csak, ha mind a két ütés megtörtént?
	// phyiscal üt, megvan a 100 xp szintlépés, jön a magical
	// vagy physical üt, magical üt és szintlépés?
	if(b_hP - other->getDamage().physical>0){
		other->addXp(other->getDamage().physical);
		b_hP-=other->getDamage().physical;
		if(b_hP - other->getDamage().magical > 0) {
			other->addXp(other->getDamage().magical);
			b_hP -= other->getDamage().magical;
		}
		else {
			other->addXp(b_hP);
			b_hP = 0;
		}
	}
	else {
		other->addXp(b_hP);
		b_hP = 0;
	}
	other->levelup();
}
