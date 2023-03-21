#pragma once

template<typename T>
class vector {

	public:
		vector(int size) {
			m_size = size;
			m_elements = new T[m_size];
		}

		~vector() {
			if (m_elements != nullptr) {
				delete[] m_elements;
			}
		}

	private:
		int m_size;
		T* m_elements;
};
