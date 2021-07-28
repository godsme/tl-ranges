//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_0730319B6B9F454DAE4DCFDDEBC0B009
#define TYPE_LIST_2_0730319B6B9F454DAE4DCFDDEBC0B009

namespace holo::detail {
    template <typename T, typename F>
    struct fold_helper {
        constexpr fold_helper(T result, F const& f) : result_(result), f_(f) {}

        template<typename ELEM>
        constexpr auto operator<<(ELEM&& elem) const {
            auto result = f_(result_, elem);
            return fold_helper<decltype(result), F>{result, f_};
        }

        constexpr auto operator()() const -> T const& { return result_; }

    private:
        T result_;
        F f_;
    };

    template <typename T, typename F>
    fold_helper(T const&, F const&) -> fold_helper<T, F>;
}

#endif //TYPE_LIST_2_0730319B6B9F454DAE4DCFDDEBC0B009
