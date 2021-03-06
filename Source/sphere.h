/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "ray.h"
#include "vec3.h"
#include "surface.h"


class sphere : public surface
{
public:
	sphere() = delete;
	sphere(const vec3& c, const float& r, std::shared_ptr<material> m) : m_center(c), m_radius(r), m_material(m) {}
	virtual bool hit(const ray& r, const float& mint, const float& maxt, hitinfo& h) const override;
	inline vec3 center() { return m_center; }
	inline float radius() { return m_radius; }
protected:
	vec3 m_center;
	float m_radius;
	std::shared_ptr<material> m_material;
};

#endif // __SPHERE_H__
