#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <map>
#include <functional>

#include "crc32_func.h"
#include "argv_parser.h"

static size_t const default_bit_width = 8;

int main(int argc, char *argv[])
try
{
    argv_parser ap { argc, argv };

    std::string const missing_file_name { "No input file name" };

    auto if_name = ap.if_name().value_or(missing_file_name);
    if (if_name == missing_file_name)
    {
        throw std::runtime_error("Input file name not specified");
    }

    std::ifstream infile { if_name, std::ifstream::binary };

    if (!infile.good())
    {
        throw std::runtime_error(if_name + " is not good");
    }

    auto bw = ap.bw().value_or(default_bit_width);

    size_t const buffer_size = (1024 * bw) / 8;

    std::vector<char> buffer(buffer_size);

    size_t total_bytes = 0;
    uint32_t crc = 0;

    while (true)
    {
        infile.read(buffer.data(), buffer.size());

        auto const gcount = infile.gcount();

        if (gcount <= 0)
        {
            break;
        }

        size_t const bytes_read = static_cast<size_t>(gcount);

        crc = crc32_8(crc, buffer.data(), bytes_read);

        total_bytes += bytes_read;
    }

    std::cout << "CRC32 " << if_name << ", " << total_bytes << " bytes: " << std::hex << crc << std::endl;

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
