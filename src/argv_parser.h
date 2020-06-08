#ifdef ARGV_PARSER_H
#error Already included
#else
#define ARGV_PARSER_H

#include <vector>
#include <string>
#include <optional>

class argv_parser
{
    public:
        explicit argv_parser(int argc, char *argv[]);
        ~argv_parser() = default;

        std::optional<std::string> if_name() const;
        std::optional<size_t> bw() const;

    private:
        std::vector<std::string> m_argv;

        std::string parse(std::string const &keyword) const;
};

#endif
