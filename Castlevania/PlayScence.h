#pragma once
#include "Game.h"
#include "Grid.h"
#include "Textures.h"
#include "Scence.h"
#include "GameObject.h"
#include "Item.h"
#include "Brick.h"
#include "HiddenBrick.h"
#include "Torch.h"
#include "Simon.h"
#include "Map.h"
#include "Board.h"
#include "Effect.h"
#include "BrokenEffect.h"
#include "EffectWhip.h"
#include "Weapon.h"
#include "Knife.h"
#include "Axe.h"
#include "Cross.h"
#include "HolyWater.h"
#include "Sound.h"


class CPlayScene : public CScene
{
protected:
	Simon* player;					// A play scene has to have player, right? 

	vector<LPGAMEOBJECT> objects;
	//vector<LPGAMEOBJECT> coObjects;

	vector<int> arrTexturesID;
	vector<int> arrSpritesID;
	vector<int> arrAnimationsID;
	vector<int> arrAnimationSetsID;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_MAP(string line);

public:
	Map* map;
	Board* board;
	Sound* sound;
	Weapon* weapon;
	DWORD gameTime = GAME_TIME;
	int stage;
	ListGrids* listGrids;
	vector<GridObjects*> currentGrids;
	bool isClockWeaponUsed = false;
	DWORD clockWeaponCast;
	bool isUnload;
	bool isWin;
	bool isFinish;
public:
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	void ResetGameTime() {
		gameTime = GAME_TIME;
	}
	void RemoveObjects(vector<LPGAMEOBJECT>& coObjects);
	void GenerateWeapon();
	Simon* GetPlayer() { return player; }
	void ReplayMusicGame();

	//friend class CPlayScenceKeyHandler;
	~CPlayScene();
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CPlayScenceKeyHandler(CScene* s) :CScenceKeyHandler(s) {};
};

