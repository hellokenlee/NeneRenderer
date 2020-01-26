/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "camera.h"


camera::camera(const vec3& o, const vec3& l, const vec3& w, const vec3& h):
	m_origin(o), m_lower_left(l), m_width(w), m_height(h)
{}

ray camera::get_ray(const float u, const float v)
{
	return ray(m_origin, m_lower_left + u * m_width + v * m_height - m_origin);
}
