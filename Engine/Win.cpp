#include "Win.h"

Win::Win() : pos(0.0f, 0.0f), boundingBox(pos, width, height)
{
}

RectF Win::getBoundingBox()
{
	return boundingBox;
}
