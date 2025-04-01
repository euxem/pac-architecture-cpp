#ifndef __NOSUCHUSEREXCEPTION_HPP__
#define __NOSUCHUSEREXCEPTION_HPP__

#include <stdexcept>
#include <string>

class NoSuchUserException : public std::runtime_error {
public:
    NoSuchUserException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif