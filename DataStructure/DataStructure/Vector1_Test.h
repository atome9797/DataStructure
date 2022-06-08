#include <string>
#include <utility>
#include <assert.h>
#include <sstream>

//-------------------------------------------------------------------------------------------------
// MyVector �� �����ϴ� ������Ʈ
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector Ŭ����.
//-------------------------------------------------------------------------------------------------
class MyVector
{

    using iterator = MyObject*;
    using const_iterator = const MyObject*;

private: // ������ �ʿ��� ��� �߰� �Լ�/�������� �����Ӱ� �Ʒ��� ���� �մϴ�.

    // ��.1) ����� �����ϴ� ��������� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
    // int _vectorSize;

    MyObject* _container = nullptr;
    size_t _capacity = 0;
    size_t _size = 0;

    // ��.2) ��������� �ø��� �Լ��� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
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

public: // ������, ���������, �Ҵ翬����, �Ҹ��ڸ� .cpp ���Ͽ� �����մϴ�.
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

public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

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
    // �־��� ID�� �� MyObject �ν��Ͻ��� ����� �� ������ ���� �߰��մϴ�.
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
    // �־��� ID�� ���� MyObject �ν��Ͻ��� ù ��° �׸��� ��ȯ�մϴ�.
    // ã�� �� ������ nullptr�� ��ȯ�մϴ�.
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
    // �� ������ �뷮�� ���� ũ��� �ڸ��ϴ�.
    void TrimToSize()
    {
        if (_size == _capacity)
        {
            return;
        }

        reallocate(_size);
    }

    // Returns the MyObject instance at the specified index.
    // ������ �ε����� �ִ� MyObject �ν��Ͻ��� ��ȯ�մϴ�.
    MyObject& operator[](size_t index)
    {
        return _container[index];
    }

    // Returns string representation of the vector.
    // ������ ���ڿ� ǥ���� ��ȯ�մϴ�.
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
    //�� ���Ϳ��� �־��� ID�� ���� ��� MyObject �ν��Ͻ��� �����մϴ�.
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
    // ���� �Ҵ�� MyVector ��ü �迭�� ��ȯ�մϴ�.
    // ������ ��Ҵ� MyObject ����ü�� ������ "_id" ���� �����ϴ�.
    // 'numGroups'�� out �Ű������̸� ���� �������� �����ؾ� �մϴ�.
    // ��ȯ�� MyVector �迭�� ũ���Դϴ�.
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
