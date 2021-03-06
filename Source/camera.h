/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "ray.h"
#include "vec3.h"


class camera
{
public:
	camera() = delete;
	camera(vec3 position, vec3 target, vec3 up, float fov, float ratio, float aperture, float focus_dist = 0.0f);
	camera(const vec3& o, const vec3& l, const vec3& w, const vec3& h);
	ray get_ray(const float u, const float v);
protected:
	vec3 m_origin;
	vec3 m_lower_left;
	vec3 m_w, m_u, m_v;
	vec3 m_width, m_height;
	float m_lens_radius;
};

#endif // __CAMERA_H__