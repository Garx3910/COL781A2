#include "parser.hpp"

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> lambda iterations" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    float lambda = std::stof(argv[2]);
    int iterations;
    std::istringstream(argv[3]) >> iterations;

    Parser p;

    Mesh mesh=p.objToMesh(filename);  
    mesh.smoothMesh(lambda, iterations);  

    mesh.render();

    return 0;
}