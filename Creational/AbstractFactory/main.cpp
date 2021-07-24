#include <memory>

#include <iostream>

struct Chair {
    virtual void sit() = 0;
    virtual ~Chair() {}
};

struct ModernChair: Chair {
    void sit() override {
        std::cout << "Сидим на современном стуле" << '\n';
    }
};
struct ArtDecoChair: Chair {
    void sit() override {
        std::cout << "Сидим на ар-деко стуле" << '\n';
    }
};

struct VictorianChair: Chair {
    void sit() override {
        std::cout << "Сидим на ар-деко стуле" << '\n';
    }
};

struct FurnitureFactory {
    virtual std::unique_ptr<Chair> createChair() = 0;
    virtual ~FurnitureFactory() {}
};

struct ArtDecoFurnitureFactory: FurnitureFactory {
    std::unique_ptr<Chair> createChair() override {
        return std::make_unique<ArtDecoChair>();
    }
};

struct ModernFurnitureFactory: FurnitureFactory {
    std::unique_ptr<Chair> createChair() override {
        return std::make_unique<ModernChair>();
    }
};

struct VictorianFurnitureFactory: FurnitureFactory {
    std::unique_ptr<Chair> createChair() override {
        return std::make_unique<VictorianChair>();
    }
};

enum class FactoryType {
    ArtDeco,
    Modern,
    Victorian
};


int main() {
    FactoryType factory_type = /* choose_factory() - очень умный метод, выбирающий фабрику */ FactoryType::ArtDeco;

    std::unique_ptr<FurnitureFactory> factory;
    if (factory_type == FactoryType::ArtDeco) {
        factory = std::make_unique<ArtDecoFurnitureFactory>();
    } else if (factory_type == FactoryType::Modern) {
        factory = std::make_unique<ModernFurnitureFactory>();
    } else if (factory_type == FactoryType::Victorian) {
        factory = std::make_unique<VictorianFurnitureFactory>();
    }

    std::unique_ptr<Chair> chair = factory->createChair();
    chair->sit();
}