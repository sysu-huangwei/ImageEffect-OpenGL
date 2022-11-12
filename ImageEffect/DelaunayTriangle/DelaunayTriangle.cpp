//
//  DelaunayTriangle.cpp
//
//  Created by rayyyhuang on 2021/4/20.
//

#include "DelaunayTriangle.hpp"
#include <vector>
#include "delaunay.h"
using namespace std;
using namespace dt;

float *DelaunayTriangle::getTriangles(float *points, int pointsCount, int& trianglesCountOutput) {
    if (!points) {
        return nullptr;
    }
    
    Delaunay<float> instance;
    vector<Vector2<float>> vertices;
    
    for (int i = 0; i < pointsCount; i++) {
        vertices.push_back(Vector2<float>(points[2 * i], points[2 * i + 1]));
    }
    
    std::vector<Triangle<float>> triangles = instance.triangulate(vertices);
    
    trianglesCountOutput = (int)triangles.size();
    
    float *result = new float[triangles.size() * 6];
    for (int i = 0; i < triangles.size(); i++) {
        result[6 * i] = triangles[i].a->x;
        result[6 * i + 1] = triangles[i].a->y;
        result[6 * i + 2] = triangles[i].b->x;
        result[6 * i + 3] = triangles[i].b->y;
        result[6 * i + 4] = triangles[i].c->x;
        result[6 * i + 5] = triangles[i].c->y;
    }
    
    return result;
}

std::vector<BaseTriangle> DelaunayTriangle::getTriangles(std::vector<BasePoint> points) {
    std::vector<BaseTriangle> result;
    
    Delaunay<float> instance;
    vector<Vector2<float>> vertices;
    for (int i = 0; i < points.size(); i++) {
        vertices.push_back(Vector2<float>(points[i].x, points[i].y));
    }
    
    std::vector<Triangle<float>> triangles = instance.triangulate(vertices);
    
    for (int i = 0; i < triangles.size(); i++) {
        BaseTriangle triangle;
        triangle.p0.x = triangles[i].a->x;
        triangle.p0.y = triangles[i].a->y;
        triangle.p1.x = triangles[i].b->x;
        triangle.p1.y = triangles[i].b->y;
        triangle.p2.x = triangles[i].c->x;
        triangle.p2.y = triangles[i].c->y;
        result.push_back(triangle);
    }
    
    return result;
}
