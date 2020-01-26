/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "ray.h"

/*
	Hit information
*/

struct hitinfo
{
	float time;
	vec3 normal;
	vec3 position;
};


/*
	Base class for all shapes
*/

class surface
{
public:
	virtual bool hit(const ray& r, const float& mint, const float& maxt, hitinfo& h) const = 0;
};

#endif // __SURFACE_H__
