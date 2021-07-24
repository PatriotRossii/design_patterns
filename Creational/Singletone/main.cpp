#include <utility>

#include <iostream>

template<typename T, typename... Types>
T& single(Types&& ... args) {
	static T instance{std::forward<Types...>(args)...};
	return instance;
}

int main() {
	single<int>() += 101;
	std::cout << single<int>() << std::endl;
}