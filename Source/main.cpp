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
#include "group.h"
#include "camera.h"
#include "diffuse.h"
#include "metal.h"
#include "dielectric.h"

using namespace std;

const int MAX_DEPTH = 50;
const float EPSILON = 0.001f;
const float GAMMA = 2.2f;
const float INV_GAMMA = 1.0f / GAMMA;


vec3 trace(const ray& r, surface* world, int depth)
{
	// World
	hitinfo h;
	if (world->hit(r, EPSILON, FLT_MAX, h))
	{
		vec3 atten;
		ray scartted(vec3(0.0f), vec3(0.0f));
		if (depth < MAX_DEPTH && h.mtl != nullptr && h.mtl->scatter(r, h, atten, scartted))
		{
			return atten * trace(scartted, world, depth + 1);
		}
		else
		{
			return vec3(0.0f, 0.0f, 0.0f);
		}
	}
	// Sky's Color
	vec3 unit_direction = normalize(r.direction());
	float f = 0.5f * (unit_direction.y + 1.0f);
	return (1.0f - f) * vec3(1.0f, 1.0f, 1.0f) + f * vec3(0.5f, 0.7f, 1.0f);
}


std::shared_ptr<group> create_random_scene()
{
	int n = 500;
	group* world = new group{};

	// Ground
	world->add(
		shared_ptr<surface>(new sphere(
			vec3(0.0f, -1000.0f, 0.0f),
			1000.0f,
			shared_ptr<material>(new diffuse(vec3(0.5f, 0.5f, 0.5f)))
		))
	);

	// Many spheres
	//*
	for (int a = -11; a < 11; ++a)
	{
		for (int b = -11; b < 11; ++b)
		{
			float dice = float(rand()) / float(RAND_MAX);
			vec3 center(
				a + 0.9f * float(rand()) / float(RAND_MAX),
				0.2f,
				b + 0.9f * float(rand()) / float(RAND_MAX)
			);
			if ((center - vec3(4.0f, 0.2f, 0.0f)).length() > 0.9)
			{
				if (dice < 0.6f)
				{
					// Diffuse material
					float r = float(rand()) / float(RAND_MAX);
					float g = float(rand()) / float(RAND_MAX);
					float b = float(rand()) / float(RAND_MAX);
					world->add(
						shared_ptr<surface>(new sphere(
							center,
							0.2f,
							shared_ptr<material>(new diffuse(vec3(r, g, b)))
						))
					);
				}
				else if (dice < 0.9f)
				{
					// Metal material
					float r = 0.5f * (1.0f + float(rand()) / float(RAND_MAX));
					float g = 0.5f * (1.0f + float(rand()) / float(RAND_MAX));
					float b = 0.5f * (1.0f + float(rand()) / float(RAND_MAX));
					float roughness = 0.5f * float(rand()) / float(RAND_MAX);
					world->add(
						shared_ptr<surface>(new sphere(
							center,
							0.2f,
							shared_ptr<material>(new metal(vec3(r, g, b), roughness))
						))
					);
				}
				else
				{
					// Glass material
					world->add(
						shared_ptr<surface>(new sphere(
							center,
							0.2f,
							shared_ptr<material>(new dielectric(1.5))
						))
					);
				}
			}
		}
	}
	//*/

	// Three main spheres
	world->add(
		shared_ptr<surface>(new sphere(
			vec3(0.0f, 1.0f, 0.0f),
			1.0f,
			shared_ptr<material>(new dielectric(1.5))
		))
	);
	world->add(
		shared_ptr<surface>(new sphere(
			vec3(-4.0f, 1.0f, 0.0f),
			1.0f,
			shared_ptr<material>(new diffuse(vec3(0.4f, 0.2f, 0.1f)))
		))
	);
	world->add(
		shared_ptr<surface>(new sphere(
			vec3(4.0f, 1.0f, 0.0f),
			1.0f,
			shared_ptr<material>(new metal(vec3(0.7f, 0.6f, 0.5f), 0.0f))
		))
	);

	return shared_ptr<group>(world);
}

int main()
{	
	srand((unsigned int)time(nullptr));
	
	ofstream image;
	image.open("result.ppm");

	int ns = 32;
	/*
	int nx = 1024;
	int ny = 512;
	//*/
	
	//*
	int nx = 720;
	int ny = 480;
	//*/

	image << "P3\n" << nx << " " << ny << "\n255\n";

	camera cam(
		vec3(13.0f, 2.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), 
		20.0f, float(nx) / float(ny),
		0.1f, 10.0f
	);
	
	shared_ptr<group> world = create_random_scene();

	
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
				color += trace(r, world.get(), 0);
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
		printf("Progress: %.2f%%\n", float(ny - y) / float(ny) * 100.0f);
	}

	image.close();
	return 0;
}