/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "metal.h"

bool metal::scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const
{
	vec3 reflected = reflect(normalize(in.direction()), h.normal);
	scattered = ray(h.position, reflected + m_roughness * random_unit_sphere());
	atten = m_albedo;
	return (dot(scattered.direction(), h.normal) > 0);
}
