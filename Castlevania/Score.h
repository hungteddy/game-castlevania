//#pragma once
//#include "Utils.h"
//#include "Sprites.h"
//#include "Simon.h"
//#include "Textures.h"
//#include "Sprites.h"
//
//
//class Score
//{
//private:
//	ID3DXFont* font;
//	RECT rect;
//	Simon* simon;
//
//	string information;
//
//	vector<LPSPRITE> simonHPList;
//	vector<LPSPRITE> enemyHPList;
//	vector<LPSPRITE> noHPList;
//
//	CSprite* heart;
//	CSprite* weapon;
//	CSprite* pinkrect;
//
//	CSprite* holyWater;
//	CSprite* cross;
//	CSprite* knife;
//	CSprite* stopWatch;
//
//	CSprite* upgrade1;
//	CSprite* upgrade2;
//
//	int simonHP;
//	int bossHP;
//	int uiHP;
//
//	int score;
//	int time;
//	int item;
//	int energy;
//	int life;
//	int stage;
//	int subWeapon;
//
//public:
//	Score();
//	~Score();
//	bool Initialize(LPDIRECT3DDEVICE9 d3ddv, Simon* simon);
//	//void Update(int bossHP, int time, int life, int stage);
//	void Update(int time, int stage, Simon* simon);
//	void Render(float x, float y, Simon* simon);
//	CSprite* axe;
//};