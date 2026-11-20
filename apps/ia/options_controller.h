#ifndef IA_OPTIONS_CONTROLLER_H
#define IA_OPTIONS_CONTROLLER_H

#include <escher.h>
#include "families.h"
#include "input_controller.h"

namespace Ia {

/* Deuxième écran : les options de la famille choisie (ordre, type...). */
class OptionsController : public ViewController, public SimpleListViewDataSource, public SelectableTableViewDataSource {
public:
  OptionsController(Responder * parentResponder, InputController * inputController);
  void setFamily(int family);
  const char * title() override;
  View * view() override { return &m_tableView; }
  void didBecomeFirstResponder() override;
  bool handleEvent(Ion::Events::Event event) override;

  int numberOfRows() const override;
  KDCoordinate cellHeight() override { return Metric::ParameterCellHeight; }
  HighlightCell * reusableCell(int index) override { return &m_cells[index]; }
  int reusableCellCount() const override { return k_maxNumberOfOptions; }
  void willDisplayCellForIndex(HighlightCell * cell, int index) override;
private:
  constexpr static int k_maxNumberOfOptions = 6;
  SelectableTableView m_tableView;
  MessageTableCellWithChevron<> m_cells[k_maxNumberOfOptions];
  InputController * m_inputController;
  int m_family;
};

}

#endif
