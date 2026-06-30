#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty." << std::endl;
        return (1);
    }

    std::ifstream infile(filename.c_str());

    if (!infile)
    {
        std::cout << "Error: cannot open file." << std::endl;
        return (1);
    }

    std::string content;
    std::string line;

    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);

    std::ofstream outfile((filename + ".replace").c_str());

    if (!outfile)
    {
        std::cout << "Error: cannot create output file." << std::endl;
        return (1);
    }

    outfile << result;
    outfile.close();

    return (0);
}