#include "app.h"
#include "ia_icon.h"
#include "apps/apps_container.h"
#include "apps/i18n.h"

namespace Ia {

I18n::Message App::Descriptor::name() {
  return I18n::Message::IaApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::IaAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::IaIcon;
}

App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

App::App(Snapshot * snapshot) :
  ::App(snapshot, &m_stackViewController),
  m_familyListController(&m_stackViewController),
  m_stackViewController(&m_modalViewController, &m_familyListController)
{
}

}
