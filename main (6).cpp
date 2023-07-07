#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class Сircular_Buffer
{
private:

    int size = 0;
    int capacity = size;
    T *current_front, *current_back;
    T *arr;

public:
    template<class Iter>
    class Iterator_of_Buffer
    {
        friend class Circular_Buffer;
    public:
        typedef Iter iterator_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef iterator_type value_type;
        typedef iterator_type& reference;
        typedef iterator_type* pointer;
        typedef ptrdiff_t difference_type;
        T *current_front1, *current_back1;
        T *arr1;
        int capacity1;
        iterator_type* value_of_iter;
    public:
        Iterator_of_Buffer(Iter*a,int capacity,T*arr ,T *current_front,T *current_back) : value_of_iter(a),capacity1(capacity),arr1(arr),current_front1(current_front),current_back1(current_back)
        {}
    public:
        Iterator_of_Buffer(const Iterator_of_Buffer& a) : value_of_iter(a.value_of_iter),capacity1(a.capacity1),arr1(a.arr1),current_front1(a.current_front1),current_back1(a.current_back1)
        {}
        bool operator==(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter==left.value_of_iter);
        }
        bool operator!=(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter!=left.value_of_iter);
        }
        typename Iterator_of_Buffer::reference operator*()const
        {
            return *value_of_iter;
        }
       /* typename Iterator_of_Buffer operator->()const
        {
            return *value_of_iter;
        }*/
        Iterator_of_Buffer& operator++()
        {
            if(current_back1!=&arr1[0])
            {
                if(current_back1==value_of_iter)
                {
                    value_of_iter=&arr1[0];

                }
                else if(value_of_iter==&arr1[capacity1-1] && value_of_iter!=current_back1)
                {
                    value_of_iter=&arr1[1];

                }
                else
                {
                    ++value_of_iter;

                }
            }

            return *this;
        }
        Iterator_of_Buffer& operator++(int val)
        {
            Iterator_of_Buffer *buf = this;
            if(current_back1!=&arr1[0])
            {
                if(current_back1==value_of_iter)
                {
                    value_of_iter==&arr1[0];

                }
                else if(value_of_iter==&arr1[capacity1-1] && value_of_iter!=current_back1 )
                {
                    value_of_iter=&arr1[1];

                }
                else
                {
                    ++value_of_iter;

                }
            }

            return *buf;
        }
        Iterator_of_Buffer& operator--()
        {
            if(current_back1!=&arr1[0])
            {
                if(value_of_iter==&arr1[1] && value_of_iter!=current_back1)
                {
                    value_of_iter=&arr1[capacity1-1];

                }
                else if(value_of_iter==current_back1)
                {
                    value_of_iter=&arr1[0];

                }
                else
                {
                    --value_of_iter;

                }return *this;
            }


        }
        Iterator_of_Buffer& operator--(int val)
        {
            Iterator_of_Buffer *buf = this;
            if(current_back1!=&arr1[0])
            {
                if(value_of_iter==&arr1[1] && value_of_iter!=current_back1)
                {
                    value_of_iter=&arr1[capacity1-1];

                }
                else if(value_of_iter==current_back1)
                {
                    value_of_iter=&arr1[0];

                }
                else
                {
                    --value_of_iter;

                }
            }


            return *buf;
        }
        Iterator_of_Buffer& operator+(int const val)
        {
            for(int i = 0;i<val;i++,++value_of_iter);
            return*this;
        }
        Iterator_of_Buffer& operator+=(int const val)
        {
            for(int i = 0;i<val;i++,++value_of_iter);
            return*this;
        }
        Iterator_of_Buffer& operator-(int const val)
        {
            for(int i = 0;i<val;i++,--value_of_iter);
            return*this;
        }
        bool operator<=(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter<=left.value_of_iter);
        }
        bool operator>=(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter>=left.value_of_iter);
        }
        bool operator<(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter<left.value_of_iter);
        }
        bool operator>(Iterator_of_Buffer const& left) const
        {
            return (this->value_of_iter>left.value_of_iter);
        }
        /*int& operator+(Iterator_of_Buffer const&left)
        {
            Iterator_of_Buffer iter(value_of_iter,capacity1,arr1 ,current_front1,current_back1);
            int counter = 0;
            while(iter.value_of_iter!=left.value_of_iter)
            {
                counter++;
                iter.value_of_iter;

            }
            return;
        }*/
        int& operator-(Iterator_of_Buffer const&left)
        {
           Iterator_of_Buffer iter(value_of_iter,capacity1,arr1 ,current_front1,current_back1);
           int counter = 0;
           while(iter.value_of_iter!=left.value_of_iter)
           {
               counter++;
               ++iter.value_of_iter;

           }
            return counter;
        }
        Iterator_of_Buffer& operator=(Iterator_of_Buffer const&left)
        {
            this->value_of_iter = left.value_of_iter;
            this->current_back1=left.current_back1;
            this->current_front1=left.current_front1;
            this->capacity1=left.capacity1;
                    this->arr1=left.arr1;
                    return *this;
        }
    };


    Сircular_Buffer(int size1) : size(size1)
    {
        this->capacity = size1;
        this->arr = new T[size1];
        this->current_front=&arr[0];
        this->current_back=&arr[0];


    }
    ~Сircular_Buffer()
    {
        delete [] arr;
    }
    void push_front(const T &value)
    {
        if(current_back!=&arr[0]) {
            if ((current_front == &arr[0] || current_front == &arr[1]) && current_back != &arr[capacity - 1]) {
                current_front = &arr[capacity - 1];
                *current_front = value;


            } else if ((current_front == &arr[0] || current_front == &arr[1]) && current_back == &arr[capacity - 1]) {
                current_front = &arr[capacity - 1];
                *current_front = value;
                --current_back;
            } else if (current_front != &arr[0] && current_front != &arr[1] && (current_front - 1) == current_back) {
                --current_front;
                *current_front = value;
                --current_back;

            } else if (current_front != &arr[0] && current_front != &arr[1] && (current_front - 1) != current_back) {
                --current_front;
                *current_front = value;

            }
        }
        else
        {
            if ((current_front == &arr[0] || current_front == &arr[1]))
            {
                current_front=&arr[capacity-1];
                *current_front=value;
            }
            else
            {
                --current_front;
                *current_front=value;
            }
        }


    }
    void push_back(const T &value)
    {
        if(current_front!=&arr[0]) {
            if (current_back == &arr[capacity - 1] && (current_front == &arr[1] || current_front == &arr[0])) {
                ++current_front;
                current_back = &arr[1];
                *current_back = value;
            } else if (current_front - 1 == current_back && current_front != &arr[0]) {
                ++current_back;
                *current_back = value;
                if (current_front != &arr[capacity - 1])
                    ++current_front;
                else
                    current_front = &arr[1];
            } else if (current_front == &arr[0]) {
                if(current_back!=&arr[capacity-1])
                {
                    ++current_back;
                    *current_back = value;
                }
                else
                {
                    current_back=&arr[1];
                    *current_back=value;
                }

            }
        }
        else if(current_front==&arr[0])
        {
            if(current_back==&arr[capacity-1])
            {
                current_back=&arr[1];
                *current_back=value;
            }
            else
            {
                ++current_back;
                *current_back=value;
            }
        }

    }
    T operator[](int value) const
    {
        return arr[value];
    }
    void pop_front() {
        if(current_front==&arr[0])
        {

        }
        else
        {
            if(current_back==&arr[0])
            {
                if(current_front==&arr[capacity-1])
                {
                    current_front=&arr[1];
                }
                else
                {
                    ++current_front;
                }
            }
            else
            {
                if(current_front==&arr[capacity-1] && current_back==&arr[1])
                {
                    current_front=&arr[1];
                    ++current_back;
                }
                else if(current_front==&arr[capacity-1] && current_back!=&arr[1])
                {
                    current_front=&arr[1];
                }
                else if(current_front+1==current_back)
                {
                    if(current_back!=&arr[capacity-1])
                    {
                        ++current_back;
                        ++current_front;
                    }
                    else
                    {
                        ++current_front;
                        current_back=&arr[1];
                    }

                }
                else
                {
                    ++current_front;
                }
            }
        }
    }
    void pop_back()
    {
        if(current_back==&arr[0])
        {

        }
        else
        {
            if(current_front==&arr[0])
            {
                if(current_back==&arr[1])
                {
                    current_back=&arr[capacity-1];
                }
                else
                {
                    --current_back;
                }
            }
            else
            {
                if(current_back==&arr[1] && current_front==&arr[capacity-1])
                {
                    --current_front;
                    current_back=&arr[capacity-1];
                }
                else if(current_back==&arr[1] && current_front!=&arr[capacity-1])
                {
                    current_back=&arr[capacity-1];
                }
                else if(current_back+1==current_front)
                {
                    if(current_front!=&arr[1])
                    {
                        --current_back;
                        --current_front;
                    }
                    else
                    {
                        current_front=&arr[capacity-1];
                        --current_back;
                    }

                }
                else
                {
                    --current_back;
                }
            }
        }
    }
    void change_capacity(const int &value)
    {

        if(value > this->capacity)
        {
            T *arr_new = new T[value];

            for(int i = 0;i<this->capacity;i++)
            {

                arr_new[i]=this->arr[i];

            }
            this->arr = arr_new;
            size = capacity;
            capacity = value;
            current_front = &arr[0];
            current_back = &arr[0];

        }
        else if(this->capacity >value)
        {
            T *arr_new = new T[value];

            for(int i = 0;i<value;i++)
            {

                arr_new[i]=this->arr[i];

            }
            this->arr = arr_new;
            capacity = value;
            size = capacity;
            current_front = &arr[0];
            current_back = &arr[0];
        }
        else if(this->capacity == value)
        {
            return;
        }
    }
    typedef Iterator_of_Buffer<T> iter;
    iter begin()
    {
        return iter(current_front,capacity,arr ,current_front,current_back);
    }
    iter end()
    {
        return iter(&arr[0],capacity,arr ,current_front,current_back);
    }
};


