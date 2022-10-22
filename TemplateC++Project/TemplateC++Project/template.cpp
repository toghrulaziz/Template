#include <iostream>
using namespace std;

//Task 
// Class DynamicArray (template<class t, int len>) ++
// Example: DynamicArray<double, 20> da; ++
// Copy Constructor, Copy Assignment operator, Default Constructor ++
// InitRandom() ++
// [] operator overloading ++
// AddElementToEnd ++
// AddElementToHead ++
// AddElementByIndex ++
// DeleteElementByIndex ++
// Print() ++


template<class T,int len>
class DynamicArray {
	T* arr;
	int count = 0;
	int capacity = len;
public:

	DynamicArray() {
		arr = new T[capacity];
	}

	DynamicArray(DynamicArray const& other) {
		delete[] this->arr;
		this->arr = other.arr;
		for (int i = 0; i < other.count; i++) {
			this->arr[i] = other.arr[i];
		}
		this->count = other.count;
	}

	DynamicArray& operator=(DynamicArray const& other) {
		delete[] this->arr;
		this->arr = other.arr;
		for (int i = 0; i < other.count; i++) {
			this->arr[i] = other.arr[i];
		}
		this->count = other.count;
	}

	T* GetArr() const { return arr; }
	int GetSize() const { return size; }



	void InitRandom(int min, int max) {
		for (int i = 0; i < capacity; i++) {
			arr[i] = min + rand() % (max - min + 1);
			count++;
		}
	}


	void AddElementToEnd(T element) {
		if (count == capacity) {
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < count; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[count] = element;
		count++;
	}



	void AddElementToHead(T element) {
		if (count != capacity) {
			T* temp = new T[capacity];
			for (int i = 0; i < count; i++) {
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}

		else if (count == capacity) {
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < count + 1; i++) {
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[0] = element;
		count++;
	}


	void AddElementByIndex(int index, T element) {
		if (count != capacity) {
			T* temp = new T[capacity];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			for (int i = index + 1; i < count + 1; i++) {
				temp[i] = arr[i - 1];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else if (count == capacity) {
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			for (int i = index + 1; i < count + 1; i++) {
				temp[i] = arr[i - 1];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[index] = element;
		count++;
	}

	void DeleteElementByIndex(int index) {
		T* temp = new T[count - 1];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}
		for (int i = index; i < count - 1; i++) {
			temp[i] = arr[i + 1];
		}
		delete[] arr;
		arr = temp;
		temp = nullptr;
		count--;
	}



	T& operator[](int index) {
		return arr[index];
	}


	void Print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~DynamicArray() {
		delete[] arr;
	}

};


void main() {
	srand(time(0));
	DynamicArray<int, 5> d;
	d.InitRandom(1, 5);
	d.AddElementToEnd(11);
	d.DeleteElementByIndex(4);
	d.AddElementByIndex(1, 4);
	d.AddElementToHead(4);
	d.Print();
}