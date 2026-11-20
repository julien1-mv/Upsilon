#include "input_controller.h"
#include "families.h"
#include <apps/i18n.h>
#include <escher/palette.h>

namespace Ia {

InputController::ContentView::ContentView() :
  m_requestView(KDFont::LargeFont, (I18n::Message)0, 0.5f, 0.5f, Palette::PrimaryText, Palette::BackgroundApps),
  m_infoView(KDFont::SmallFont, I18n::Message::IaInputComingSoon, 0.5f, 0.5f, Palette::SecondaryText, Palette::BackgroundApps)
{
}

void InputController::ContentView::setRequest(int family, int option) {
  const Family & f = familyAtIndex(family);
  m_requestView.setMessage(option >= 0 ? f.options[option] : f.name);
}

void InputController::ContentView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(bounds(), Palette::BackgroundApps);
}

View * InputController::ContentView::subviewAtIndex(int index) {
  return index == 0 ? static_cast<View *>(&m_requestView) : static_cast<View *>(&m_infoView);
}

void InputController::ContentView::layoutSubviews(bool force) {
  KDCoordinate h = bounds().height();
  KDCoordinate w = bounds().width();
  m_requestView.setFrame(KDRect(0, h / 2 - 30, w, 30), force);
  m_infoView.setFrame(KDRect(0, h / 2 + 4, w, 20), force);
}

InputController::InputController(Responder * parentResponder) :
  ViewController(parentResponder),
  m_family(0)
{
}

void InputController::setRequest(int family, int option) {
  m_family = family;
  m_view.setRequest(family, option);
}

const char * InputController::title() {
  return I18n::translate(familyAtIndex(m_family).name);
}

bool InputController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::Left) {
    static_cast<StackViewController *>(parentResponder())->pop();
    return true;
  }
  return false;
}

}
