#pragma once
#include <stdlib.h>
#include <utility>
class MyVector
{
public:
    // �⺻ ������
    MyVector() = default;

    // count��ŭ ������ �Ҵ�� ������ MyVector(4) => 0 0 0 0
    explicit MyVector(size_t count)
        : _container(new int[count]), _size(count), _capacity(count)
    {
        for (size_t i = 0; i < count; i++)
        {
            _container[i] = 0;
        }
    }
    // ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector(const MyVector& other)
        : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }

    // �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector& operator=(MyVector rhs)
    {
        std::swap(_container, rhs._container);
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);
        return *this;
    }

    // �Ҹ���
    ~MyVector()
    {
        clear();
    }

    // ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    int* begin()
    {
        //���Ͱ� ����ִٸ� end()�� ��ȯ
        if (empty())
        {
            return end();
        }

        //���Ͱ� ������� �ʴٸ� ù��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container;

    }
    const int* begin() const
    {
        //���Ͱ� ����ִٸ� end()�� ��ȯ
        if (empty())
        {
            return end();
        }

        //���Ͱ� ������� �ʴٸ� ù��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container;
    }

    // ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    int* end()
    {
        //_container :�����̳��� �ּ�
        //_size : ���� ������ �ִ� ������ ����  int num[10] = {1,2,3} => size : 3 , capacity : 10
        //_capacity : �ִ� ������ ����
        return _container + _size;
    }
    const int* end() const
    {
        return _container + _size;
    }

    // �����̳ʰ� ������� �˻��Ѵ�.
    bool                empty() const
    {
        if (_size == 0) { //begin == end()
            return true;
        }
        else {
            return false;
        }
    }

    // ������ ������ ��ȯ�Ѵ�.
    size_t              size() const { return _size; }

    // ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t              capacity() const { return _capacity; }


    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
    int& operator[](size_t pos) { return _container[pos]; }
    const int& operator[](size_t pos) const { return _container[pos]; }

    // �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�.
    int& front() { return *begin(); }
    const int& front() const { return *begin(); }

    // �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
    int& back() { return *(end() - 1); }
    const int& back() const { return *(end() - 1); }

    // �����̳ʸ� ����.
    void                clear()
    {
        delete[] _container;
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }

    // pos ���� ��ġ�� value�� �����Ѵ�.
    // value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
    //��ĭ �и��� ������ �׾��ش�.

    int* insert(int* pos, int value)
    {
        //1.ù��° ���ҷ� ���� �󸶳� ������ �ִ°��� ����
        int dist = pos - begin();//�ּҰ��� ���� �Ÿ�����
        //2. �뷮�� Ȯ���Ѵ�.
        if (_capacity == 0)
        {
            reserve(1);

            pos = begin() + dist; //�ּ� ������ �̷���
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2); //�޸� Ȯ�� ��Ű�� �� ����
        }

        //3. ���� 
        //*iter = end() �κп��� container�ּҸ� ���� => �����̳��� �ּҸ� �ڷ� �о���
        for (int* iter = end(); iter != pos; --iter)
        {
            *iter = *(iter - 1);
        }

        //�ܺο��� ������ container �ּҸ� pos�� ������
        *pos = value; //insert�� pos ��ġ�� ���� �Ҵ� 

        //4. �ʵ� ������ �ֽ�ȭ
        ++_size; //�ϳ� �߰� �Ǿ����Ƿ� + 1��

        return pos; //
    }

    // pos�� ��ġ�� ���Ҹ� �����.
    // ������ ����� ���� �����͸� ��ȯ�Ѵ�.
    int* erase(int* pos)
    {
        //1. ����ִٸ� end() ��ȯ
        if (_size == 0)
        {
            return end();
        }

        int* last = end() - 1;

        //2. ������ �̵�(����)
        //for (int* iter = end(); iter != pos; --iter) //*iter = end() �κп��� container�ּҸ� ����
        //{
        //    *(iter - 1) = *iter;
        //}
        for (int* iter = pos; iter != last; ++iter) //*iter = end() �κп��� container�ּҸ� ����
        {
            *iter = *(iter + 1);
        }

        //3. �ʵ� ������Ʈ
        --_size;

        return pos;
    }

    // �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
    void                push_back(int value)
    {
        insert(end(), value);
        //int *ptr = insert(end(), value);
        //container �� insert�ʿ��� ó���� ������ �����
    }

    // �����̳��� ������ ���Ҹ� �����Ѵ�.
    void                pop_back()
    {
        erase(end() - 1);
    }

    // value�� �����ϴ��� �˻��Ѵ�.
    bool                contains(int value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (_container[i] == value) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    // �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
    // newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
    // �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.
    void                reserve(size_t newCapacity)
    {
        //1. newCapacity�� _capacity ���� ū�� ��
        if (newCapacity > _capacity) {

            //2. ���ο� �޸𸮸� �Ҵ�
            //int* new_container = (int*)malloc(sizeof(int) * newCapacity);
            int* new_container = new int[newCapacity]; //���� �Ҵ�

            //3. ���� �޸��� �����͸� ����
            for (int i = 0; i < _size; i++)
            {
                new_container[i] = _container[i];
            }
            //4. ���� �޸� ����
            delete[] _container;
            //free(_container);

            //5. �ʵ� ������ ���� _capacity = newCapacity;
            _capacity = newCapacity;
            _container = new_container;
        }
    }

private:
    int* _container = nullptr; //�迭 ������ �ڽ�=> �迭
    size_t              _size = 0;  // ���� �ε��� ��ȣ  => �迭�� ���� �Է��� ���� ����
    size_t              _capacity = 0; //������ ���� �ִ� ���� sizeof
};