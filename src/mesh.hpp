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

  // Smooth the mesh using the umbrella operator
  void smoothMesh(float lambda, int iterations);

  // Perform Taubin smoothing on the mesh
  void taubinSmoothMesh(float lambda, float nu, int iterations);

  //perform edge flip operation on the mesh
  void edgeFlip(int vertexIndex1, int vertexIndex2);

  //perform edge flip operation on the mesh
  void edgeSplit(int vertexIndex1, int vertexIndex2);
  
  //perform edge flip operation on the mesh
  void edgeCollapse(int vertexIndex1, int vertexIndex2);

  //checks if mesh connectivity is valid or not
  bool isValid();
};

#endif // MESH_HPP