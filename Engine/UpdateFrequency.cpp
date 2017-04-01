#include "UpdateFrequency.h"

UpdateFrequency::UpdateFrequency() : updateFrequency(1.0f)
{
}

void UpdateFrequency::setUpdateFrequency(float newUF)
{
	updateFrequency = newUF;
}

float UpdateFrequency::getUpdateFrequency()
{
	return updateFrequency;
}
