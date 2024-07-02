#ifndef MATERIAL_H
#define MATERIAL_H

#include "utility.h"
#include "light.h"
#include <cmath>

struct hit_record;

class material {
    public:
        virtual bool scatter(
            const hit_record& rec, color& pixel, const std::vector<light>& lights, const hittable& world
        ) const = 0;
};

class phong : public material {
    public:
        phong(const color& a) : albedo(a) {}

        virtual bool scatter(
            const hit_record& rec, color& pixel, const std::vector<light>& lights, const hittable& world
        ) const override {
            //paramètres constants (entre 0 et 1)
            const double ambient = 0.05;
            const double diffuse = 0.8;
            const double specular = 0.45;
            //ambient
            pixel += albedo*ambient;
            
            std::vector<light> lights_to_compute;
            hit_record test;
            for(int i=0; i<lights.size(); i++) {
                ray light_ray(rec.p, unit_vector(lights[i].origin() - rec.p));
                if(!world.hit(light_ray, 0.001, (lights[i].origin() - rec.p).length(), test))
                    lights_to_compute.push_back(lights[i]);
            }

            for(int i=0; i<lights_to_compute.size(); i++) {
                vec3 light_direction = unit_vector(lights_to_compute[i].origin() - rec.p);
                //diffuse
                double scalar = dot(light_direction, rec.normal);
                if(scalar > 0) {
                  pixel += albedo*diffuse*scalar*lights_to_compute[i].brightness();
                }

                //specular
                int alpha = 10;
                vec3 reflect = unit_vector(rec.normal*(2*scalar) - light_direction);
                double teta = pow( (dot(reflect, light_direction)<0.0)?0.0:dot(reflect, light_direction) ,specular );
                if(teta > 0) {
                  pixel += specular*color(pow(teta,alpha), pow(teta,alpha), pow(teta,alpha))*lights_to_compute[i].brightness();
                }
            }

            return true;
        }

    public:
        color albedo;
};

class mirror : public material {
    public:
        mirror(const color& a) : albedo(a) {}

        virtual bool scatter(
            const hit_record& rec, color& pixel, const std::vector<light>& lights, const hittable& world
        ) const override {
            for(int i=0; i<lights.size(); i++) {
              vec3 light_direction = unit_vector(lights[i].origin() - rec.p);
              ray rayReflection = ray(rec.p, unit_vector(2 * rec.normal + light_direction));
              hit_record rec_reflection;
              hit_record test;

              if (world.hit(rayReflection, 0.001, infinity, rec_reflection)) {
                  std::vector<light> lights_to_compute;
                  for(int i=0; i<lights.size(); i++) {
                      ray light_ray(rec_reflection.p, unit_vector(lights[i].origin() - rec_reflection.p));
                      if(!world.hit(light_ray, 0.001, (lights[i].origin() - rec_reflection.p).length(), test))
                          lights_to_compute.push_back(lights[i]);
                  }
                  rec_reflection.mat_ptr->scatter(rec_reflection, pixel, lights_to_compute, world);
              }
            }
            return true;
        }

    public:
        color albedo;
};

class glass : public material {
    public:
        glass(const color& a) : albedo(a) {}

        virtual bool scatter(
            const hit_record& rec, color& pixel, const std::vector<light>& lights, const hittable& world
        ) const override {
            for(int i=0; i<lights.size(); i++) {
              vec3 light_direction = unit_vector(lights[i].origin() - rec.p);
              float cosi = clamp(-1, 1, dot(light_direction, rec.normal));
              float etai = 1, etat = 1.5;
              vec3 n = rec.normal;
              if (cosi < 0) { cosi = -cosi; } else { std::swap(etai, etat); n= -rec.normal; }
              float eta = etai / etat;
              float k = 1 - eta * eta * (1 - cosi * cosi);
              if(k >= 0) {
                  ray rayRefraction = ray(rec.p, unit_vector(eta * light_direction + (eta * cosi - sqrtf(k)) * n));
                  hit_record rec_refraction;
                  if (world.hit(rayRefraction, 0.001, infinity, rec_refraction)) {
                      rec_refraction.mat_ptr->scatter(rec_refraction, pixel, lights, world);
                  }
              }
            }
            return true;
        }

    public:
        color albedo;
};

#endif
