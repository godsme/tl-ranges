//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_43F97EF6D1244E2E940DB99FF1725AA0
#define TYPE_LIST_2_43F97EF6D1244E2E940DB99FF1725AA0

namespace holo {
    struct nothing_t{};
    constexpr auto nothing_c = nothing_t{};

    template<typename T>
    constexpr auto operator==(T, nothing_t) -> auto {
        return false_c;
    }

    template<typename T>
    constexpr auto operator==(nothing_t, T) -> auto {
        return false_c;
    }

    constexpr auto operator==(nothing_t, nothing_t) -> auto {
        return true_c;
    }

    constexpr auto operator!=(nothing_t, nothing_t) -> auto {
        return false_c;
    }

    template<typename T>
    constexpr auto operator!=(T, nothing_t) -> auto {
        return true_c;
    }

    template<typename T>
    constexpr auto operator!=(nothing_t, T) -> auto {
        return true_c;
    }
}

#endif //TYPE_LIST_2_43F97EF6D1244E2E940DB99FF1725AA0
