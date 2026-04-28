#pragma once 
#include <memory>

#include "../aic-starlink/core/error.h"
#include "../aic-starlink/core/module_context.h"

#include <iostream>
using namespace std; 

namespace aic_starlink:: core
{
    class StarlinkCore
    {
        public: 
        explicit StarlinkCore(ModuleContextPtr ctx);

        Error initialize(); 
        Error shutdown(); 

        [[nodiscard]] bool initialized() const noexcept;
        [[nodiscard]] ModuleContextPtr context() const noexcept; 

        private:
        ModuleContextPtr m_ctx; 
        bool m_initialized = false;
    }; 
} // namespace aic_starlink :: cire 