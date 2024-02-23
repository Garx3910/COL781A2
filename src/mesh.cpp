#include "mesh.hpp"

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
  int addVertex(const glm::vec3 &pos, const glm::vec3 &normal)
  {
    Vertex vertex;
    vertex.position = pos;
    vertex.normal = normal;
    vertices.push_back(vertex);
    return vertices.size() - 1; // Return index of the added vertex
  }

  // Add a triangle to the mesh
  void addTriangle(int vertexIndex1, int vertexIndex2, int vertexIndex3)
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
  std::vector<Vertex> getNeighboringVertices(int vertexIndex)
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
  std::vector<Triangle> getNeighboringTriangles(int vertexIndex)
  {
    std::vector<Triangle> neighboringTriangles;
    for (int triangleIndex : vertices[vertexIndex].adjacentTriangles)
    {
      neighboringTriangles.push_back(triangles[triangleIndex]);
    }
    return neighboringTriangles;
  }

  // Render the mesh using a rasterization API (dummy implementation)
  void render()
  {
    // Dummy implementation for rendering
    std::cout << "Rendering mesh...\n";
    // Iterate through triangles and render each triangle
    for (const Triangle &triangle : triangles)
    {
      // Render triangle using rasterization API
      std::cout << "Rendering triangle with vertices: "
                << triangle.vertices[0] << ", "
                << triangle.vertices[1] << ", "
                << triangle.vertices[2] << "\n";
    }
  }
};

int main()
{
  // Create a mesh
  Mesh mesh;

  // Add vertices
  int v0 = mesh.addVertex(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  int v1 = mesh.addVertex(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  int v2 = mesh.addVertex(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

  // Add triangles
  mesh.addTriangle(v0, v1, v2);

  // Render the mesh
  mesh.render();

  return 0;
}
