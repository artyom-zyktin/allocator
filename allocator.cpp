#include "allocator.hpp"

az::Allocator::Allocator(size_t size)
    : _begin(new _byte[size]), _end(_begin + size), _head(_begin)
{}

az::Allocator::~Allocator()
{
    delete [] _begin;
}

az::Allocator::EmplacingException::EmplacingException()
    : std::exception()
{}
