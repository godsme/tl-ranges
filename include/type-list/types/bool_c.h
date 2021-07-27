//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_E020BF9E02404BA19B54B5629F5596FC
#define TYPE_LIST_2_E020BF9E02404BA19B54B5629F5596FC

namespace holo {
    template<bool V>
    struct bool_t {
        constexpr operator bool() const { return V; }
        constexpr auto operator!() const -> auto {
            return bool_t<!V>{};
        }
    };

    template<bool V>
    constexpr auto bool_c = bool_t<V>{};

    constexpr auto true_c  = bool_c<true>;
    constexpr auto false_c = bool_c<false>;

    template<bool V1, bool V2>
    constexpr auto operator==(bool_t<V1>, bool_t<V2>) -> auto {
        return bool_c<V1 == V2>;
    }

    template<bool V1, bool V2>
    constexpr auto operator!=(bool_t<V1> l, bool_t<V2> r) -> auto {
        return !operator==(l, r);
    }

    template<bool V1, bool V2>
    constexpr auto operator&&(bool_t<V1> l, bool_t<V2> r) -> auto {
        return bool_c<V1 && V2>;
    }

    template<bool V1, bool V2>
    constexpr auto operator||(bool_t<V1> l, bool_t<V2> r) -> auto {
        return bool_c<V1 || V2>;
    }
}

#endif //TYPE_LIST_2_E020BF9E02404BA19B54B5629F5596FC
