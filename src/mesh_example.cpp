#include "mesh.hpp"
#include <cmath>

Mesh createSquareGrid(float width, float height, int m, int n)
{
  Mesh mesh;

  // Calculate the step sizes for rows and columns
  float rowStep = height / m;
  float colStep = width / n;

  // Generate vertices
  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      // Calculate vertex position
      float x = j * colStep;
      float y = i * rowStep;
      mesh.addVertex(glm::vec3(x, y, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    }
  }

  // Generate triangles
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      // Indices of the four vertices of the current grid cell
      int v0 = i * (n + 1) + j;
      int v1 = v0 + 1;
      int v2 = (i + 1) * (n + 1) + j;
      int v3 = v2 + 1;

      // First triangle
      mesh.addTriangle(v0, v1, v2);

      // Second triangle
      mesh.addTriangle(v1, v3, v2);
    }
  }

  return mesh;
}

Mesh createSphere(float radius, int m, int n)
{
  Mesh mesh;

  // Generate vertices
  for (int i = 0; i <= n; ++i)
  {
    float theta = glm::pi<float>() * static_cast<float>(i) / static_cast<float>(n);
    for (int j = 0; j <= m; ++j)
    {
      float phi = 2.0f * glm::pi<float>() * static_cast<float>(j) / static_cast<float>(m);

      // Calculate vertex position
      float x = radius * std::sin(theta) * std::cos(phi);
      float y = radius * std::sin(theta) * std::sin(phi);
      float z = radius * std::cos(theta);

      mesh.addVertex(glm::vec3(x, y, z), glm::normalize(glm::vec3(x, y, z)));
    }
  }

  // Generate triangles
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      // Indices of the four vertices of the current rectangle
      int v0 = i * (m + 1) + j;
      int v1 = v0 + 1;
      int v2 = (i + 1) * (m + 1) + j;
      int v3 = v2 + 1;

      // First triangle
      mesh.addTriangle(v0, v1, v2);

      // Second triangle
      mesh.addTriangle(v1, v3, v2);
    }
  }

  return mesh;
}

int main()
{
  // Create a unit square grid divided into 3 rows and 4 columns
  Mesh squareGridMesh = createSquareGrid(1.0f, 1.0f, 3, 4);

  // Create a unit sphere with 4 slices and 2 stacks
  Mesh sphereMesh = createSphere(1.0f, 4, 2);

  // Render or process the meshes as needed
  // ...

  return 0;
}
