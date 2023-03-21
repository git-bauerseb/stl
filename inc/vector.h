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

			explicit vector(size_type size);


			// Access element of vector by reference. No range checking is performed.
			reference operator[](size_type index);
		
			// Access element of vector by value. No range check.
			value_type operator[](size_type index) const;


			~vector() {
				if (m_elements != nullptr) {
					delete[] m_elements;
				}
			}

		private:
			const size_type m_gf = 2;			// Growth factor
			size_type m_size;					// Number of elements stored in vector
			size_type m_capacity;				// Number of elements until reallocation
			value_type* m_elements = nullptr;	// Pointer to element storage
	};


	template<typename T>
	vector<T>::vector(size_type size) {
		if (size < 0) {
			throw std::length_error();
		}

		m_size = size;
		m_size = m_size * m_gf;
		m_elements = new T[m_size];
	}

	template<typename T>
	inline typename vector<T>::reference vector<T>::operator[](size_type index) {
		return m_elements[index];
	}

	template<typename T>
	inline typename vector<T>::value_type vector<T>::operator[](size_type index) const {
		return m_elements[index];
	}
}

#endif
