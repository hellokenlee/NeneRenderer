/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __RAY_H__
#define __RAY_H__

#include "vec3.h"

/*
	Ray: p(t) = a + b * t
*/

class ray
{
public:
	ray() {}
	ray(const vec3& a_, const vec3& b_): a(a_), b(b_) {}
	inline vec3 origin() const { return a; }
	inline vec3 direction() const { return b; }
	inline vec3 point_at(const float& t) const { return a + b * t; }
protected:
	vec3 a;
	vec3 b;
};


#endif // __RAY_H__
