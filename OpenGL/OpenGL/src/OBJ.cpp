#include "OBJ.h"

OBJ::OBJ(std::string name, std::string filename)
{
    std::ifstream indata;
    std::string s;
    indata.open(filename);
    if (!indata) { // file couldn't be opened
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    if (indata.is_open())
    {
        while (std::getline(indata, s))
        {
            switch (*s.c_str())
            {
            case 'v':
                vertex v;
                indata >> v.x >> v.y >> v.z;
                std::cout << v.x << "\n";
                break;
            }
        }
        indata.close();
    }

}

