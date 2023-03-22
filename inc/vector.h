#pragma once
#ifndef OSTD_VECTOR_H
#define OSTD_VECTOR_H

// For size_t
#include <cstddef>

// For length_error
#include <stdexcept>

namespace ostd {

template<typename T>
class vector {
        public:
            using value_type = T;
            using size_type = size_t;
            using reference = T&;

            // Constructors, Destructors
            explicit vector(size_type size);
            ~vector();


            // Element access
            reference operator[](size_type index);              // No bounds checking
            value_type operator[](size_type index) const;       // No bounds checking

            // Capacity
            size_type size() const;                             // Number of allocated elements
            size_type capacity() const;                         // Elements without reallocation

            // Modifier
            void push_back(const reference value);

            template<typename ... Args>
            void emplace_back(Args&& ... args);

        private:
            const size_type m_gf = 2;            // Growth factor
            size_type m_size;                    // Number of elements stored in vector
            size_type m_capacity;                // Number of elements until reallocation
            value_type* m_elements = nullptr;    // Pointer to element storage
    };


    template<typename T>
    vector<T>::vector(size_type size) {
        if (size < 0) {
            throw std::length_error();
        }

        m_size = size;
        m_size = m_size;
        m_capacity = m_size + m_size / m_gf + 1;
        m_elements = new T[m_size];
    }

    template<typename T>
    vector<T>::~vector() {
        if (m_elements != nullptr) {
            delete[] m_elements;
        }
    }

    template<typename T>
    inline typename vector<T>::reference vector<T>::operator[](size_type index) {
        return m_elements[index];
    }

    template<typename T>
    inline typename vector<T>::value_type vector<T>::operator[](size_type index) const {
        return m_elements[index];
    }

    template<typename T>
    inline typename vector<T>::size_type vector<T>::size() const {
        return m_size;
    }

    template<typename T>
    inline void vector<T>::push_back(const reference value) {
        emplace_back();
    }

    template<typename T>
    template<typename ... Args>
    inline void vector<T>::emplace_back(Args&& ... args) {
        if (m_size == m_capacity) {
            m_capacity += m_size / m_gf + 1;
            reallocate();
        }
    }
}

#endif
