#ifndef IA_INPUT_CONTROLLER_H
#define IA_INPUT_CONTROLLER_H

#include <escher.h>

namespace Ia {

/* Troisième écran : saisie de l'expression.
 * Étape 1 du développement : écran provisoire qui affiche la demande choisie. */
class InputController : public ViewController {
public:
  InputController(Responder * parentResponder);
  void setRequest(int family, int option);
  const char * title() override;
  View * view() override { return &m_view; }
  DisplayParameter displayParameter() override { return DisplayParameter::DoNotShowOwnTitle; }
  bool handleEvent(Ion::Events::Event event) override;
private:
  class ContentView : public View {
  public:
    ContentView();
    void setRequest(int family, int option);
    void drawRect(KDContext * ctx, KDRect rect) const override;
  private:
    int numberOfSubviews() const override { return 2; }
    View * subviewAtIndex(int index) override;
    void layoutSubviews(bool force = false) override;
    MessageTextView m_requestView;
    MessageTextView m_infoView;
  };
  ContentView m_view;
  int m_family;
};

}

#endif
