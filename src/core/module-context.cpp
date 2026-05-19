#include "../aic-starlink/core/module_context.h"

namespace aic_starlink :: core 
{
    ModuleContext :: ModuleContext() = default; 

    ModuleContext :: ModuleContext(ModuleConfig config)
    {
        m_config = move(config); 
    }

    ModuleConfig &ModuleContext :: config() noexcept
    {
        return m_config; 
    }

    Logger &ModuleContext :: logger() noexcept 
    {
        return m_logger; 
    }

    const Logger &ModuleContext :: logger() const noexcept 
    {
        return m_logger; 
    }

    void ModuleContext :: setConfig(ModuleConfig cfg)
    {
        m_config = move(cfg);
    }
}