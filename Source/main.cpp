/*All Rights Reserved by KenLee hellokenlee@163.com*/
#include <ctime>
#include <vector>
#include <memory>
#include <cfloat>
#include <fstream>
#include <iostream>

#include "ray.h"
#include "vec3.h"
#include "sphere.h"
#include "camera.h"

using namespace std;

const float EPSILON = 0.001f;
const float GAMMA = 2.2f;
const float INV_GAMMA = 1.0f / GAMMA;

vector<unique_ptr<surface>> world;

vec3 random_in_unit_sphere()
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


vec3 trace(const ray& r)
{
	// World
	hitinfo h;
	for (auto& s : world)
	{
		if (s->hit(r, EPSILON, FLT_MAX, h))
		{
			vec3 target = h.position + h.normal + random_in_unit_sphere();
			return 0.5f * trace(ray(h.position, target - h.position));
		}
	}
	// Sky's Color
	vec3 unit_direction = normalize(r.direction());
	float f = 0.5f * (unit_direction.y + 1.0f);
	return (1.0f - f) * vec3(1.0f, 1.0f, 1.0f) + f * vec3(0.5f, 0.7f, 1.0f);
}


int main()
{	
	srand((unsigned int)time(nullptr));

	ofstream image;
	image.open("result.ppm");

	int ns = 4;
	int nx = 1024;
	int ny = 512;

	image << "P3\n" << nx << " " << ny << "\n255\n";

	camera cam(
		vec3(0.0f, 0.0f, 0.0f), vec3(-2.0f, -1.0f, -1.0f),
		vec3(4.0f, 0.0f, 0.0f), vec3(0.0f, 2.0f, 0.0f)
	);
	
	world.emplace_back(new sphere(vec3(0.0f, 0.0f, -1.0f), 0.5f));
	world.emplace_back(new sphere(vec3(0.0f, -100.5f, -1.0f), 100.f));
	
	for (int y = ny - 1; y >= 0; --y)
	{
		for (int x = 0; x < nx; ++x)
		{ 
			vec3 color(0.0f);
			
			for (int s = 0; s < ns; ++s)
			{
				float du = float(double(rand()) / double(RAND_MAX));
				float dv = float(double(rand()) / double(RAND_MAX));

				float u = (float(x) + du) / float(nx);
				float v = (float(y) + dv) / float(ny);

				ray r = cam.get_ray(u, v);
				color += trace(r);
			}
			
			color /= float(ns);
			// Gamma correction: c = c^0.5
			color = vec3(
				pow(color.r, INV_GAMMA),
				pow(color.g, INV_GAMMA), 
				pow(color.b, INV_GAMMA)
			);
			int ir = int(255.99f * color.x);
			int ig = int(255.99f * color.y);
			int ib = int(255.99f * color.z);

			image << ir << " " << ig << " " << ib << "\n";
		}
	}

	image.close();
	return 0;
}