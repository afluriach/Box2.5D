
#include <Box2D/Common/b2Filter.h>

bool b2Filter::shouldCollide(const b2Filter& other) const
{
	bool layersCollide = layers & other.layers;

	if (groupIndex == other.groupIndex && groupIndex != 0)
	{
		return groupIndex > 0 && layersCollide;
	}
	else
	{
		return (maskBits & other.categoryBits) != 0 &&
			(categoryBits & other.maskBits) != 0 &&
			layersCollide;
	}
}

bool b2Filter::isQueryCollide(const b2Filter& other) const
{
	return other.isBlankType() ?
		(other.maskBits & categoryBits) && (other.layers & layers) :
		shouldCollide(other)
	;
}

bool b2Filter::isBlankType() const
{
	return categoryBits == 0 && groupIndex == 0;
}
