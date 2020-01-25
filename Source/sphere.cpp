/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "sphere.h"

/*
	p(t) = a + bt
	(p - c) ， (p - c) = R * R
	(a + bt - c) ， (a + bt - c)
	(t * t)(b ， b) + (2 * t)(b ， (a - c)) + (a - c) ， (a - c) = R * R
	Δ = B * B - 4 * A * C
*/
bool sphere::hit(const ray& r)
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0f * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float delta = b * b - 4.0f * a * c;
	return (delta > 0);
}