bool checker(int i)
{
    return(i==3);
}
template<class iterator,class predicant>
bool all_of_(iterator begin_,iterator end_,predicant function)
{
    for(auto it = begin_;it!=end_;++it)
    {
        if(function(*it)==false)
            return false;

    }
    return true;
}
template<class iterator,class predicant>
bool any_of_(iterator begin_,iterator end_,predicant function)
{
    for(auto it = begin_;it!=end_;++it)
    {
        if(function(*it)==true)
            return true;

    }
    return false;
}
template<class iterator,class predicant>
bool none_of_(iterator begin_,iterator end_,predicant function)
{
    for(auto it = begin_;it!=end_;++it)
    {
        if(function(*it)==true)
            return false;

    }
    return true;
}
template<class iterator,class predicant>
bool one_of_(iterator begin_,iterator end_,predicant function)
{
    int counter = 0;
    for(auto it = begin_;it!=end_;++it)
    {
        if(function(*it)==true)
            counter++;

    }
    if(counter==1)
        return true;
    else
        return false;
}
template<class iterator,class predicant>
bool is_sorted_(iterator begin_,iterator end_,predicant function)
{
    auto check = begin_;
    int counter = 0;
    for(auto it = begin_;it!=end_;++it) {
        if (counter >= 1) {
            if (check > it) {
                return false;
            } else {
                check = it;
            }
        }
        counter++;
    }
    return true;
    }
    template <class Iter, class Predicate>
    bool is_partitioned_ (Iter first, Iter last, Predicate pred)
    {
        while (first!=last && pred(*first)) {
            ++first;
        }
        while (first!=last) {
            if (pred(*first)) return false;
            ++first;
        }
        return true;
    }

