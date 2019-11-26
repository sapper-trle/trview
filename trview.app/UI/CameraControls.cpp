#include "CameraControls.h"

#include <trview.ui/GroupBox.h>
#include <trview.ui/Checkbox.h>
#include <trview.ui/Button.h>
#include <trview.ui/Slider.h>
#include <trview.ui/Label.h>
#include <trview.ui/StackPanel.h>
#include <trview.ui/Layouts/GridLayout.h>

namespace trview
{
    CameraControls::CameraControls(ui::Control& parent)
    {
        using namespace ui;

        auto camera_window = std::make_unique<GroupBox>(Size(150, 72), Colour::Transparent, Colour::Grey, L"Camera");
        camera_window->client_area()->set_layout(std::make_unique<GridLayout>(2));

        auto reset = std::make_unique<StackPanel>(Size(), Colour::Transparent, Size(2,0), StackPanel::Direction::Horizontal);
        auto reset_camera = std::make_unique<Button>(Size(16, 16));
        reset_camera->on_click += on_reset;
        reset->add_child(std::move(reset_camera));
        reset->add_child(std::move(std::make_unique<Label>(Size(40, 16), Colour::Transparent, L"Reset", 8, graphics::TextAlignment::Left, graphics::ParagraphAlignment::Centre)));

        auto orbit_camera = std::make_unique<Checkbox>(Colour::Transparent, L"Orbit");
        _token_store += orbit_camera->on_state_changed += [&](auto) { change_mode(CameraMode::Orbit); };

        auto free_camera = std::make_unique<Checkbox>(Colour::Transparent, L"Free");
        _token_store += free_camera->on_state_changed += [&](auto) { change_mode(CameraMode::Free); };

        auto axis_camera = std::make_unique<Checkbox>(Colour::Transparent, L"Axis");
        _token_store += axis_camera->on_state_changed += [&](auto) { change_mode(CameraMode::Axis); };

        camera_window->add_child(std::move(reset));
        _orbit = camera_window->add_child(std::move(orbit_camera));
        _free = camera_window->add_child(std::move(free_camera));
        _axis = camera_window->add_child(std::move(axis_camera));

        parent.add_child(std::move(camera_window));
    }

    // Set the current camera mode and raise the on_mode_selected event.
    // mode: The new camera mode.
    void CameraControls::change_mode(CameraMode mode)
    {
        set_mode(mode);
        on_mode_selected(mode);
    }

    // Set the current camera mode. This will not raise the on_mode_selected event.
    // mode: The camera mode to change to.
    void CameraControls::set_mode(CameraMode mode)
    {
        _orbit->set_state(mode == CameraMode::Orbit);
        _free->set_state(mode == CameraMode::Free);
        _axis->set_state(mode == CameraMode::Axis);
    }
}
