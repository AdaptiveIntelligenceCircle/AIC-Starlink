#pragma once 
#include <iostream>

#include <string> 
using namespace std;

namespace aic_starlink :: core 
{
    enum class ErrorCode
    {
        Ok = 0, 

        InvalidArgument, 
        InvalidState, 
        NotInitialized, 

        FileNotFound, 
        FileIOError, 

        JsonParserError, 
        SchemaValidationError, 

        SimulationError, 
        TelemetryError, 
        DetectionError, 
        PolicyError, 
        IntegrationError, 

        NotImplemented,
        InternalError
    }; 

    struct Error
    {
        ErrorCode code{
            ErrorCode :: Ok
        }; 

        [[nodiscard]] bool Ok() const noexcept
        {
            return code == ErrorCode :: Ok; 
        }

        static Error success()
        {
            return Error{
                ErrorCode :: Ok
            }; 
        }

        static Error failure(ErrorCode c , string msg)
        {
            return Error{
                c
            }; 
        }
    }; 
}