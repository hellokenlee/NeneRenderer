/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "sphere.h"

/*
	p(t) = a + bt
	(p - c) ， (p - c) = R * R
	(a + bt - c) ， (a + bt - c)
	(t * t)(b ， b) + (2 * t)(b ， (a - c)) + (a - c) ， (a - c) = R * R
	Δ = B * B - 4 * A * C
*/
bool sphere::hit(const ray& r, const float& mint, const float& maxt, hitinfo& h) const
{
	vec3 oc = r.origin() - m_center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0f * dot(oc, r.direction());
	float c = dot(oc, oc) - m_radius * m_radius;
	float delta = b * b - 4.0f * a * c;
	if (delta > 0.0f)
	{
		//
		h.mtl = m_material;
		//
		float t;
		t= (-b - sqrt(delta)) / (2.0f * a);
		if (t < maxt && t > mint)
		{
			h.time = t;
			h.position = r.point_at(t);
			h.normal = (h.position - m_center) / m_radius;
			return true;
		}
		t = (-b + sqrt(delta)) / (2.0f * a);
		if (t < maxt && t > mint)
		{
			h.time = t;
			h.position = r.point_at(t);
			h.normal = (h.position - m_center) / m_radius;
			return true;
		}
	}
	h.mtl = nullptr;
	return false;
}
