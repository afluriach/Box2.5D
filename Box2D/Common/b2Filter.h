#ifndef B2_FILTER_H
#define B2_FILTER_H

#include <Box2D/Common/b2Settings.h>

/// This holds contact filtering data.
struct b2Filter
{
	b2Filter()
	{
		categoryBits = 0x0000;
		maskBits = 0x0;
		groupIndex = 0;
		layers = 0;
	}

	/// The collision category bits. Normally you would just set one bit.
	uint32 categoryBits;

	/// The collision mask bits. This states the categories that this
	/// shape would accept for collision.
	uint32 maskBits;

	/// Collision groups allow a certain group of objects to never collide (negative)
	/// or always collide (positive). Zero means no collision group. Non-zero group
	/// filtering always wins against the mask bits.
	int32 groupIndex;

	uint32 layers;

	//Refactored from b2ContactFilter::ShouldCollide.
	bool shouldCollide(const b2Filter& other) const;
	//In this case, the filter might not be compared against the identity of an object.
	//If the provided filter has a blank identity, simply check a match by type & layers.
	bool isQueryCollide(const b2Filter& other) const;

	bool isBlankType() const;
};

#endif
