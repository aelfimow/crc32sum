#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <map>
#include <functional>

#include "rdrand_func.h"
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

    auto bw = ap.bw().value_or(default_bit_width);

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

static void rand_fill(std::vector<size_t> &buffer)
{
    static std::map<size_t, std::function<void (size_t *p)>> const factory
    {
        { 4,    [](size_t *p) { rdrand_func4(p);    } },
        { 8,    [](size_t *p) { rdrand_func8(p);    } },
        { 16,   [](size_t *p) { rdrand_func16(p);   } },
        { 32,   [](size_t *p) { rdrand_func32(p);   } },
        { 64,   [](size_t *p) { rdrand_func64(p);   } },
        { 128,  [](size_t *p) { rdrand_func128(p);  } },
        { 256,  [](size_t *p) { rdrand_func256(p);  } },
        { 512,  [](size_t *p) { rdrand_func512(p);  } },
        { 1024, [](size_t *p) { rdrand_func1024(p); } },
    };

    auto it = factory.find(buffer.size());

    if (it == factory.end())
    {
        for (auto &value: buffer)
        {
            rdrand_func1(&value);
        }
    }
    else
    {
        auto &func = it->second;
        func(buffer.data());
    }
}
