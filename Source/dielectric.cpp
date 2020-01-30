/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "dielectric.h"

bool dielectric::scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const
{
	vec3 outward_normal;
	vec3 reflected = reflect(in.direction(), h.normal);
	float ni_over_nt;
	atten = vec3(1.0, 1.0, 1.0);
	vec3 refracted;
	float reflect_prob;
	float cosine;

	if (dot(in.direction(), h.normal) > 0)
	{
		outward_normal = -h.normal;
		ni_over_nt = m_ri;
		cosine = m_ri * dot(in.direction(), h.normal) / in.direction().length();
	}
	else
	{
		outward_normal = h.normal;
		ni_over_nt = 1.0f / m_ri;
		cosine = -dot(in.direction(), h.normal) / in.direction().length();
	}

	if (refract(in.direction(), outward_normal, ni_over_nt, refracted))
	{
		reflect_prob = schlick(cosine, m_ri);
	}
	else
	{
		reflect_prob = 1.0f;
	}

	if (float(double(rand()) / double(RAND_MAX)) < reflect_prob)
	{
		scattered = ray(h.position, reflected);
	}
	else
	{
		scattered = ray(h.position, refracted);
	}
	return true;
}