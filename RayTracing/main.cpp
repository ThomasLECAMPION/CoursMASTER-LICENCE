#include "utility.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "triangle.h"
#include "camera.h"
#include "material.h"
#include "light.h"

#include <iostream>
#include <vector>

color ray_color(const ray& r, const hittable& world, const std::vector<light>& lights) {
    hit_record rec;
    color pixel(0,0,0);

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    color background = (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);

    if (world.hit(r, 0.001, infinity, rec)) {
        if(rec.mat_ptr->scatter(rec, pixel, lights, world)) {
          return pixel;
        }
    }
    return background;

}

int main() {

    // Image
    const auto aspect_ratio = 4.0 / 3.0;
    const int image_width = 800;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // World
    hittable_list world;

    auto material_back = make_shared<phong>(color(0.0, 1.0, 1.0));
    auto material_down = make_shared<phong>(color(0.0, 0.0, 1.0));
    auto material_up = make_shared<phong>(color(0.0, 1.0, 0.0));
    auto material_left = make_shared<phong>(color(1.0, 0.0, 0.0));
    auto material_right = make_shared<phong>(color(1.0, 0.0, 1.0));
    auto material_sphere1 = make_shared<glass>(color(1.0, 1.0, 0.0));
    auto material_sphere2 = make_shared<phong>(color(0.7, 0.2, 0.7));
    auto material_sphere3 = make_shared<mirror>(color(1.0, 1.0, 0.0));


    //back
    world.add(make_shared<triangle>(point3(-1.0, -1.0, -1.0), point3(1.0, -1.0, -1.0), point3(-1.0, 1.0, -1.0), material_back));
    world.add(make_shared<triangle>(point3(1.0, -1.0, -1.0), point3(1.0, 1.0, -1.0), point3(-1.0, 1.0, -1.0), material_back));

    //down
    world.add(make_shared<triangle>(point3(-1.0, -1.0, -1.0), point3(-1.0, -1.0, 1.0), point3(1.0, -1.0, -1.0), material_down));
    world.add(make_shared<triangle>(point3(1.0, -1.0, -1.0), point3(-1.0, -1.0, 1.0), point3(1.0, -1.0, 1.0), material_down));
    //up
    world.add(make_shared<triangle>(point3(-1.0, 1.0, -1.0), point3(-1.0, 1.0, 1.0), point3(1.0, 1.0, -1.0), material_up));
    world.add(make_shared<triangle>(point3(1.0, 1.0, -1.0), point3(-1.0, 1.0, 1.0), point3(1.0, 1.0, 1.0), material_up));
    //left
    world.add(make_shared<triangle>(point3(-1.0, -1.0, -1.0), point3(-1.0, 1.0, -1.0), point3(-1.0, -1.0, 1.0), material_left));
    world.add(make_shared<triangle>(point3(-1.0, 1.0, -1.0), point3(-1.0, 1.0, 1.0), point3(-1.0, -1.0, 1.0), material_left));
    //right
    world.add(make_shared<triangle>(point3(1.0, -1.0, -1.0), point3(1.0, 1.0, -1.0), point3(1.0, -1.0, 1.0), material_right));
    world.add(make_shared<triangle>(point3(1.0, 1.0, -1.0), point3(1.0, 1.0, 1.0), point3(1.0, -1.0, 1.0), material_right));

    world.add(make_shared<sphere>(point3(-0.75,-0.5,-0.5), 0.25, material_sphere1));
    world.add(make_shared<sphere>(point3(0.0,-0.5,-0.5), 0.25, material_sphere2));
    world.add(make_shared<sphere>(point3(0.75,-0.5,-0.5), 0.25, material_sphere3));

    // Camera
    point3 lookfrom(0,0.5,6);
    point3 lookat(0,0,0);
    vec3 vup(0,1,0);
    auto dist_to_focus = (lookfrom-lookat).length();
    auto aperture = 0.1;

    camera cam(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);

    // Light
    std::vector<light> lights;
    lights.push_back(light(point3(0,0.95,0.5), 0.75));


    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        //Progress bar
        std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            ray r = cam.get_ray(u, v);
            color pixel = ray_color(r, world, lights);

            write_color(std::cout, pixel);
        }
    }

    std::cerr << "\nDone.\n";
}
