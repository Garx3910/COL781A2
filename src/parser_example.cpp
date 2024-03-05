#include "parser.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    Parser p;

    Mesh mesh=p.objToMesh(filename);    

    mesh.render();

    return 0;
}