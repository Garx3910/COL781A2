#include "mesh.hpp"
#include <cmath>
#include <sstream>
#include <iostream>

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
      float x = j * colStep - width / 2.0f;
      float y = i * rowStep - height / 2.0f;
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
    float theta = M_PI * static_cast<float>(i) / static_cast<float>(n);
    for (int j = 0; j <= m; ++j)
    {
      float phi = 2.0f * M_PI * static_cast<float>(j) / static_cast<float>(m);

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

  Mesh mesh = createSquareGrid(1.0f,1.0f,3,3);
  mesh.edgeCollapse(9,10);
  mesh.edgeFlip(1,4);
  mesh.edgeSplit(3,6);


  // Render or process the meshes as needed
  mesh.render();
  // squareGridMesh.render();
  return 0;
}
