#include <iostream>
#include <fstream>

int main(int ac, char **av){

    if (ac != 4){
        std::cout << "Usage : ./replace <filename> <s1> <s2>\n";
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream file (filename.c_str());
    if (!file.is_open()){
        std::cout << "Cannot open the file\n";
        return (1);
    }
    if (s1.empty()){
        std::cout << "s1 cannot be empty\n";
        return (1);
    }
    std::string content;
    std::getline (file, content, '\0');
    std::ofstream out((filename + ".replace").c_str());
    int i = 0;
    while (content[i]){
        size_t pos = content.find(s1, i);
        if (pos == std::string::npos){
            out << content.substr(i);
            break;
        }
        out << content.substr(i, pos - i);
        out << s2;
        i = pos + s1.length();
    }
    return (0);
}