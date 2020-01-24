/*All Rights Reserved by KenLee hellokenlee@163.com*/
#include <fstream>
#include <iostream>

#include "vec3.h"

using namespace std;

int main()
{	
	ofstream image;
	image.open("result.ppm");

	int nx = 200;
	int ny = 100;

	image << "P3\n" << nx << " " << ny << "\n255\n";

	for (int y = ny - 1; y >= 0; --y)
	{
		for (int x = 0; x < nx; ++x)
		{ 
			vec3 color(float(x) / float(nx), float(y) / float(ny), 0.2f);

			int ir = int(255.99f * color.x);
			int ig = int(255.99f * color.y);
			int ib = int(255.99f * color.z);

			image << ir << " " << ig << " " << ib << "\n";
		}
	}

	return 0;
}