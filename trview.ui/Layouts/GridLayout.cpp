#include "GridLayout.h"
#include <trview.ui/Control.h>

namespace trview
{
    namespace ui
    {
        void GridLayout::update_layout(Control& control)
        {
            const auto children = control.child_elements();

            const int columns = 2;
            const float column_width = control.size().width / 2.0f;

            float bottom_of_previous = 0;
            float previous_height = 0;
            float min_height = 20;

            for (std::size_t i = 0; i < children.size(); ++i)
            {
                int row = i / 2;
                int column = i - row * columns;

                if (column == 0)
                {
                    bottom_of_previous = previous_height;
                }
                else
                {
                    previous_height = std::max(min_height, std::max(children[i]->size().height, previous_height));
                }

                children[i]->set_position(Point(column_width * column, bottom_of_previous));
            }
        }
    }
}