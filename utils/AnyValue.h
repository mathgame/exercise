#ifndef ANY_VALUE_H
#define ANY_VALUE_H
#include <cstdlib>
#include <tuple>

//TODO - Add debug error messages output on fail etc..

class some
{
    using id = size_t;

    template<typename T>
    struct type { static void id() { } };

    template<typename T>
    static id type_id() { return reinterpret_cast<id>(&type<T>::id); }

    template<typename T>
    using decay = typename std::decay<T>::type;

    template<typename T>
    using none = typename std::enable_if<!std::is_same<some, T>::value>::type;

    struct base
    {
        virtual ~base() { }
        virtual bool is(id) const = 0;
        virtual base *copy() const = 0;
    } *p = nullptr;

    template<typename T>
    struct data : base, std::tuple<T>
    {
        using std::tuple<T>::tuple;

        T       &get()      & { return std::get<0>(*this); }
        T const &get() const& { return std::get<0>(*this); }

        bool is(id i) const override { return i == type_id<T>(); }
        base *copy()  const override { return new data{get()}; }
    };

    template<typename T>
    T &stat() { return static_cast<data<T>&>(*p).get(); }

    template<typename T>
    T const &stat() const { return static_cast<data<T> const&>(*p).get(); }

    template<typename T>
    T &dyn() { return dynamic_cast<data<T>&>(*p).get(); }

    template<typename T>
    T const &dyn() const { return dynamic_cast<data<T> const&>(*p).get(); }

public:
     some() { }
    ~some() { delete p; }

    some(some &&s)      : p{s.p} { s.p = nullptr; }
    some(some const &s) : p{s.p->copy()} { }

    template<typename T, typename U = decay<T>, typename = none<U>>
    some(T &&x) : p{new data<U>{std::forward<T>(x)}} { }

    some &operator=(some s) { swap(*this, s); return *this; }

    friend void swap(some &s, some &r) { std::swap(s.p, r.p); }

    void clear() { delete p; p = nullptr; }

    bool empty() const { return p; }

    template<typename T>
    bool is() const { return p ? p->is(type_id<T>()) : false; }

    template<typename T> T      &&_()     && { return std::move(stat<T>()); }
    template<typename T> T       &_()      & { return stat<T>(); }
    template<typename T> T const &_() const& { return stat<T>(); }

    template<typename T> T      &&cast()     && { return std::move(dyn<T>()); }
    template<typename T> T       &cast()      & { return dyn<T>(); }
    template<typename T> T const &cast() const& { return dyn<T>(); }

    template<typename T> operator T     &&()     && { return std::move(_<T>()); }
    template<typename T> operator T      &()      & { return _<T>(); }
    template<typename T> operator T const&() const& { return _<T>(); }
};
using Any_t = some;

#endif //ANY_VALUE_H
