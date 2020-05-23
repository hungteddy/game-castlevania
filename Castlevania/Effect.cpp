#include "Effect.h"

void Effect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount() - firstRenderTime > EFFECT_TIME)
		isExposed = true;
}

void Effect::Render()
{
	animation_set->at(0)->Render(x, y);
	//RenderBoundingBox();
	DebugOut(L"[EFFECT] render %f %f\n", x, y);
}

void Effect::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 0;
	b = 0;
}

