#include "mesh.hpp"
#include "viewer.hpp"
#include <algorithm>

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

// Render the mesh using a rasterization API
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

// Smooth the mesh using the umbrella operator
void Mesh::smoothMesh(float lambda, int iterations)
{
  for (int it = 0; it < iterations; ++it)
  {
    std::vector<glm::vec3> newPositions(vertices.size());

    for (size_t i = 0; i < vertices.size(); ++i)
    {
      glm::vec3 averagePosition(0.0f);

      for (int j : vertices[i].adjacentTriangles)
      {
        for (int k : triangles[j].vertices)
        {
          if (k != i)
          {
            averagePosition += vertices[k].position;
          }
        }
      }

      averagePosition /= vertices[i].adjacentTriangles.size() * 2;
      glm::vec3 delta = averagePosition - vertices[i].position;
      newPositions[i] = vertices[i].position + lambda * delta;
    }

    for (size_t i = 0; i < vertices.size(); ++i)
    {
      vertices[i].position = newPositions[i];
    }
  }
}

// Perform Taubin smoothing on the mesh
void Mesh::taubinSmoothMesh(float lambda, float nu, int iterations)
{
  for (int it = 0; it < iterations; ++it)
  {
    smoothMesh(lambda, 1);
    smoothMesh(nu, 1);
  }
}

void Mesh::edgeFlip(int vertexIndex1, int vertexIndex2)
{
  int t1idx = -1, t2idx = -1;
  for (int i = 0; i < triangles.size(); i++)
  {
    if ((triangles[i].vertices[0] == vertexIndex1 && triangles[i].vertices[1] == vertexIndex2) || (triangles[i].vertices[0] == vertexIndex1 && triangles[i].vertices[2] == vertexIndex2) || (triangles[i].vertices[1] == vertexIndex1 && triangles[i].vertices[0] == vertexIndex2) || (triangles[i].vertices[1] == vertexIndex1 && triangles[i].vertices[2] == vertexIndex2) || (triangles[i].vertices[2] == vertexIndex1 && triangles[i].vertices[0] == vertexIndex2) || (triangles[i].vertices[2] == vertexIndex1 && triangles[i].vertices[1] == vertexIndex2))
    {
      // triangle contains the edge
      if (t1idx == -1)
        t1idx = i;
      else
      {
        t2idx = i;
        break;
      }
    }
  }
  // t1idx, t2idx are triangles sharing the edge
  if (t2idx == -1)
  {
    // edge is part of only one or no triangle
    std::cout << "edge not flippable" << std::endl;
    return;
  }
  int v3, v4;
  for (int i = 0; i < 3; i++)
  {
    if (triangles[t1idx].vertices[i] != vertexIndex1 && triangles[t1idx].vertices[i] != vertexIndex2)
      v3 = triangles[t1idx].vertices[i];
    if (triangles[t2idx].vertices[i] != vertexIndex1 && triangles[t2idx].vertices[i] != vertexIndex2)
      v4 = triangles[t2idx].vertices[i];
    ;
  }
  bool clockwise = false;
  for (int i = 0; i < 2; i++)
  {
    if (triangles[t1idx].vertices[i] == vertexIndex1 && triangles[t1idx].vertices[(i + 1) % 3] == vertexIndex2)
    {
      clockwise = true;
      break;
    }
  }
  if (clockwise)
  {
    triangles[t1idx].vertices[0] = v3;
    triangles[t1idx].vertices[1] = vertexIndex1;
    triangles[t1idx].vertices[2] = v4;
    triangles[t2idx].vertices[0] = v3;
    triangles[t2idx].vertices[1] = v4;
    triangles[t2idx].vertices[2] = vertexIndex2;
  }
  else
  {
    triangles[t1idx].vertices[0] = v3;
    triangles[t1idx].vertices[1] = v4;
    triangles[t1idx].vertices[2] = vertexIndex1;
    triangles[t2idx].vertices[0] = v3;
    triangles[t2idx].vertices[1] = vertexIndex2;
    triangles[t2idx].vertices[2] = v4;
  }
  // update adjacent triangles of v1,v2,v3,v4
  std::vector<int> &temp = vertices[vertexIndex1].adjacentTriangles;
  for (auto it = temp.begin(); it != temp.end();)
  {
    if (*it == t1idx)
    {
      it = temp.erase(it);
      break;
    }
    else
    {
      ++it;
    }
  }
  std::vector<int> &temp2 = vertices[vertexIndex2].adjacentTriangles;
  for (auto it = temp2.begin(); it != temp2.end();)
  {
    if (*it == t2idx)
    {
      it = temp2.erase(it);
      break;
    }
    else
    {
      ++it;
    }
  }
  vertices[v3].adjacentTriangles.push_back(t2idx);
  vertices[v4].adjacentTriangles.push_back(t1idx);
}

