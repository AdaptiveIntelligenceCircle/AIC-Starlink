#include "../aic-starlink/core/logger.h"
#include <chrono> 

#include <ctime>
#include <iostream> 

using namespace std; 

namespace aic_starlink :: core 
{
    static const char *toString(LogLevel lvl) 
    {
        switch(lvl)
        {
            case LogLevel :: Trace : return "Trace"; 
            case LogLevel :: Debug : return "Debug";
            case LogLevel :: Info : return "INFO"; 
            case LogLevel :: Warn : return "Warn"; 
            case LogLevel :: Error : return "Error"; 
            case LogLevel :: Critical : return "Critical"; 
            default : return "UNknown"; 
        }

    }

    void Logger :: setLevel(LogLevel level)
    {
        lock_guard<mutex> lock(m_mutex); 
        m_level = level; 
    }

    LogLevel Logger :: level() const noexcept 
    {
        return m_level; 
    }

    void Logger :: log(LogLevel level, string_view msg)
    {
        lock_guard<mutex> lock(m_mutex);

        if (static_cast<int>(level) < static_cast<int>(m_level))
        return; 

        cout << "[" << toString(level) << "]" << msg << endl; 
    }

    void Logger :: trace(string_view msg)
    {
        log(LogLevel :: Trace, msg); 
    }

    void Logger :: debug(string_view msg)
    {
        log(LogLevel :: Debug, msg); 
    }

    void Logger :: info(string_view msg)
    {
        log(LogLevel :: Info , msg); 
    }

    void Logger :: warn(string_view msg)
    {
        log(LogLevel:: Warn, msg); 
    }

    void Logger :: error(string_view msg)
    {
        log(LogLevel :: Error, msg); 
    }

    void Logger :: critical(string_view msg)
    {
        log(LogLevel :: Critical, msg); 
    }
}