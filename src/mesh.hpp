#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>
#include <glm/glm.hpp>

// Define a structure for vertex
struct Vertex
{
  glm::vec3 position;
  glm::vec3 normal;
  std::vector<int> adjacentTriangles;
};

// Define a structure for triangle
struct Triangle
{
  int vertices[3];
};

// Define a mesh class
class Mesh
{
private:
  std::vector<Vertex> vertices;
  std::vector<Triangle> triangles;

public:
  // Add a vertex to the mesh
  int addVertex(const glm::vec3 &pos, const glm::vec3 &normal);

  // Add a triangle to the mesh
  void addTriangle(int vertexIndex1, int vertexIndex2, int vertexIndex3);

  // Get neighboring vertices of a vertex
  std::vector<Vertex> getNeighboringVertices(int vertexIndex);

  // Get neighboring triangles of a vertex
  std::vector<Triangle> getNeighboringTriangles(int vertexIndex);

  // Render the mesh using a rasterization API (dummy implementation)
  void render();
};

#endif // MESH_HPP
