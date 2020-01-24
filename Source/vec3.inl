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

#endif // __VEC3_INL__
