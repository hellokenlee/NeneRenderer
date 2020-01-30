/*All Rights Reserved by KenLee hellokenlee@163.com*/
#ifndef __VEC3_H__
#define __VEC3_H__

#include <cmath>
#include <iostream>

class vec3
{
public:
	union
	{
		float data[3];
		struct { float x, y, z; };
		struct { float r, g, b; };
		struct { float s, t, p; };
	};
public:
	vec3() {}
	vec3(float d) : x(d), y(d), z(d) {}
	vec3(float d0, float d1, float d2) : x(d0), y(d1), z(d2) {}
	
	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-x, -y, -z); }

	inline float operator[](size_t i) const { return data[i]; }
	inline float& operator[](size_t i) { return data[i]; }

	inline vec3& operator+=(const vec3& rhs);
	inline vec3& operator-=(const vec3& rhs);
	inline vec3& operator*=(const vec3& rhs);
	inline vec3& operator/=(const vec3& rhs);

	inline vec3& operator*=(const float c);
	inline vec3& operator/=(const float c);

	inline float length() const { return sqrt(x * x + y * y + z * z); }
	inline float squared_length() const { return (x * x + y * y + z * z); }

	inline void normalize();
};

inline std::istream& operator>>(std::istream &is, vec3& v);

inline std::ostream& operator<<(std::ostream &os, vec3& v);

inline vec3 operator+(const vec3& lhs, const vec3& rhs);

inline vec3 operator-(const vec3& lhs, const vec3& rhs);

inline vec3 operator*(const vec3& lhs, const vec3& rhs);

inline vec3 operator/(const vec3& lhs, const vec3& rhs);

inline vec3 operator*(const float& lhs, const vec3& rhs);

inline vec3 operator*(const vec3& lhs, const float& rhs);

inline vec3 operator/(const vec3& lhs, const float& rhs);

inline float dot(const vec3& lhs, const vec3& rhs);

inline vec3 cross(const vec3& lhs, const vec3& rhs);

inline vec3 normalize(const vec3& v);

inline vec3 reflect(const vec3& vin, const vec3& vnormal);

inline vec3 random_unit_vec3();

#include "vec3.inl"

#endif // __VEC3_H__
