namespace py{
template<typename dataType>
class clasRange{
public:

    template<typename T>
    class iterator{
    private:
        T data;
        T step;
    public:
        iterator(T i, T j):data(i), step(j){}
        T operator*() const{return data;}
        T& operator*(){return data;}
        iterator operator++(){data+=step; return *this;}
        inline friend bool operator==(iterator dis, iterator dat){return dis.data == dat.data;}
        inline friend bool operator!=(iterator dis,iterator dat){return dis.data!=dat.data;}
    };

    dataType start_, end_, step_;
public:
    clasRange(const clasRange&that):start_(that.start_), end_(that.end_), step_(that.step_){}
    clasRange(dataType start, dataType end, dataType step):start_(start), end_(end), step_(step){}
    iterator<dataType> begin(){return clasRange::iterator<dataType>(start_, step_);}
    iterator<dataType> end(){return clasRange::iterator<dataType>(end_, step_);}
};

template<typename T=int>
clasRange<T> range(T a){return clasRange<T>(0,a,1);}

template<typename T=int>
clasRange<T> range(T a, T b, T c=1){return clasRange<T>(a,b,c);}
}