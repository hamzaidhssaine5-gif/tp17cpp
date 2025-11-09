#include <iostream>
#include <string>

class Logger {
private:
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }
};

class Config {
public:
    Config() {}

    std::string getValue(const std::string& key) const {
        if (key == "app_name") return "DemoApp";
        return "undefined";
    }
};

int main() {
    Logger::getInstance().log("Démarrage de l'application");
    Config config;
    std::cout << "Nom de l'application: " << config.getValue("app_name") << std::endl;
    return 0;
}