void Mesh::edgeSplit(int v1, int v2)
{
  int t1idx = -1, t2idx = -1;
  for (int i = 0; i < triangles.size(); i++)
  {
    if ((triangles[i].vertices[0] == v1 && triangles[i].vertices[1] == v2) || (triangles[i].vertices[0] == v1 && triangles[i].vertices[2] == v2) || (triangles[i].vertices[1] == v1 && triangles[i].vertices[0] == v2) || (triangles[i].vertices[1] == v1 && triangles[i].vertices[2] == v2) || (triangles[i].vertices[2] == v1 && triangles[i].vertices[0] == v2) || (triangles[i].vertices[2] == v1 && triangles[i].vertices[1] == v2))
    {
      // triangle containts the edge
      if (t1idx == -1)
        t1idx = i;
      else
      {
        t2idx = i;
        break;
      }
    }
  }
  if (t1idx == -1)
  {
    std::cout << v1 << ", " << v2 << " do not form an edge in the mesh" << std::endl;
    return;
  }
  if (t2idx == -1)
  {
    // edge contained in only one triangle
    int v3;
    for (int i = 0; i < 3; i++)
    {
      if (triangles[t1idx].vertices[i] != v1 && triangles[t1idx].vertices[i] != v2)
        v3 = triangles[t1idx].vertices[i];
    }
    bool clockwise = false;
    for (int i = 0; i < 2; i++)
    {
      if (triangles[t1idx].vertices[i] == v1 && triangles[t1idx].vertices[(i + 1) % 3] == v2)
      {
        clockwise = true;
        break;
      }
    }
    int v4 = vertices.size();
    int newt = triangles.size();
    Triangle newtdata;
    triangles.push_back(newtdata);
    if (clockwise)
    {
      triangles[t1idx].vertices[0] = v3;
      triangles[t1idx].vertices[1] = v1;
      triangles[t1idx].vertices[2] = v4;

      triangles[newt].vertices[0] = v3;
      triangles[newt].vertices[1] = v4;
      triangles[newt].vertices[2] = v2;
    }
    else
    {
      triangles[t1idx].vertices[0] = v3;
      triangles[t1idx].vertices[1] = v4;
      triangles[t1idx].vertices[2] = v1;

      triangles[newt].vertices[0] = v3;
      triangles[newt].vertices[1] = v2;
      triangles[newt].vertices[2] = v1;
    }

    vertices[v3].adjacentTriangles.push_back(newt);
    std::vector<int> &temp = vertices[v2].adjacentTriangles;
    for (auto it = temp.begin(); it != temp.end();)
    {
      if (*it == t1idx)
      {
        it = temp.erase(it);
        break;
      }
      else
      {
        ++it;
      }
    }
    vertices[v2].adjacentTriangles.push_back(newt);
    Vertex v4data;
    vertices.push_back(v4data);
    vertices[v4].position = (vertices[v1].position + vertices[v2].position) / 2.0f;
    vertices[v4].adjacentTriangles = {newt, t1idx};
    vertices[v4].normal = glm::vec3(0.0f);
    glm::vec3 v1p, v2p, v3p, v4p;
    v1p = vertices[v1].position;
    v2p = vertices[v2].position;
    v3p = vertices[v3].position;
    v4p = vertices[v4].position;

    if (clockwise)
    {
      vertices[v4].normal += glm::cross((v3p - v4p), (v1p - v4p)) / (glm::length(v1p - v4p) * glm::length(v1p - v4p) * glm::length(v3p - v4p) * glm::length(v3p - v4p));
      vertices[v4].normal += glm::cross((v2p - v4p), (v3p - v4p)) / (glm::length(v3p - v4p) * glm::length(v3p - v4p) * glm::length(v2p - v4p) * glm::length(v2p - v4p));
    }
    else
    {
      vertices[v4].normal += glm::cross((v1p - v4p), (v3p - v4p)) / (glm::length(v1p - v4p) * glm::length(v1p - v4p) * glm::length(v3p - v4p) * glm::length(v3p - v4p));
      vertices[v4].normal += glm::cross((v3p - v4p), (v2p - v4p)) / (glm::length(v3p - v4p) * glm::length(v3p - v4p) * glm::length(v2p - v4p) * glm::length(v2p - v4p));
    }
  }
  else
  {
    // edge contained in two triangles
    int v3, v4;
    for (int i = 0; i < 3; i++)
    {
      if (triangles[t1idx].vertices[i] != v1 && triangles[t1idx].vertices[i] != v2)
        v3 = triangles[t1idx].vertices[i];
      if (triangles[t2idx].vertices[i] != v1 && triangles[t2idx].vertices[i] != v2)
        v4 = triangles[t2idx].vertices[i];
    }

    bool clockwise = false;
    for (int i = 0; i < 2; i++)
    {
      if (triangles[t1idx].vertices[i] == v1 && triangles[t1idx].vertices[(i + 1) % 3] == v2)
      {
        clockwise = true;
        break;
      }
    }
    int v5 = vertices.size();
    int newt1 = triangles.size();
    int newt2 = newt1 + 1;
    Triangle newt1data, newt2data;
    triangles.push_back(newt1data);
    triangles.push_back(newt2data);

    if (clockwise)
    {
      triangles[t1idx].vertices[0] = v3;
      triangles[t1idx].vertices[1] = v1;
      triangles[t1idx].vertices[2] = v5;

      triangles[t2idx].vertices[0] = v4;
      triangles[t2idx].vertices[1] = v2;
      triangles[t2idx].vertices[2] = v5;

      triangles[newt1].vertices[0] = v3;
      triangles[newt1].vertices[1] = v5;
      triangles[newt1].vertices[2] = v2;

      triangles[newt2].vertices[0] = v1;
      triangles[newt2].vertices[1] = v4;
      triangles[newt2].vertices[2] = v5;
    }
    else
    {
      triangles[t1idx].vertices[0] = v1;
      triangles[t1idx].vertices[1] = v3;
      triangles[t1idx].vertices[2] = v5;

      triangles[t2idx].vertices[0] = v2;
      triangles[t2idx].vertices[1] = v4;
      triangles[t2idx].vertices[2] = v5;

      triangles[newt1].vertices[0] = v3;
      triangles[newt1].vertices[1] = v2;
      triangles[newt1].vertices[2] = v5;

      triangles[newt2].vertices[0] = v5;
      triangles[newt2].vertices[1] = v4;
      triangles[newt2].vertices[2] = v1;
    }

    vertices[v3].adjacentTriangles.push_back(newt1);
    vertices[v4].adjacentTriangles.push_back(newt2);
    std::vector<int> &temp = vertices[v2].adjacentTriangles;
    for (auto it = temp.begin(); it != temp.end();)
    {
      if (*it == t1idx)
      {
        it = temp.erase(it);
        break;
      }
      else
      {
        ++it;
      }
    }
    std::vector<int> &temp2 = vertices[v1].adjacentTriangles;
    for (auto it = temp2.begin(); it != temp2.end();)
    {
      if (*it == t2idx)
      {
        it = temp2.erase(it);
        break;
      }
      else
      {
        ++it;
      }
    }
    vertices[v2].adjacentTriangles.push_back(newt1);
    vertices[v1].adjacentTriangles.push_back(newt2);
    Vertex v5data;
    vertices.push_back(v5data);
    vertices[v5].position = (vertices[v1].position + vertices[v2].position) / 2.0f;
    vertices[v5].adjacentTriangles = {newt1, t1idx, newt2, t2idx};
    vertices[v5].normal = glm::vec3(0.0f);
    glm::vec3 v1p, v2p, v3p, v4p, v5p;
    v1p = vertices[v1].position;
    v2p = vertices[v2].position;
    v3p = vertices[v3].position;
    v4p = vertices[v4].position;
    v5p = vertices[v5].position;

    if (clockwise)
    {
      vertices[v5].normal += glm::cross((v3p - v5p), (v1p - v5p)) / (glm::length(v1p - v5p) * glm::length(v1p - v5p) * glm::length(v3p - v5p) * glm::length(v3p - v5p));
      vertices[v5].normal += glm::cross((v2p - v5p), (v3p - v5p)) / (glm::length(v3p - v5p) * glm::length(v3p - v5p) * glm::length(v2p - v5p) * glm::length(v2p - v5p));
      vertices[v5].normal += glm::cross((v1p - v5p), (v4p - v5p)) / (glm::length(v1p - v5p) * glm::length(v1p - v5p) * glm::length(v4p - v5p) * glm::length(v4p - v5p));
      vertices[v5].normal += glm::cross((v4p - v5p), (v2p - v5p)) / (glm::length(v4p - v5p) * glm::length(v4p - v5p) * glm::length(v2p - v5p) * glm::length(v2p - v5p));
    }
    else
    {
      vertices[v5].normal += glm::cross((v1p - v5p), (v3p - v5p)) / (glm::length(v1p - v5p) * glm::length(v1p - v5p) * glm::length(v3p - v5p) * glm::length(v3p - v5p));
      vertices[v5].normal += glm::cross((v3p - v5p), (v2p - v5p)) / (glm::length(v3p - v5p) * glm::length(v3p - v5p) * glm::length(v2p - v5p) * glm::length(v2p - v5p));
      vertices[v5].normal += glm::cross((v4p - v5p), (v1p - v5p)) / (glm::length(v1p - v5p) * glm::length(v1p - v5p) * glm::length(v4p - v5p) * glm::length(v4p - v5p));
      vertices[v5].normal += glm::cross((v2p - v5p), (v4p - v5p)) / (glm::length(v4p - v5p) * glm::length(v4p - v5p) * glm::length(v2p - v5p) * glm::length(v2p - v5p));
    }
  }
}

