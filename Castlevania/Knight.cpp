#include "Knight.h"

Knight::Knight()
{
	minX = 0;
	maxX = 290;
	health = 2;
	SetState(KNIGHT_STATE_WALKING);
}

void Knight::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + KNIGHT_BBOX_WIDTH;
	bottom = y + KNIGHT_BBOX_HEIGHT;
}

void Knight::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);

	//
	// TO-DO: make sure Koopas can interact with the world and to each of them too!
	// 

	x += dx;
	y += dy;

	if (vx < 0 && x < minX) {
		x = minX; 
		vx = -vx;
	}

	if (vx > 0 && x + KNIGHT_BBOX_WIDTH > maxX) {
		x = maxX - KNIGHT_BBOX_WIDTH; 
		vx = -vx;
	}
}

void Knight::Render()
{
	int ani = KNIGHT_ANI_WALKING_LEFT;
	if (vx > 0) ani = KNIGHT_ANI_WALKING_RIGHT;
	else if (vx <= 0) ani = KNIGHT_ANI_WALKING_LEFT;

	if (isFrozen)
		animation_set->at(ani)->ResetFrame();

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void Knight::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KNIGHT_STATE_WALKING:
		vx = KNIGHT_WALKING_SPEED;
	}

}