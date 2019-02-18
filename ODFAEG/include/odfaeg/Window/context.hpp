#ifndef ODFAEG_CONTEXT_HPP
#define ODFAEG_CONTEXT_HPP
#include "iContext.hpp"
#include "contextFactory.hpp"
namespace odfaeg {
    namespace window {
        class Context {
            public :
                Context();
                Context(ContextSettings settings, unsigned int width, unsigned int height);
                Context(sf::WindowHandle handle);
                void create (ContextSettings settings, unsigned int width, unsigned int height);
                void create (sf::WindowHandle handle);
                void display();
                void setVerticalSyncEnabled(bool enabled);
                bool setActive(bool active);
                const ContextSettings& getSettings() const;
            private :
                IContext* m_context;
        };
    }
}
#endif