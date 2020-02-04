/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __VEC3_INL__
#define __VEC3_INL__

inline vec3& vec3::operator+=(const vec3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

inline vec3& vec3::operator-=(const vec3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

inline vec3& vec3::operator*=(const vec3& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

inline vec3& vec3::operator/=(const vec3& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

inline vec3& vec3::operator*=(const float c)
{
	x *= c;
	y *= c;
	z *= c;
	return *this;
}

inline vec3& vec3::operator/=(const float c)
{
	x /= c;
	y /= c;
	z /= c;
	return *this;
}

inline void vec3::normalize()
{
	float k = 1.0f / length();
	x *= k;
	y *= k;
	z *= k;
}

inline std::istream& operator>>(std::istream &is, vec3& v)
{
	is >> v.x >> v.y >> v.z;
	return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

inline vec3 operator+(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline vec3 operator-(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline vec3 operator*(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline vec3 operator/(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

inline vec3 operator*(const float& lhs, const vec3& rhs)
{
	return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

inline vec3 operator*(const vec3& lhs, const float& rhs)
{
	return vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

inline vec3 operator/(const vec3& lhs, const float& rhs)
{
	return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline float dot(const vec3& lhs, const vec3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline vec3 cross(const vec3& lhs, const vec3& rhs)
{
	return vec3(
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
	);
}

inline vec3 normalize(const vec3& v)
{
	return v / v.length();
}

inline vec3 reflect(const vec3& vin, const vec3& vnormal)
{
	return vin - 2.0f * dot(vin, vnormal) * vnormal; 
}

inline bool refract(const vec3& vin, const vec3& vnormal, float ni_over_nt, vec3& refracted)
{
	
	// Ref: https://zhuanlan.zhihu.com/p/31127076 
	vec3 v = normalize(vin);
	float d = dot(v, vnormal);
	float sqr_cos_t = 1.0f - (ni_over_nt * ni_over_nt) * (1.0f - d * d);
	// 
	if (sqr_cos_t > 0)
	{
		refracted = ni_over_nt * (v - vnormal * d) - vnormal * sqrt(sqr_cos_t);
		return true;
	}
	// Total internal reflection
	return false;
}

inline vec3 random_unit_disk()
{
	vec3 point;
	do 
	{
		vec3 square = vec3(
			float(double(rand()) / double(RAND_MAX)),
			float(double(rand()) / double(RAND_MAX)),
			0.0f
		);
		point = 2.0f * square - vec3(1.0f, 1.0f, 0.0f);
	} while (dot(point, point) > 1.0f);
	return point;
}

inline vec3 random_unit_sphere()
{
	vec3 point;
	do
	{
		vec3 cube = vec3(
			float(double(rand()) / double(RAND_MAX)),
			float(double(rand()) / double(RAND_MAX)),
			float(double(rand()) / double(RAND_MAX))
		);
		point = 2.0f * cube - vec3(1.0f);
	} while (point.squared_length() >= 1.0f);
	return point;
}

inline float schlick(float cosine, float ri)
{
	float r0 = (1.0f - ri) / (1.0f + ri);
	r0 = r0 * r0;
	return r0 + (1.0f - r0) * pow((1.0f - cosine), 5.0f);
}

#endif // __VEC3_INL__
