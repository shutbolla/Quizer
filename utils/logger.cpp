#include "utils/logger.h"
#include <fstream>
#include <ctime>
#include <mutex>
#include <sstream>
#include <iostream>

namespace logger {

    namespace {

        enum class level { info, warning, error };

        std::mutex s_mutex;

        std::ofstream &get_file() {

            static std::ofstream file("log.txt", std::ios::out | std::ios::trunc);

            return file;
        }

        const char *type_str(logger::level level_) {

            switch (level_) {

            case logger::level::info: return "INFO";

            case logger::level::warning: return "WARN";

            case logger::level::error: return "ERROR";
            }

            return "";
        }

        void log(logger::level level_, const std::string &msg) {

            std::lock_guard<std::mutex> lock(s_mutex);

            std::time_t time_ = std::time(nullptr);

            char time_buffer[9];

            std::tm tm_buffer{};

#ifdef _WIN32

            localtime_s(&tm_buffer, &time_);

#else

            localtime_r(&time_, &tm_buffer);

#endif

            std::strftime(time_buffer, 9, "%H:%M:%S", &tm_buffer);

            std::ostringstream line;

            line << "[" << time_buffer << "] [" << type_str(level_) << "] " << msg << "\n";

            get_file() << line.str();

            get_file().flush();

            std::cout << line.str();
        }
    }

    void info(const std::string &msg) { logger::log(logger::level::info, msg); }

    void warn(const std::string &msg) { logger::log(logger::level::warning, msg); }

    void error(const std::string &msg) { logger::log(logger::level::error, msg); }
}