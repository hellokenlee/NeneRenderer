/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __GROUP_H__
#define __GROUP_H__

#include <vector>
#include "surface.h"

/*
	A Group of Surfaces
*/

class group : public surface
{
public:
	group() = default;
	inline size_t add(std::shared_ptr<surface> surf) { size_t idx = m_list.size(); m_list.push_back(surf); return idx; }
	virtual bool hit(const ray& r, const float& mint, const float& maxt, hitinfo& h) const override;
private:
	std::vector<std::shared_ptr<surface>> m_list;
};

#endif // __GROUP_H__
