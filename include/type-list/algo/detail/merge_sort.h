//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_5522B6D97CBC4518A33787C81CB6D76F
#define TYPE_LIST_2_5522B6D97CBC4518A33787C81CB6D76F

#include <type-list/types/tuple_c.h>

namespace holo::detail {
    template<typename TUPLE, typename LT, std::size_t L, std::size_t R>
    constexpr bool take_left_v = decltype(std::declval<LT>()(get<L>(std::declval<TUPLE>()), get<R>(std::declval<TUPLE>()))){};

    ////////////////////////////////////////////////////////////////////////
    template
        < typename TUPLE
        , typename LT
        , typename Ln
        , typename Rn
        , std::size_t ... Result>
    struct merge;

    template
        < typename TUPLE
        , typename LT
        , std::size_t L0
        , std::size_t ... Ln
        , std::size_t R0
        , std::size_t ... Rn
        , std::size_t ... Result>
    struct merge<TUPLE, LT, std::index_sequence<L0, Ln...>, std::index_sequence<R0, Rn...>, Result...> {
        using take_left = typename merge<
                TUPLE, LT,
                std::index_sequence<Ln...>,
                std::index_sequence<R0, Rn...>,
                Result...,
                L0>::type;

        using take_right = typename merge<
                TUPLE, LT,
                std::index_sequence<L0, Ln...>,
                std::index_sequence<Rn...>,
                Result...,
                R0>::type;

        using type = std::conditional_t
                < take_left_v<TUPLE, LT, L0, R0>
                , take_left
                , take_right>;
    };

    template
        < typename TUPLE
        , typename LT
        , std::size_t ... Rn
        , std::size_t ... Result>
    struct merge<TUPLE, LT, std::index_sequence<>, std::index_sequence<Rn...>, Result...> {
        using type = std::index_sequence<Result..., Rn...>;
    };

    template
        < typename TUPLE
        , typename LT
        , std::size_t ... Ln
        , std::size_t ... Result>
    struct merge<TUPLE, LT, std::index_sequence<Ln...>, std::index_sequence<>, Result...> {
        using type = std::index_sequence<Result..., Ln...>;
    };

    ////////////////////////////////////////////////////////////////////////
    template<std::size_t Start, std::size_t ... Xn>
    auto make_sequence(std::index_sequence<Xn...>) -> std::index_sequence<Start+Xn...>;

    ////////////////////////////////////////////////////////////////////////
    template<typename TUPLE, typename LT, typename Xn>
    struct merge_sort {
        using type = Xn;
    };

    template<typename TUPLE, typename LT, std::size_t X0, std::size_t ... Xn>
    struct merge_sort<TUPLE, LT, std::index_sequence<X0, Xn...>> {
        constexpr static size_t len = sizeof...(Xn) + 1;
        constexpr static size_t half = len / 2;
        using left  = decltype(make_sequence<X0>(std::make_index_sequence<half>{}));
        using right = decltype(make_sequence<X0 + half>(std::make_index_sequence<len - half>{}));
        using type = typename merge
                < TUPLE
                , LT
                , typename merge_sort<TUPLE, LT, left>::type
                , typename merge_sort<TUPLE, LT, right>::type
                >::type;
    };

    template<typename TUPLE, typename LT, std::size_t N>
    struct merge_sort<TUPLE, LT, std::index_sequence<N>> {
        using type = std::index_sequence<N>;
    };

    template<typename TUPLE, typename LT>
    using merge_sort_t = typename merge_sort<TUPLE, LT, std::make_index_sequence<TUPLE::size()>>::type;
}

#endif //TYPE_LIST_2_5522B6D97CBC4518A33787C81CB6D76F
