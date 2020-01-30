#ifndef __DIELECTRIC_H__
#define __DIELECTRIC_H__

#include "material.h"

class dielectric : public material
{
public:
	dielectric() = delete;
	dielectric(float ri) : m_ri(ri) {}
	virtual bool scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const override;
protected:
	float m_ri;		// Refractive Index
};

#endif // __DIELECTRIC_H__
