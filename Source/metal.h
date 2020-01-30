/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __MATEL_H__
#define __MATEL_H__

#include "material.h"
#include <algorithm>

/*
	Metal Material
*/

class metal : public material
{
public:
	metal() = delete;
	metal(const vec3& a, const float& r) : m_albedo(a), m_roughness(std::min(r, 1.0f)) {}
	virtual bool scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const override;
protected:
	vec3 m_albedo;
	float m_roughness;
};

#endif // __MATEL_H__
