//
// Created by mengjie on 1/6/20.
//

#ifndef IO_MULTIPLEXING_MYTUPLE_HPP

template <typename... Tail> class tuple;
template<>
class tuple<>{};

template <typename  Head, typename... Tail>
class tuple<Head, Tail...>
        :private tuple<Tail...>{
private:
    typedef tuple<Tail...> inherited;
protected:
    Head mValue;
public:
    tuple(Head value, Tail... vTail)
        :inherited(vTail...),mValue(value){
    }
    Head head(){return mValue;}

    inherited& tail(){return *this;}

//    auto operator[](int n)-> decltype(sizeof...(Tail)){
//    }
};

#define IO_MULTIPLEXING_MYTUPLE_HPP

#endif //IO_MULTIPLEXING_MYTUPLE_HPP
