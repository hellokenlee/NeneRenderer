/*All Rights Reserved by KenLee hellokenlee@163.com*/

#include "group.h"


bool group::hit(const ray& r, const float& mint, const float& maxt, hitinfo& h) const
{
	hitinfo temp;
	bool hit_anything = false;
	float closest = maxt;
	for (size_t i = 0; i < m_list.size(); ++i)
	{
		if (m_list[i]->hit(r, mint, closest, temp))
		{
			hit_anything = true;
			closest = temp.time;
			h = temp;
		}
	}
	return hit_anything;
}