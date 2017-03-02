template <typename T>
class Restorer
{
public:
    Restorer()
            : ptr_(nullptr), active_(false)
    { }

    explicit Restorer(T& var)
            : Restorer(var, var)
    { }

    Restorer(T& var, const T& val)
            : ptr_(&var), val_(val), active_(true)
    { }

    ~Restorer()
    {
        rollback();
    }

    void commit()
    {
        active_ = false;
    }

    void rollback()
    {
        if (active_) *ptr_ = val_;
    }

private:
    T* ptr_;
    T val_;
    bool active_;
};

template <typename T>
Restorer<T> make_restorer(T& var)
{
    return Restorer<T>(var);
}
