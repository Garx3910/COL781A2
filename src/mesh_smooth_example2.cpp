#include "parser.hpp"

int main(int argc, char* argv[]) {

    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <filename> lambda nu iterations" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    float lambda = std::stof(argv[2]);
    float nu = std::stof(argv[3]);
    int iterations;
    std::istringstream(argv[4]) >> iterations;

    Parser p;

    Mesh mesh=p.objToMesh(filename);  
    mesh.taubinSmoothMesh(lambda, nu, iterations);  

    mesh.render();

    return 0;
}