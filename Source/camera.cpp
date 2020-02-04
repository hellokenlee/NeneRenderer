/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "camera.h"

camera::camera(vec3 position, vec3 target, vec3 up, float fov, float ratio)
{
	// 这里假设透视点离近平面的距离为 1
	float theta = fov * 3.1415926f / 180.0f;
	float half_height = tan(theta / 2.0f);
	float half_width = ratio * half_height;
	
	m_origin = position;

	vec3 w = normalize(position - target);  // back direction
	vec3 u = normalize(cross(up, w));		// right direction
	vec3 v = cross(w, u);					// true up direction

	// 近平面的左下角坐标可以通过原点和摄像机方向计算出来
	m_lower_left = position - (half_width * u) - (half_height * v) - w;
	
	m_width = 2.0f * half_width * u;
	m_height = 2.0f * half_height * v;
}

camera::camera(const vec3& o, const vec3& l, const vec3& w, const vec3& h):
	m_origin(o), m_lower_left(l), m_width(w), m_height(h)
{}

ray camera::get_ray(const float u, const float v)
{
	return ray(m_origin, m_lower_left + u * m_width + v * m_height - m_origin);
}
