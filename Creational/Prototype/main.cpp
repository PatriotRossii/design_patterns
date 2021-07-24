#include <memory>

enum class Color {
	Red,
	Blue
};

class Shape {
protected:
	Color color;
public:
	Shape(Color color): color{color} { }
	virtual std::unique_ptr<Shape> clone() const {
		return std::make_unique<Shape>(color);
	}
};

class Rectangle: public Shape {
	int width, height;
protected:
	std::unique_ptr<Shape> clone() const override {
		return std::make_unique<Rectangle>(
			color, width, height
		);
	}
public:
	Rectangle(Color color, int width, int height): Shape(color), width{width}, height{height} {}
};