template<class Iter, class Predicat>
Iter find_not_ (Iter first, Iter last, Predicat pred)
{
    while (first!=last) {
        if (!pred(*first))
            return first;
        ++first;
    }
    return last;
}
template<class iterator,class predicant>
std::string find_backward_(iterator begin_,iterator end_,predicant function)
{
    auto buf = begin_;
    bool check = false;
    for(auto it = begin_;it!=end_;++it)
    {
        if(function(*it)==true)
        {
            buf=it;
            check = true;
        }
    }
    if(check==true)
    return "YES,i find that!";
    else
        throw std::exception();
}
int main()
{
    Сircular_Buffer<int> p1(11);
    Сircular_Buffer<int> p(5);
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    p.change_capacity(6);
    p.push_front(1);
    std::cout << p[1] << " " << p[2]<< " " << p[3]<< " " << p[4] << p[5] << "\n";
    p.push_front(2);
    p.push_front(2);
    p.push_front(2);
    p.push_front(2);

    std::cout << p[1] << " " << p[2]<< " " << p[3]<< " " << p[4]<< " " << p[5] << "\n";
   p.push_front(3);
    p.push_front(3);
    p.push_front(3);
    p.push_front(3);
    p.push_front(3);
    std::cout << p[1] << " " << p[2]<< " " << p[3]<< " " << p[4]<< " " << p[5] << "\n";
    p.push_back(4);
    p.push_back(4);
    p.push_back(4);
    p.push_back(4);
    p.push_back(4);
    p.push_front(3);
    p.pop_back();
    p.push_back(1);







   // p.push_back(9);
    std::cout << p[1] << " " << p[2]<< " " << p[3]<< " " << p[4]<< " " << p[5] << "\n";
    for(auto it = p.begin();it!=p.end();++it)
    {
        std::cout << *it << " ";
    }
    //std::cout<<"\n";
    std::cout<<(find_backward_(p.begin(),p.end(), checker));
    return 0;
}