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
            using value_type                  = T;
            using pointer                     = T*;
            using const_pointer               = const T*;
            using reference                   = T&;
            using const_reference             = const T&;
            using size_type                   = size_t;

            using iterator                    = T*;
            using const_iterator              = const T*;

            // Constructors, Destructors
            vector() noexcept;
            explicit vector(size_type size);
            ~vector();


            // Element access   
            reference at(size_type index);                      // Bounds checking
            const_reference at(size_type index) const;          // Bounds checking


            reference operator[](size_type index);              // No bounds checking
            const_reference operator[](size_type index) const;  // No bounds checking


            // Iterators
            iterator begin() noexcept;
            const_iterator cbegin() const noexcept;

            iterator end() noexcept;
            const_iterator cend() const noexcept;


            // Capacity
            size_type size() const;                             // Number of allocated elements
            size_type capacity() const;                         // Elements without reallocation

            // Modifier
            void push_back(const_reference value);
            void push_back(T&& rvalue);

            template<typename ... Args>
            void emplace_back(Args&& ... args);

        private:
            void reallocate();
        
            const size_type m_gf = 2;            // Growth factor
            size_type m_size;                    // Number of elements stored in vector
            size_type m_capacity;                // Number of elements until reallocation
            pointer m_elements = nullptr;        // Pointer to element storage
    };

    
    template<typename T>
    vector<T>::vector() noexcept : m_size{0}, m_capacity{0} {}

    template<typename T>
    vector<T>::vector(size_type size) {
        if (size < 0) {
            throw std::length_error("Length cannot be negative");
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
    inline typename vector<T>::const_reference vector<T>::at(size_type index) const {
        if (index < 0 || index > (m_size-1)) {
            throw std::range_error("Cannot access vector element outside range");
        }

        return m_elements[index];
    }

    template<typename T>
    inline typename vector<T>::reference vector<T>::at(size_type index) {
        if (index < 0 || index > (m_size-1)) {
            throw std::range_error("Cannot access vector element outside range");
        }

        return m_elements[index];
    }


    // Iterators
    template<typename T>
    inline typename vector<T>::iterator vector<T>::begin() noexcept { return m_elements; }
    template<typename T>
    inline typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
        return m_elements + m_size;
    }

    template<typename T>
    inline typename vector<T>::iterator vector<T>::end() noexcept { return m_elements;}
    template<typename T>
    inline typename vector<T>::const_iterator vector<T>::cend() const noexcept {
        return m_elements + m_size;
    }


    // Element access
    template<typename T>
    inline typename vector<T>::reference vector<T>::operator[](size_type index) {
        return m_elements[index];
    }

    template<typename T>
    inline typename vector<T>::const_reference vector<T>::operator[](size_type index) const {
        return m_elements[index];
    }

    template<typename T>
    inline typename vector<T>::size_type vector<T>::size() const {
        return m_size;
    }

    template<typename T>
    inline void vector<T>::push_back(const_reference value) { emplace_back(value); }
    template<typename T>
    inline void vector<T>::push_back(T&& rvalue) { emplace_back(rvalue); }

    template<typename T>
    template<typename ... Args>
    inline void vector<T>::emplace_back(Args&& ... args) {
        if (m_size == m_capacity) {
            m_capacity += m_size / m_gf + 1;
            reallocate();
        }

        m_elements[m_size] = std::move(T(std::forward<Args>(args) ...));
        m_size++;
    }


    // Private member functions
    template<typename T>
    inline void vector<T>::reallocate() {
        T* extended = new T[m_capacity];

        // Move existing elements over to extended
        for (size_type i = 0; i < m_size; ++i) {
            extended[i] = std::move(m_elements[i]);
        }

        delete[] m_elements;
        m_elements = extended;
    }
}

#endif
