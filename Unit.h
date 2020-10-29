/*!
 * \class Unit
 * 
 * \brief Unit class
 * 
 * A karakterekért felelős osztály.
 * 
 * 
 * \author  Borbély Roland, Vitéz Marcell, Voznek Péter
 * 
 * \version 3.2
 * 
 * \date 2020/10/15 17:05
 * 
 * Created on 2020/10/15 17:05
 */


#include <string>
#include "Parser.h"

class Unit
{
public:
	//! A fight függvény levezényli a csatát 2 Unit között.
	/*!
		\return A győztesre Unitra mutató objektum.
	*/ 
	Unit* fight(Unit *other /** [in] ellenfél karakter Unit */);

	/*! \brief Unit konstruktor
 	*         
 	*  
 	*  Beállítja a karakterek adatait a paraméterek alapján.
 	*  
 	*  \param name [in] karakter neve
	*  \param hp [in] karakter életereje
	*  \param dmg [in] karakter támadási ereje
	*  \param acd [in] karakter támadási ideje
 	*/
 	Unit(const std::string& name, int hP, int dmg, double acd) : b_name(name), b_hP(hP), b_dmg(dmg), b_acd(acd), b_maxHp(hP), b_xp(0), b_level(1) {}
	
	//! Ez a függvény a különböző Unitok értékeit parzolja le a bemeneti fájl alapján. 
	/*!
		\return A leparzolt Unitra mutató objektum.
	*/
	static Unit* parseUnit(const std::string& fname/** [in] elérési út */);

	//! Ez a függvény visszaadja a karakter életerejét.
	/*!
		\return A karakter életereje.
	*/
	int getHP() const { return b_hP; }

	//! Ez a függvény visszaadja a karakter nevét.
	/*!
		\return A karakter neve.
	*/
	std::string getName() const { return b_name; }

private:
	const std::string b_name;  ///< A karakter neve. 
	int b_hP; ///< A karakter életereje.
	int b_dmg; ///< A karakter támadási ereje.
	double b_acd; ///< Karakter támadási ideje.
	int b_maxHp; ///< Karakter maximális életereje.
	int b_xp; ///< Karakter fejlődési pont.
	int b_level; ///< Karakter szintje.

	/// Ez a függvény ellenőrzi/végzi a szintlépést.
	void levelup();
	/// Ez a függvény sebzést oszt ki a karakterre.
	void getHitBy(Unit *other /** [in] ellenfél karakter Unit */ );

	//! Ez a függvény visszaadja a karakter támadási erejét.
	/*
		\return A karakter támadási ereje.
	*/
	int getDmg() const { return b_dmg; }

	//! Ez a függvény visszaadja a karakter támadási idejét.
	/*
		\return A karakter támadási ideje.
	*/
	double getAcd() const { return b_acd; } 

	//! Ez a függvény visszaadja a karakter meghalt-e.
	/*
		\return Logikai változó, annak függvényében, hogy a karatker életben van-e.
	*/
	bool isDead() const;
};