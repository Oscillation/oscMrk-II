#pragma once
#include <vector>
#include <fstream>
#include <iostream>

#include "DeadMob.h"
#include "Mob\Mob.h"
#include "Mob\MinorMob.h"
#include "Mob\MajorMob.h"
#include "Math\GeneralMath.h"
#include "ResourceHolders\TextureHolder.h"
#include "Item\LootItem.h"
#include "Inventory\LootTable.h"
#include "PathFinder\PathFinder.h"
#include "Tree.h"

///<summary>Tiles from the starting position.</summary>
#define WalkingDistance 10

///<summary>%</summary>
#define WalkChancePct 50

///<summary>In seconds.</summary>
#define TimeBetweenPathing 0.5f

#define UPDATE_PATH 1.f

struct LootTable;

struct DeadMob;

class MobManager : public sf::Drawable{
public:
	MobManager(TextureHolder & textureHolder, std::vector<std::vector<gen::Tile>>* tiles, PathFinder* pathFinder);
	MobManager();
	~MobManager();

	typedef std::vector<Mob*> Mobs;
	typedef std::vector<MinorMob> MinorMobs;
	typedef std::vector<MajorMob> MajorMobs;

	std::vector<DeadMob> deadMobs;
	Mobs mobs;
	MinorMobs minorMobs;
	MajorMobs majorMobs;

	std::vector<std::vector<gen::Tile>>* tiles;
	std::vector<LootTable> LootTables;
	/*std::vector<int> update_IDs;
	std::vector<int> pathing_IDs;
	std::vector<int> aggro_IDs;*/

	mobtree::Tree m_tree;

	void Add(Mob & mob);
	void Build_Tree();

	void Update(sf::Time & deltaTime, sf::Vector2f const& playerPosition);
	void SetView(sf::View const& view);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	
	sf::View view;

	LootTable* GetLootTable(TYPE const& type);
	Mob* getAtPosition(float x, float y);
	Mob* getAtPosition(sf::Vector2f position);
	int GetIndexOf(Mob const& mob);
	int AliveMobs();
	TextureHolder* textures;
	sf::Vector2<float> playerPosition;

private:
	PathFinder* pathFinder;

	bool update(int const& id);
};

/*	   '.'�`\/�`'.'
 ___________\/_____________
/��������������������������\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|						   |	o     O                                                      0                  0           o  o
|						   |	�	O				 <><                 ><>  ><>                     _              o
|						   |		o			 _______________			><>                    ____|___________        o
|						   |			��		/				\		0  o                      / o o o o o o o o\___ � �
|						   |_/|			0		|				|_/|	`	  O                   \___________________(X) ~ �~
| .______________________. |_-|		  O 0	    | .___________. |_-|		0� �           <><        ~ ' �  ~   ~ 
\__________________________/ \|		o			\_______________/ \|	o �o


Two whales on an adventure.
*/