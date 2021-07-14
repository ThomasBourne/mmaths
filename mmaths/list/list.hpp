#ifndef LIST_HPP
#define LIST_HPP

#include <iostream> //eww dont want that
#include <cstdarg>

namespace mmaths {
		template<typename T>
		class list_box { //2D dont work fool
		private:
			//array pointer
			T* arr;

			//total storage capacity of the list
			int capacity;

			//number of elements currently in the array
			int current;
		public:
			inline list_box() {
				//delete[] this->arr;
				this->arr = new T[1];
				this->capacity = 1;
				this->current = 0;
			}
			
			inline list_box(int count, ...) {
				va_list ls;
				va_start(ls, count);
				//delete[] this->arr;
				this->arr = new T[count];
				this->capacity = count;
				this->current = count;
				for (int i = 0; i < count; i++) {
					this->arr[i] = va_arg(ls, T);
				}
			}

			inline list_box(T data[]) {
				//delete[] this->arr;
				this->arr = new T[sizeof(data) / sizeof(data[0])];
				this->arr = data;
				this->capacity = sizeof(data) / sizeof(data[0]);
				this->current = this->capacity;
			}

			void PushBack(T data) {
				//if num elements == capacity, we don't have space to accommodate more elements, so double the capacity
				if (this->current == this->capacity) {
					T* temp = new T[2 * this->capacity];

					// copying old array elements to new array
					for (int i = 0; i < this->capacity; i++) {
						temp[i] = this->arr[i];
					}

					// deleting previous array
					delete[] this->arr;
					this->capacity *= 2;
					this->arr = temp;
				}

				// Inserting data
				this->arr[current] = data;
				this->current++;
			}

			void Push(T data, int index) {
				if (index == this->capacity)
					this->PushBack(data);
				else
					this->arr[index] = data;
			}

			void Add(int count, ...) {
				va_list ls;
				va_start(ls, count);
				for (int i = 0; i < count; i++)
					this->PushBack(va_arg(ls, T));
			}

			T Get(int index) {
				if (index < this->current) {
					return this->arr[index];
				}
			}

			void Pop() {
				this->current--;
			}

			int Size() {
				return this->current;
			}

			int Capacity() {
				return this->capacity;
			}

			void Print() { //not using << as std::ostream may not be avaliabe; and want to move away from cout
				for (int i = 0; i < this->current; i++)
					std::cout << this->arr[i] << " ";
				std::cout << std::endl;
			}

			//overloads
			inline void operator+=(T add) {
				PushBack(add);
			}

			inline void operator=(T data[]) {
				delete[] this->arr;
				this->arr = new T[sizeof(data) / sizeof(data[0])];
				this->arr = data;
				this->capacity = sizeof(data) / sizeof(data[0]);
				this->current = this->capacity;
				/*
				
				delete[] this->arr;
				this->arr = new T[1];
				this->capacity = 1;
				this->current = 0;

				for (auto& ele : data) {
					this->PushBack(ele);
				}
				*/
			}
		};

	template<typename T>
	using list = list_box<T>;
	using listi = list_box<int>;
	using listf = list_box<float>;
	using listd = list_box<double>;
}
#endif