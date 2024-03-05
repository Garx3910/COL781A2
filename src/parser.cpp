#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include <glm/glm.hpp>
#include <algorithm>
#include "mesh.hpp"

void parseOBJ(const std::string& filename, std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& normals, std::vector<glm::ivec3>& faces) {
    std::ifstream file(filename);
    if(!file.good())
    {
        std::cout<<"Cannor Open File "<<filename<<". Please check filename"<<std::endl;
    }
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        if (!(iss >> token)) continue;

        if (token == "v") {
            float x, y, z;
            if (iss >> x >> y >> z) {
                vertices.push_back(glm::vec3(x, y, z));
            }
        } 
        else if (token == "vn") {
            float x, y, z;
            if (iss >> x >> y >> z) {
                normals.push_back(glm::vec3(x, y, z));
            }
        } 
        else if (token == "f") {
            glm::ivec3 face;
            for (int i = 0; i < 3; ++i) {
                std::string vertexData;
                if (!(iss >> vertexData)) break;

                std::istringstream viss(vertexData);
                std::string vIndexStr, nIndexStr;
                std::getline(viss, vIndexStr, '/');
                face[i] = std::stoi(vIndexStr) - 1;
            }
            faces.push_back(face);
        }
    }
    int diff=vertices.size()-normals.size();
    for (int i =0;i<diff;i++)
    { 
        normals.push_back(glm::vec3(0.0));
    }
}


// Function to create a map of vertices to the indices of faces containing each vertex
std::map<int, std::vector<int>> createVertexFacesMap(const std::vector<glm::ivec3>& faces) {
    std::map<int, std::vector<int>> vertexFacesMap;

    // Iterate through each face
    for (int i = 0; i < faces.size(); ++i) {
        const glm::ivec3& face = faces[i];

        // Iterate through each vertex of the face
        for (int j = 0; j < 3; ++j) {
            int vertexIndex = face[j];

            // Check if the vertex index is already in the map
            auto it = vertexFacesMap.find(vertexIndex);

            // If not found, add a new entry for the vertex
            if (it == vertexFacesMap.end()) {
                vertexFacesMap[vertexIndex] = std::vector<int>{i};
            } else {
                // If found, append the face index to the existing list
                it->second.push_back(i);
            }
        }
    }

    return vertexFacesMap;
}

glm::vec3 getVertexNormal(int vidx,const std::vector<glm::ivec3>& faces,const std::vector<int>& faceMap, const std::vector<glm::vec3>& vertices)
{
    glm::vec3 normal=glm::vec3(0);
    for (int faceidx : faceMap)
    {
        glm::ivec3 face = faces[faceidx];
        int v1idx,v2idx;
        for (int i=0;i<3;i++)
        {
            if(face[i]==vidx)
            {
                v1idx=face[(i+1)%3];
                v2idx=face[(i+2)%3];
                break;
            }
        }
        glm::vec3 v=vertices[vidx],v1=vertices[v1idx],v2=vertices[v2idx];
        normal+=glm::cross((v1-v),(v2-v))/(glm::length(v1-v)*glm::length(v1-v)*glm::length(v2-v)*glm::length(v2-v));
        
    }
    return normal;
}

void setNormals(const std::vector<glm::ivec3>& faces, const std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& normals)
{
    // Create a map of vertices to the indices of faces containing each vertex
    std::map<int, std::vector<int>> vertexFacesMap = createVertexFacesMap(faces);

    for (int i=0;i<vertices.size();i++)
    {
        if(glm::all(glm::equal(normals[i], glm::vec3(0.0f))))
        normals[i]=getVertexNormal(i,faces,vertexFacesMap[i],vertices);
    }
}

Mesh objToMesh(const std::string filename)
{
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::ivec3> faces;

    parseOBJ(filename, vertices, normals, faces);

    setNormals(faces,vertices,normals);

    Mesh mesh;

    for (int i =0;i<vertices.size();i++)
    {
        mesh.addVertex(vertices[i],normals[i]);
    }
    for (auto face:faces)
    {
        mesh.addTriangle(face.x,face.y,face.z);
    }
    return mesh;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    Mesh mesh=objToMesh(filename);    

    mesh.render();

    return 0;
}


