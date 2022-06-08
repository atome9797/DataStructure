#include <string>
#include <utility>
#include <assert.h>
#include <sstream>

//-------------------------------------------------------------------------------------------------
// MyVector 가 관리하는 오브젝트
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector 클래스.
//-------------------------------------------------------------------------------------------------
class MyVector
{

    using iterator = MyObject*;
    using const_iterator = const MyObject*;

private: // 구현에 필요한 멤버 추가 함수/변수들을 자유롭게 아래에 정의 합니다.

    // 예.1) 사이즈를 저장하는 멤버변수를 아래처럼 추가하면 됩니다.
    // int _vectorSize;

    MyObject* _container = nullptr;
    size_t _capacity = 0;
    size_t _size = 0;

    // 예.2) 저장공간을 늘리는 함수를 아래처럼 추가하면 됩니다.
    // void Grow();

    iterator begin() { return _container; }
    const_iterator begin() const { return _container; }
    iterator end() { return _container + _size; }
    const_iterator end() const { return _container + _size; }
    iterator erase(iterator pos)
    {
        if (_size == 0)
        {
            return end();
        }
        iterator last = end() - 1;

        for (iterator iter = pos; iter != last; iter++)
        {
            *iter = *(iter + 1);
        }

        _size--;

        return pos;
    }
    void reallocate(int newCapacity)
    {
        MyObject* newContainer = new MyObject[newCapacity];

        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }

        delete[] _container;

        _container = newContainer;
        _capacity = newCapacity;
    }
    void reserve(int newCapacity)
    {
        if (_capacity >= newCapacity)
        {
            return;
        }

        reallocate(newCapacity);
    }

    void Clear()
    {
        delete[] _container;
        _container = nullptr;
        _capacity = 0;
        _size = 0;
    }

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.
    MyVector() = default;
    // Constructor.
    MyVector(int capacity)
        : _container(new MyObject[capacity]), _size(0), _capacity(capacity)
    { }

    // Copy constructor.
    MyVector(const MyVector& other)
        : _container(new MyObject[other._capacity]), _size(other._size),
        _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }

    // Assignment operator.
    MyVector& operator=(MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }
        MyVector temp(other);
        std::swap(_container, other._container);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);

        return *this;
    }
    // Destructor.
    ~MyVector()
    {
        Clear();
    }

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

    // Returns current capacity of this vector.
    int GetCapacity() const
    {
        return _capacity;
    }

    // Returns current size of this vector.
    int GetSize() const
    {
        return _size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    // 주어진 ID로 새 MyObject 인스턴스를 만들고 이 벡터의 끝에 추가합니다.
    void Add(int id)
    {
        if (_size == _capacity)
        {
            reserve((_capacity == 0) ? 1 : _capacity * 2);
        }

        _container[_size]._id = id;
        _size++;
    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    // 주어진 ID를 가진 MyObject 인스턴스의 첫 번째 항목을 반환합니다.
    // 찾을 수 없으면 nullptr을 반환합니다.
    MyObject* FindById(int MyObjectId) const
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i]._id == MyObjectId)
            {
                return &_container[i];
            }

        }
        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    // 이 벡터의 용량을 현재 크기로 자릅니다.
    void TrimToSize()
    {
        if (_size == _capacity)
        {
            return;
        }

        reallocate(_size);
    }

    // Returns the MyObject instance at the specified index.
    // 지정된 인덱스에 있는 MyObject 인스턴스를 반환합니다.
    MyObject& operator[](size_t index)
    {
        return _container[index];
    }

    // Returns string representation of the vector.
    // 벡터의 문자열 표현을 반환합니다.
    std::string ToString() const
    {
        std::stringstream ss;

        ss << "[";
        for (size_t i = 0; i < _size; i++)
        {
            ss << _container[i]._id << ",";
        }
        ss << "]";

        return ss.str();
        /*std::string str;

        for (int i = 0; _container != nullptr; i++)
        {
            str += std::to_string(_container[i]._id);
        }

        return str;*/
    }

    // Remove all MyObject instances with the given ID in this vector.
    //이 벡터에서 주어진 ID를 가진 모든 MyObject 인스턴스를 제거합니다.
    void RemoveAll(int MyObjectId)
    {
        iterator iter = begin();

        while (iter != end())
        {
            if (iter->_id == MyObjectId)
            {
                iter = erase(iter);
            }
            else
            {
                iter++;
            }
        }
        /* for (int i = 0; _container != nullptr; i++)
         {
             if (_container[i]._id == MyObjectId)
             {
                 delete[] (_container + i);
             }
         }*/
    }

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    // 
    // 새로 할당된 MyVector 객체 배열을 반환합니다.
    // 각각의 요소는 MyObject 구조체의 동일한 "_id" 값을 갖습니다.
    // 'numGroups'는 out 매개변수이며 값을 다음으로 설정해야 합니다.
    // 반환할 MyVector 배열의 크기입니다.
    MyVector* GroupById(int* numGroups)
    {
        MyVector ids;
        for (size_t i = 0; i < _size; i++)
        {
            if (ids.FindById(_container[i]._id) == nullptr)
            {
                ids.Add(_container[i]._id);
            }

        }
        int count = ids.GetSize();
        MyVector* result = new MyVector[count];

        for (size_t i = 0; i < _size; i++)
        {
            size_t index = ids.FindById(_container[i]._id) - ids.begin();
            result[index].Add(_container[i]._id);
        }

        *numGroups = count;
        return result;

    }
};
