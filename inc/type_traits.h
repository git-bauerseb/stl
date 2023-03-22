#ifndef OSTD_TYPE_TRAITS_H
#define OSTD_TYPE_TRAITS_H

namespace ostd {

    // Removes reference from type
    template<typename T>
    struct remove_reference  {typedef T type;};
    template<typename T>
    struct remove_reference<T&> {typedef T type;};
    template<typename T>
    struct remove_reference<T&&> {typedef T type;};

    // Checks if two types are the same
    template<typename T, typename S>
    struct is_same { constexpr static bool value = false; };
    template<typename T>
    struct is_same<T,T> { constexpr static bool value = true; };


}

#endif
