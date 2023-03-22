#ifndef OSTD_TYPE_TRAITS_H
#define OSTD_TYPE_TRAITS_H

namespace ostd {

    // Remove reference of type
    template<class T>
    struct remove_reference  {typedef T type;};

    template<class T>
    struct remove_reference<T&> {typedef T type;};

    template<class T>
    struct remove_reference<T&&> {typedef T type;};

}

#endif
