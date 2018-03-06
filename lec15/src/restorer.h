#pragma once

template <typename T>
class Restorer
{
public:
    explicit Restorer(T& var)
            : Restorer(var, var)
    { }

    Restorer(T& var, const T& val)
            : var_(&var), val_(val), active_(true)
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
        if (active_) *var_ = val_;
    }

private:
    T* var_ = nullptr;
    T val_;
    bool active_ = false;
};

template <typename T>
Restorer<T> make_restorer(T& var)
{
    return Restorer<T>(var);
}
