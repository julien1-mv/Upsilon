#ifndef IA_FAMILIES_H
#define IA_FAMILIES_H

#include <apps/i18n.h>

namespace Ia {

/* Une famille de calcul du menu IA et ses options.
 * Une famille sans option passe directement à l'écran de saisie. */
struct Family {
  I18n::Message name;
  const I18n::Message * options;
  int numberOfOptions;
};

constexpr int k_numberOfFamilies = 9;
const Family & familyAtIndex(int index);

}

#endif
