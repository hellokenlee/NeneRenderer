/*All Rights Reserved by KenLee hellokenlee@163.com*/
#include <fstream>
#include <iostream>

#include "ray.h"
#include "vec3.h"
#include "sphere.h"

using namespace std;

sphere gsphere(vec3(0.0f, 0.0f, -1.0f), 0.5f);

vec3 trace(const ray& r)
{
	if (gsphere.hit(r))
	{
		return vec3(1.0f, 0.0f, 0.0f);
	}
	vec3 unit_direction = normalize(r.direction());
	float f = 0.5f * (unit_direction.y + 1.0f);
	return (1.0f - f) * vec3(1.0f, 1.0f, 1.0f) + f * vec3(0.5f, 0.7f, 1.0f);
}


int main()
{	
	ofstream image;
	image.open("result.ppm");

	int nx = 200;
	int ny = 100;

	image << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left(-2.0f, -1.0f, -1.0f);
	vec3 width(4.0f, 0.0f, 0.0f);
	vec3 height(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);

	for (int y = ny - 1; y >= 0; --y)
	{
		for (int x = 0; x < nx; ++x)
		{ 
			float u = float(x) / float(nx);
			float v = float(y) / float(ny);

			ray r(origin, lower_left + u * width + v * height);

			vec3 color = trace(r);

			int ir = int(255.99f * color.x);
			int ig = int(255.99f * color.y);
			int ib = int(255.99f * color.z);

			image << ir << " " << ig << " " << ib << "\n";
		}
	}

	return 0;
}