#include <memory>

struct Button {
    virtual void render() = 0;
    virtual void onClick() = 0;
    virtual ~Button() { }
};

struct WindowsButton: public Button {
    void render() override { }
    void onClick() override { }
};

struct HTMLButton: public Button {
    void render() override { }
    void onClick() override { }
};

struct Dialog {
    void render() {
        std::unique_ptr<Button> okButton = createButton();
        okButton->onClick();
        okButton->render();
    }
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual ~Dialog() { }
};

struct WindowsDialog: public Dialog {
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WindowsButton>();
    }
};

struct WebDialog: public Dialog {
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<HTMLButton>();
    }
};

class Application {
    std::unique_ptr<Dialog> dialog;
public:
    Application(): dialog{new WindowsDialog{}} { }
    void run() {
        dialog->render();
    }
};

int main() {
    Application application;
    application.run();
}
