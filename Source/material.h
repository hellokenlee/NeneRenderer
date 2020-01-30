/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "ray.h"
#include "surface.h"

class material
{
public:
	virtual bool scatter(const ray& in, const hitinfo& h, vec3& atten, ray& scattered) const = 0;
};

#endif // __MATERIAL_H__
