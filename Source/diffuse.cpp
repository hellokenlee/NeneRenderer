/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "diffuse.h"

bool diffuse::scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const
{	
	vec3 target = h.position + h.normal + random_unit_sphere();
	scattered = ray(h.position, target - h.position);
	atten = m_albedo;
	return true;
}
