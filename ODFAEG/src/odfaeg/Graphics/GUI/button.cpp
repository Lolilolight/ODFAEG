#include "../../../../include/odfaeg/Graphics/GUI/button.hpp"
namespace odfaeg {
    namespace graphic {
        namespace gui {
            Button::Button(math::Vec3f position, math::Vec3f size, const Font* font, std::string t, RenderWindow& rw) :
                LightComponent(rw, position, size, size * 0.5f) {
                background = sf::Color::White;
                text.setFont(*font);
                text.setString(t);
                text.setColor(sf::Color::Black);
                text.setSize(size);
                unsigned int characterSize = size.y;
                text.setCharacterSize(characterSize);
                rect = RectangleShape(size);
                rect.setOutlineThickness(5.f);
                rect.setOutlineColor(sf::Color::Red);
            }
            void Button::clear() {
                if (background != rect.getFillColor())
                    rect.setFillColor(background);
            }
            void Button::setTextSize(unsigned int size) {
                text.setCharacterSize(size);
            }
            void Button::setTextColor(sf::Color color) {
                text.setColor(color);
            }
            void Button::recomputeSize() {
                unsigned int characterSize = getSize().y;
                text.setCharacterSize(characterSize);
                size = getSize();
            }
            void Button::onDraw(RenderTarget& target, RenderStates states) {
                if (size != getSize())
                    recomputeSize();
                text.setPosition(getPosition());
                rect.setPosition(getPosition());
                text.setSize(getSize());
                rect.setSize(getSize());
                target.draw(rect);
                target.draw(text);
            }
            std::string Button::getText() {
                return text.getString();
            }
            bool Button::isMouseInButton() {

                physic::BoundingBox bb = getGlobalBounds();
                //math::Vec2f mousePos = math::Vec2f(sf::Mouse::getPosition(getWindow()).x, sf::Mouse::getPosition(getWindow()).y);
                if (bb.isPointInside(mousePos)) {
                    return true;
                }
                return false;
            }
            void Button::addActionListener (ActionListener *al) {
                core::FastDelegate<bool> trigger(&Button::isMouseInButton, this);
                core::FastDelegate<void> slot(&ActionListener::actionPerformed,al, this);
                core::Action a (core::Action::EVENT_TYPE::MOUSE_BUTTON_PRESSED_ONCE, sf::Mouse::Left);
                core::Command cmd(a, trigger, slot);
                getListener().connect("CBUTTONCLICKED"+getText(), cmd);
            }
            void Button::onEventPushed (sf::Event event, RenderWindow& window) {
                if (&getWindow() == &window)
                    getListener().pushEvent(event);
            }
            void Button::onUpdate (RenderWindow* window, sf::Event& event) {
                if (&getWindow() == window) {
                    if (event.type == sf::Event::MouseButtonPressed
                        && event.mouseButton.button == sf::Mouse::Left) {
                        mousePos = math::Vec3f(event.mouseButton.x, event.mouseButton.y, 0);
                    }
                }
            }
            void Button::checkSubWindowEvents() {

            }
        }
    }
}