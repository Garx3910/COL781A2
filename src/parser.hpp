#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include <glm/glm.hpp>
#include <algorithm>
#include "mesh.hpp"

class Parser
{
    public:
        void parseOBJ(const std::string& filename, std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& normals, std::vector<glm::ivec3>& faces);
        std::map<int, std::vector<int>> createVertexFacesMap(const std::vector<glm::ivec3>& faces);
        glm::vec3 getVertexNormal(int vidx,const std::vector<glm::ivec3>& faces,const std::vector<int>& faceMap, const std::vector<glm::vec3>& vertices);
        void setNormals(const std::vector<glm::ivec3>& faces, const std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& normals);
        Mesh objToMesh(const std::string filename);
};

#endif //PARSER_HPP