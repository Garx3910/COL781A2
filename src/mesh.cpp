#include "mesh.hpp"
#include "viewer.hpp"

// Add a vertex to the mesh
int Mesh::addVertex(const glm::vec3 &pos, const glm::vec3 &normal)
{
  Vertex vertex;
  vertex.position = pos;
  vertex.normal = normal;
  vertices.push_back(vertex);
  return vertices.size() - 1; // Return index of the added vertex
}

// Add a triangle to the mesh
void Mesh::addTriangle(int vertexIndex1, int vertexIndex2, int vertexIndex3)
{
  Triangle triangle;
  triangle.vertices[0] = vertexIndex1;
  triangle.vertices[1] = vertexIndex2;
  triangle.vertices[2] = vertexIndex3;
  triangles.push_back(triangle);
  // Update adjacent triangles for each vertex
  vertices[vertexIndex1].adjacentTriangles.push_back(triangles.size() - 1);
  vertices[vertexIndex2].adjacentTriangles.push_back(triangles.size() - 1);
  vertices[vertexIndex3].adjacentTriangles.push_back(triangles.size() - 1);
}

// Get neighboring vertices of a vertex
std::vector<Vertex> Mesh::getNeighboringVertices(int vertexIndex)
{
  std::vector<Vertex> neighboringVertices;
  for (int triangleIndex : vertices[vertexIndex].adjacentTriangles)
  {
    for (int i = 0; i < 3; ++i)
    {
      int neighborVertexIndex = triangles[triangleIndex].vertices[i];
      if (neighborVertexIndex != vertexIndex)
      {
        neighboringVertices.push_back(vertices[neighborVertexIndex]);
      }
    }
  }
  return neighboringVertices;
}

// Get neighboring triangles of a vertex
std::vector<Triangle> Mesh::getNeighboringTriangles(int vertexIndex)
{
  std::vector<Triangle> neighboringTriangles;
  for (int triangleIndex : vertices[vertexIndex].adjacentTriangles)
  {
    neighboringTriangles.push_back(triangles[triangleIndex]);
  }
  return neighboringTriangles;
}

// Render the mesh using a rasterization API (dummy implementation)
void Mesh::render()
{
  COL781::Viewer::Viewer v;
  if (!v.initialize("Mesh viewer", 640, 480))
  {
    return;
  }
  glm::vec3 *verticesArray = new glm::vec3[vertices.size()];
  glm::vec3 *normalsArray = new glm::vec3[vertices.size()];
  glm::ivec3 *trianglesArray = new glm::ivec3[triangles.size()];
  for (int i = 0; i < vertices.size(); ++i)
  {
    verticesArray[i] = vertices[i].position;
    normalsArray[i] = vertices[i].normal;
  }
  for (int i = 0; i < triangles.size(); ++i)
  {
    trianglesArray[i] = glm::ivec3(triangles[i].vertices[0], triangles[i].vertices[1], triangles[i].vertices[2]);
  }
  v.setVertices(vertices.size(), verticesArray);
  v.setNormals(vertices.size(), normalsArray);
  v.setTriangles(triangles.size(), trianglesArray);
  v.view();
}
