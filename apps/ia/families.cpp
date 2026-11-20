#include "families.h"
#include <assert.h>

namespace Ia {

using M = I18n::Message;

static constexpr M k_derivativeOptions[] = {M::IaOrder1, M::IaOrder2, M::IaOrderN, M::IaPartialDerivative};
static constexpr M k_integralOptions[] = {M::IaSimpleIntegral, M::IaDoubleIntegral, M::IaTripleIntegral};
static constexpr M k_odeOptions[] = {M::IaOrder1, M::IaOrder2, M::IaOrder1WithCondition, M::IaOrder2WithConditions};
static constexpr M k_equationOptions[] = {M::IaOneUnknown, M::IaTwoUnknowns, M::IaThreeUnknowns};
static constexpr M k_limitOptions[] = {M::IaLimitAtPoint, M::IaLimitPlusInfinity, M::IaLimitMinusInfinity, M::IaLimitLeft, M::IaLimitRight};
static constexpr M k_matrixOptions[] = {M::IaDeterminant, M::IaInverse, M::IaEigenvalues};

#define IA_COUNT(a) static_cast<int>(sizeof(a) / sizeof(a[0]))

static const Family k_families[k_numberOfFamilies] = {
  {M::IaDerivative, k_derivativeOptions, IA_COUNT(k_derivativeOptions)},
  {M::IaAntiderivative, nullptr, 0},
  {M::IaIntegral, k_integralOptions, IA_COUNT(k_integralOptions)},
  {M::IaDifferentialEquation, k_odeOptions, IA_COUNT(k_odeOptions)},
  {M::IaEquation, k_equationOptions, IA_COUNT(k_equationOptions)},
  {M::IaLimit, k_limitOptions, IA_COUNT(k_limitOptions)},
  {M::IaTaylorExpansion, nullptr, 0},
  {M::IaMatrix, k_matrixOptions, IA_COUNT(k_matrixOptions)},
  {M::IaHistory, nullptr, 0},
};

const Family & familyAtIndex(int index) {
  assert(index >= 0 && index < k_numberOfFamilies);
  return k_families[index];
}

}
