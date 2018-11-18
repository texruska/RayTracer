#include "scene.h"
#include "object.h"
#include "boundingbox.h"
#include "vec3.h"
#include "ray.h"
#include "colordata.h"
#include "plane.h"
#include "matrix3.h"

#include <iostream>
#include <experimental/optional>

using namespace RayTracer;

int main() {
	Scene scene;

	BoundingBox bb(&scene, Vec3(0,0,0), Vec3(0,0,0), Vec3(10,20,5));
	Object obj(&scene, Vec3(0,0,0), Vec3(0,0,0), &bb);

	std::cout << bb.forward() << std::endl;
	std::cout << bb.right() << std::endl;
	std::cout << bb.up() << std::endl;

	std::cout << std::endl;

	std::vector<Plane *> planes = bb.getPlanes();
	for (auto plane : planes) {
		std::cout << plane->getPosition() << " | " << plane->getNorm() << " | " << plane->getAngle() << std::endl;
	}

	std::cout << std::endl;

	bb.rotate(Vec3(45,0,0));

	std::cout << bb.forward() << std::endl;
	std::cout << bb.right() << std::endl;
	std::cout << bb.up() << std::endl;
	std::cout << std::endl;

//	bb.setPosition(Vec3(10,0,0));
	for (auto plane : planes) {
		std::cout << plane->getPosition() << " | " << plane->getNorm() << " | " << plane->getAngle() << std::endl;
	}

	std::cout << std::endl;
//
//	ColorData colorData;
//	colorData.color = Vec3(1,1,1);
//	colorData.emissivity = 0;
//	colorData.reflectivity = 1;
//	colorData.transmissivity = 0;
//
//	Plane surface(&scene, Vec3(0,0,0), Vec3(45,0,0), false, true);
//	surface.setColorData(colorData);
//
//	CameraSensor sensor(&scene, &surface, 10, 10, 1);
//	Camera cam(&scene, &sensor);
//	cam.captureImage();

	Vec3 v1(1,0,0);
	Vec3 v2(0,1,0);
	Vec3 v3(0,0,1);

	return 0;
}
