#ifndef IA_FAMILY_LIST_CONTROLLER_H
#define IA_FAMILY_LIST_CONTROLLER_H

#include <escher.h>
#include "families.h"
#include "options_controller.h"
#include "input_controller.h"

namespace Ia {

/* Premier écran de l'application : la liste des familles de calcul. */
class FamilyListController : public ViewController, public SimpleListViewDataSource, public SelectableTableViewDataSource {
public:
  FamilyListController(Responder * parentResponder);
  const char * title() override;
  View * view() override { return &m_tableView; }
  void didBecomeFirstResponder() override;
  bool handleEvent(Ion::Events::Event event) override;

  int numberOfRows() const override { return k_numberOfFamilies; }
  KDCoordinate cellHeight() override { return Metric::ParameterCellHeight; }
  HighlightCell * reusableCell(int index) override { return &m_cells[index]; }
  int reusableCellCount() const override { return k_numberOfFamilies; }
  void willDisplayCellForIndex(HighlightCell * cell, int index) override;
private:
  StackViewController * stack();
  SelectableTableView m_tableView;
  MessageTableCellWithChevron<> m_cells[k_numberOfFamilies];
  OptionsController m_optionsController;
  InputController m_inputController;
};

}

#endif
