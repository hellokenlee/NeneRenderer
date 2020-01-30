/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __DIFFUSE_H__
#define __DIFFUSE_H__

#include "material.h"

/*
	Lambertian Material
*/

class diffuse : public material
{
public:
	diffuse() = delete;
	diffuse(const vec3& a) : m_albedo(a) {}
	virtual bool scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const override;
protected:
	vec3 m_albedo;
};

#endif // __DIFFUSE_H__
