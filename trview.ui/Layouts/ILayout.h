#pragma once

#include <memory>

namespace trview
{
    namespace ui
    {
        class Control;

        struct ILayout
        {
            virtual ~ILayout() = 0;

            /// To be called when the layout needs to be updated - this can be
            /// when a control has been added or removed.
            /// @param control The control to lay out.
            virtual void update_layout(Control& control) = 0;
        };

        std::unique_ptr<ILayout> create_default_layout();
    }
}