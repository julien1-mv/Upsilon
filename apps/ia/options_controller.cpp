#include "options_controller.h"
#include <apps/i18n.h>
#include <assert.h>

namespace Ia {

OptionsController::OptionsController(Responder * parentResponder, InputController * inputController) :
  ViewController(parentResponder),
  m_tableView(this, this, this),
  m_inputController(inputController),
  m_family(0)
{
}

void OptionsController::setFamily(int family) {
  m_family = family;
  assert(familyAtIndex(family).numberOfOptions <= k_maxNumberOfOptions);
  selectCellAtLocation(0, 0);
  m_tableView.reloadData();
}

const char * OptionsController::title() {
  return I18n::translate(familyAtIndex(m_family).name);
}

void OptionsController::didBecomeFirstResponder() {
  if (selectedRow() < 0) {
    selectCellAtLocation(0, 0);
  }
  Container::activeApp()->setFirstResponder(&m_tableView);
}

int OptionsController::numberOfRows() const {
  return familyAtIndex(m_family).numberOfOptions;
}

void OptionsController::willDisplayCellForIndex(HighlightCell * cell, int index) {
  static_cast<MessageTableCellWithChevron<> *>(cell)->setMessage(familyAtIndex(m_family).options[index]);
}

bool OptionsController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::OK || event == Ion::Events::EXE || event == Ion::Events::Right) {
    m_inputController->setRequest(m_family, selectedRow());
    static_cast<StackViewController *>(parentResponder())->push(m_inputController);
    return true;
  }
  if (event == Ion::Events::Left) {
    static_cast<StackViewController *>(parentResponder())->pop();
    return true;
  }
  return false;
}

}
