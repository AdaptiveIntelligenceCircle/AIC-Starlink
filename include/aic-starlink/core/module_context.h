#pragma once 

#include <memory> 

#include "../aic-starlink/core/logger.h"
#include "../aic-starlink/core/module_config.h"

using namespace std;

namespace aic_starlink :: core 
{
    class ModuleContext
    {
        public:
        ModuleContext(); 

        explicit ModuleContext(ModuleConfig config); 

        [[nodiscard]] ModuleConfig& config() noexcept; 
        [[nodiscard]] const ModuleConfig &config() const noexcept; 

        [[nodiscard]] Logger &logger() noexcept; 
        [[nodiscard]] const Logger&logger() const noexcept; 

        void setConfig(ModuleConfig cfg); 

        private: 
        ModuleConfig m_config{}; 
        Logger m_logger{}; 
    };

    using ModuleContextPtr = shared_ptr<ModuleContext>; 
} // namespace aic_starlink :: core