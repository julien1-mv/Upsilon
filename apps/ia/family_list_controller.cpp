#include "family_list_controller.h"
#include <apps/i18n.h>

namespace Ia {

FamilyListController::FamilyListController(Responder * parentResponder) :
  ViewController(parentResponder),
  m_tableView(this, this, this),
  m_optionsController(this, &m_inputController),
  m_inputController(this)
{
}

const char * FamilyListController::title() {
  return I18n::translate(I18n::Message::IaChooseFamily);
}

StackViewController * FamilyListController::stack() {
  return static_cast<StackViewController *>(parentResponder());
}

void FamilyListController::didBecomeFirstResponder() {
  if (selectedRow() < 0) {
    selectCellAtLocation(0, 0);
  }
  Container::activeApp()->setFirstResponder(&m_tableView);
}

void FamilyListController::willDisplayCellForIndex(HighlightCell * cell, int index) {
  static_cast<MessageTableCellWithChevron<> *>(cell)->setMessage(familyAtIndex(index).name);
}

bool FamilyListController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::OK || event == Ion::Events::EXE || event == Ion::Events::Right) {
    int family = selectedRow();
    if (familyAtIndex(family).numberOfOptions > 0) {
      m_optionsController.setFamily(family);
      stack()->push(&m_optionsController);
    } else {
      m_inputController.setRequest(family, -1);
      stack()->push(&m_inputController);
    }
    return true;
  }
  return false;
}

}
