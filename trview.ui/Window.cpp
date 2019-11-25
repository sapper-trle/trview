#include "Window.h"

namespace trview
{
    namespace ui
    {
        Window::Window(const Size& size, const Colour& background_colour, std::unique_ptr<ILayout>&& layout)
            : Window(Point(), size, background_colour, std::move(layout))
        {
        }

        Window::Window(const Point& point, const Size& size, const Colour& background_colour, std::unique_ptr<ILayout>&& layout)
            : Control(point, size, std::move(layout)), _background_colour(background_colour)
        {
        }

        Colour Window::background_colour() const
        {
            return _background_colour;
        }

        void Window::set_background_colour(Colour colour)
        {
            _background_colour = colour;
            on_invalidate();
        }
    }
}
