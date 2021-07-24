#include <stdexcept>

#include <memory>

struct House {
	House() {}

	int countOfBathrooms{0};
	int countOfBedrooms{0};

	bool hasGarden{false};
	bool hasSwimmingPool{false};
	bool hasGarage{false};

	bool hasFancyStatues{false};
};

class HouseBuilder {
private:
	std::shared_ptr<House> house{new House()};

	static const int MAX_BATHROOMS{50};
	static const int MAX_BEDROOMS{10};

	int countOfBathrooms{0};
	int countOfBedrooms{0};

	bool hasGarden{false};
	bool hasSwimmingPool{false};
	bool hasGarage{false};

	bool hasFancyStatues{false};
public:
	HouseBuilder() {}

	void setBathrooms(int count) {
		if(count < 0 || count > MAX_BATHROOMS) {
			throw std::runtime_error{"Иди к черту"};
		}
		house->countOfBathrooms = count;
	}
	void setBedrooms(int count) {
		if(count < 0 || count > MAX_BEDROOMS) {
			throw std::runtime_error{"Иди к черту"};
		}
		house->countOfBedrooms = count;
	}

	void buildGarden() {
		house->hasGarden = true;
	}
	void buildSwimmingPool() {
		house->hasSwimmingPool = true;
	}
	void buildGarage() {
		house->hasGarage = true;
	}

	void buildFancyStatues() {
		house->hasFancyStatues = true;
	}

	std::shared_ptr<House> build() {
		return house;
	} 
};

int main() {
	HouseBuilder builder;

	builder.buildGarden();
	builder.setBathrooms(/* 500 */ 10);

	builder.build();
}