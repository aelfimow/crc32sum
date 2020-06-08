#include <sstream>
#include <stdexcept>

#include "argv_parser.h"


argv_parser::argv_parser(int argc, char *argv[]) :
    m_argv { }
{
    for (auto i = 0; i < argc; ++i)
    {
        m_argv.push_back(argv[i]);
    }
}

std::optional<std::string> argv_parser::if_name() const
try
{
    auto str = parse("if=");

    if (0 == str.length())
    {
        return std::nullopt;
    }

    return str;
}
catch (...)
{
    return std::nullopt;
}

std::optional<size_t> argv_parser::bw() const
try
{
    std::string bs_str = parse("bw=");

    size_t value { 0 };
    std::stringstream ss { bs_str };
    ss >> value;

    if (value == 0)
    {
        return std::nullopt;
    }

    return value;
}
catch (...)
{
    return std::nullopt;
}

std::string argv_parser::parse(std::string const &keyword) const
{
    std::string parsed_str;

    for (auto const &str: m_argv)
    {
        auto pos = str.find(keyword);

        bool const found = (pos == 0);

        if (found)
        {
            pos += keyword.length();
            parsed_str = str.substr(pos);
            break;
        }
    }

    return parsed_str;
}
