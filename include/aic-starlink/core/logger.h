#pragma once 

#include <mutex> 
#include <string>

#include <string_view>
using namespace std; 

namespace aic_starlink :: core 
{
    enum class LogLevel
    {
        Trace, 
        Debug, 
        Info, 
        Warn, 
        Error, 
        Critical
    }; 

    class Logger
    {
        public:
        Logger() = default;

        void setLevel(LogLevel level); 
        [[nodiscard]] LogLevel level() const noexcept; 

        void log(LogLevel level, string_view msg); 

        void trace(string_view msg);
        void debug(string_view msg); 

        void info(string_view msg); 
        void warn(string_view msg); 

        void error(string_view msg); 
        void critical(string_view msg); 

        private:
        LogLevel m_level{
            LogLevel :: Info
        };

        mutex m_mutex; 
    };
}