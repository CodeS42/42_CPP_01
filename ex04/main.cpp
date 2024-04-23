#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

void update_line(std::string &line, std::string s1, size_t position)
{
    int len_s1 = s1.length();
    int len_new_line = line.length() - (position + len_s1);

    line = line.substr(position + len_s1, len_new_line);
}

std::string replace_word(std::string line, std::string s2, size_t position)
{
    if (position > 0)
        return (line.substr(0, position) + s2);
    return (s2);
}

void    read_file(std::string s1, std::string s2, std::ifstream &file1, std::ofstream &file2)
{
    std::string line;
    size_t position;

    while (std::getline(file1, line))
    {
        if (s1.empty())
        {
            file2.write(line.c_str(), line.size());
            file2.write("\n", 1);
        }
        else
        {
            std::string new_line;
            position = line.find(s1);
            if (position != std::string::npos)
            {
                while(position != std::string::npos && !line.empty())
                {
                    new_line += replace_word(line, s2, position);
                    update_line(line, s1, position);
                    if (!line.empty())
                        position = line.find(s1);
                }
                if (position == std::string::npos)
                    new_line += line;
            }
            else
                new_line = line;
            file2.write(new_line.c_str(), new_line.size());
            file2.write("\n", 1);
        }
    }
}

bool open_files(std::ifstream &file1, std::ofstream &file2, char *av1)
{
    std::string file2_name = av1;

    file2_name.append(".replace");

    file1.open(av1, std::ios::in);
    if (!file1.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        return (false);
    }
    file2.open(file2_name.c_str(), std::ios::out);
    if (!file2.is_open())
    {
        file1.close();
        std::cerr << "Failed to open file." << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char *argv[])
{
    std::ifstream file1;
    std::ofstream file2;

    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments." << std::endl;
        return(1);
    }

    if (!open_files(file1, file2, argv[1]))
        return (1);
    read_file(argv[2], argv[3], file1, file2);
    file1.close();
    file2.close();

    return (0);
}
