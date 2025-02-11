#ifndef PONG_BAR_HPP
#define PONG_BAR_HPP
#include "odfaeg/Graphics/entity.h"
class Bar : public odfaeg::graphic::Entity {
    public :
        Bar(odfaeg::math::Vec2f position, odfaeg::math::Vec2f size);
        bool isLeaf() const {
            return true;
        }
        bool operator== (odfaeg::graphic::Entity& entity) {
            return false;
        }
        bool isAnimated() const {
            return false;
        }
        bool isModel() const {
            return false;
        }
        bool selectable() const {
            return false;
        }
        bool isLight() const {
            return false;
        }
        bool isShadow() const {
            return false;
        }
    private :

};
#endif
