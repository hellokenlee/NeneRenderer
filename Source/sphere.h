/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "ray.h"
#include "vec3.h"


class sphere
{
public:
	sphere() = delete;
	sphere(const vec3& c, const float& r) : center(c), radius(r) {}
	bool hit(const ray& r);
protected:
	vec3 center;
	float radius;
};

#endif // __SPHERE_H__
