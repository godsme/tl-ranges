//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_83551568A5224FA499D85DFF0D418089
#define TYPE_LIST_2_83551568A5224FA499D85DFF0D418089

#include <type-list/types/size_c.h>
#include <type_traits>

namespace holo {
    template<typename T>
    struct type_t;

    namespace detail {
        template<typename T> struct type_t_trait {
            using type = T;
        };

        template<typename T>
        struct type_t_trait<type_t<T>> {
            using type = typename type_t<T>::type;
        };
    }

    template<typename T>
    struct type_t {
        using type = typename detail::type_t_trait<T>::type;
        using this_type = type_t<type>;
        constexpr auto size() const -> auto {
            return size_c<sizeof(type)>;
        }
    };

    template<typename T>
    constexpr auto type_c = type_t<T>{};

    template<typename T1, typename T2>
    constexpr auto operator==(type_t<T1>, type_t<T2>) -> auto {
        return bool_c<std::is_same_v<typename type_t<T1>::type, typename type_t<T2>::type>>;
    }

    template<typename T1, typename T2>
    constexpr auto operator!=(type_t<T1> lhs, type_t<T2> rhs) -> auto {
        return !operator==(lhs, rhs);
    }
}

#endif //TYPE_LIST_2_83551568A5224FA499D85DFF0D418089
