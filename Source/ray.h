/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __RAY_H__
#define __RAY_H__

#include "vec3.h"

/*
	Ray: p(t) = a + b * t
	Where a is origin and b is direction
*/

class ray
{
public:
	ray() = delete;
	ray(const vec3& a, const vec3& b): m_a(a), m_b(b) {}
	inline vec3 origin() const { return m_a; }
	inline vec3 direction() const { return m_b; }
	inline vec3 point_at(const float& t) const { return m_a + m_b * t; }
protected:
	vec3 m_a;
	vec3 m_b;
};


#endif // __RAY_H__