bool Mesh::edgeExists(int vertexIndex1, int vertexIndex2)
{
  // Check if the vertices are valid
  if (vertexIndex1 < 0 || vertexIndex1 >= vertices.size() || vertexIndex2 < 0 || vertexIndex2 >= vertices.size())
  {
    std::cerr << "Invalid vertex index" << std::endl;
    return false;
  }

  // Iterate over the adjacent triangles of the first vertex
  for (int triangleIndex : vertices[vertexIndex1].adjacentTriangles)
  {
    // Check if the second vertex is part of the triangle
    for (int i = 0; i < 3; i++)
    {
      if (triangles[triangleIndex].vertices[i] == vertexIndex2)
      {
        // An edge exists between the two vertices
        return true;
      }
    }
  }

  // No edge exists between the two vertices
  return false;
}

void Mesh::edgeCollapse(int vertexIndex1, int vertexIndex2)
{
  // check if edge exists between the two vertices
  if (edgeExists(vertexIndex1, vertexIndex2) == false)
  {
    std::cerr << "Edge does not exist between the two vertices" << std::endl;
    return;
  }
  glm::vec3 updatedpos=(vertices[vertexIndex1].position+vertices[vertexIndex2].position)/2.0f;
  vertices[vertexIndex1].position=(vertices[vertexIndex1].position+vertices[vertexIndex2].position)/2.0f;
  vertices[vertexIndex1].normal=(vertices[vertexIndex1].normal+vertices[vertexIndex2].normal)/2.0f;
  // Remove the second vertex
  vertices.erase(vertices.begin() + vertexIndex2);

  // Update the triangles
  for (Triangle &triangle : triangles)
  {
    for (int i = 0; i < 3; i++)
    {
      if (triangle.vertices[i] == vertexIndex2)
      {
        // Replace the removed vertex with the remaining vertex
        triangle.vertices[i] = vertexIndex1;
      }
      else if (triangle.vertices[i] > vertexIndex2)
      {
        // Decrement the indices of the vertices that come after the removed vertex
        triangle.vertices[i]--;
      }
    }
  }

  // Update the adjacent triangles of the remaining vertex
  vertices[vertexIndex1].adjacentTriangles.clear();
  for (int i = 0; i < triangles.size(); i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (triangles[i].vertices[j] == vertexIndex1)
      {
        vertices[vertexIndex1].adjacentTriangles.push_back(i);
        break;
      }
    }
  }
}

