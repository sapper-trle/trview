#include "ILayout.h"
#include "AbsoluteLayout.h"

namespace trview
{
    namespace ui
    {
        ILayout::~ILayout()
        {
        }

        std::unique_ptr<ILayout> create_default_layout()
        {
            return std::make_unique<AbsoluteLayout>();
        }
    }
}
