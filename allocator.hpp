#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>
#include <utility>
#include <exception>

namespace az {

    class Allocator
    {

    public:

        class EmplacingException : public std::exception
        {
        public:
            EmplacingException();
        };

        explicit Allocator(size_t size);
        ~Allocator();

        template<class T, class... Args>
        T* emplace(Args&&... args)
        {
            size_t _Tsize = sizeof(T);

            if (_size() < _Tsize) throw EmplacingException();

            T* res = new (_head) T (std::forward<Args>(args)...);
            _head += _Tsize;

            return res;
        }


    protected:
        using _byte = unsigned char;
        using _ptr  = _byte*;

        _ptr _begin;
        _ptr _end;
        _ptr _head;

        inline size_t _size() { return _end - _head; }

    };

}

#endif // ALLOCATOR_HPP