bool Mesh::isValid()
{
  // check if triangle indices are valid
  int n = vertices.size();
  for (auto triangle : triangles)
  {
    for (int i = 0; i < 3; i++)
    {
      if (triangle.vertices[i] < 0 || triangle.vertices[i] >= n)
      {
        std::cout << "Triangle index out of bound" << std::endl;
        return false;
      }
    }
  }
  // check if adjacent triangle indices are valid
  n = triangles.size();
  for (auto v : vertices)
  {
    for (int i : v.adjacentTriangles)
    {
      if (i < 0 || i >= n)
      {
        std::cout << "Adjacent triangle index out of bound" << std::endl;
        return false;
      }
    }
  }

  // check if triangles are valid
  for (auto triangle : triangles)
  {
    glm::vec3 v1 = vertices[triangle.vertices[0]].position, v2 = vertices[triangle.vertices[1]].position, v3 = vertices[triangle.vertices[2]].position;
    glm::vec3 angle = glm::cross(v2 - v1, v3 - v1);
    if (glm::all(glm::equal(angle, glm::vec3(0.0f))))
    {
      std::cout << "Triangle formed by vertices " << triangle.vertices[0] << ", " << triangle.vertices[1] << ", " << triangle.vertices[1] << " is not valid(collinear vertices)" << std::endl;
      return false;
    }
  }


  // check for no duplicate triangles
  for (int i = 0; i < triangles.size(); i++)
  {
    for (int j = i + 1; j < triangles.size(); j++)
    {
      if (triangles[i].vertices[0] == triangles[j].vertices[0] && triangles[i].vertices[1] == triangles[j].vertices[1] && triangles[i].vertices[2] == triangles[j].vertices[2])
      {
        return false;
      }
      if (triangles[i].vertices[0] == triangles[j].vertices[0] && triangles[i].vertices[1] == triangles[j].vertices[2] && triangles[i].vertices[2] == triangles[j].vertices[1])
      {
        return false;
      }
      if (triangles[i].vertices[0] == triangles[j].vertices[1] && triangles[i].vertices[1] == triangles[j].vertices[2] && triangles[i].vertices[2] == triangles[j].vertices[0])
      {
        return false;
      }
      if (triangles[i].vertices[0] == triangles[j].vertices[1] && triangles[i].vertices[1] == triangles[j].vertices[0] && triangles[i].vertices[2] == triangles[j].vertices[2])
      {
        return false;
      }
      if (triangles[i].vertices[0] == triangles[j].vertices[2] && triangles[i].vertices[1] == triangles[j].vertices[0] && triangles[i].vertices[2] == triangles[j].vertices[1])
      {
        return false;
      }
      if (triangles[i].vertices[0] == triangles[j].vertices[2] && triangles[i].vertices[1] == triangles[j].vertices[1] && triangles[i].vertices[2] == triangles[j].vertices[0])
      {
        return false;
      }
    }
  }

  // check for orientational consistency
  for (int i = 0; i < vertices.size(); i++)
  {
    for (int j : vertices[i].adjacentTriangles)
    {
      glm::vec3 v1 = vertices[triangles[j].vertices[0]].position, v2 = vertices[triangles[j].vertices[1]].position, v3 = vertices[triangles[j].vertices[2]].position;
      glm::vec3 angle = glm::cross(v2 - v1, v3 - v1);
      if (glm::dot(angle, vertices[i].normal) < 0)
      {
        return false;
      }
    }
  }
  return true;
}