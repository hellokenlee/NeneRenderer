/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "camera.h"

camera::camera(vec3 position, vec3 target, vec3 up, float fov, float ratio, float aperture, float focus_dist)
{
	//
	m_lens_radius = aperture / 2.0f;
	//
	if (focus_dist <= 0.0f)
	{
		focus_dist = (target - position).length();
	}

	// 这里假设透视点离近平面的距离为 1
	float theta = fov * 3.1415926f / 180.0f;
	float half_height = tan(theta / 2.0f);
	float half_width = ratio * half_height;
	
	m_origin = position;

	m_w = normalize(position - target);  // back direction
	m_u = normalize(cross(up, m_w));		// right direction
	m_v = cross(m_w, m_u);					// true up direction

	// 近平面的左下角坐标可以通过原点和摄像机方向计算出来
	m_lower_left = position - focus_dist * (half_width * m_u) - focus_dist * (half_height * m_v) - focus_dist * m_w;
	
	m_width = 2.0f * half_width * m_u * focus_dist;
	m_height = 2.0f * half_height * m_v * focus_dist;
}

camera::camera(const vec3& o, const vec3& l, const vec3& w, const vec3& h):
	m_origin(o), m_lower_left(l), m_width(w), m_height(h)
{}

ray camera::get_ray(const float u, const float v)
{
	vec3 rd = m_lens_radius * random_unit_disk();
	vec3 offset = m_u * rd.x + m_v * rd.y;
	return ray(m_origin + offset, m_lower_left + u * m_width + v * m_height - m_origin - offset);
}
