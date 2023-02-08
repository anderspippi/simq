/*
              __ __ __
             |__|__|  | __
             |  |  |  ||__|
  ___ ___ __ |  |  |  |
 |   |   |  ||  |  |  |    Ubiquitous Internet @ IIT-CNR
 |   |   |  ||  |  |  |    C++ quantum routing libraries and tools
 |_______|__||__|__|__|    https://github.com/ccicconetti/quantum-routing

Licensed under the MIT License <http://opensource.org/licenses/MIT>
Copyright (c) 2022 C. Cicconetti <https://ccicconetti.github.io/>

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "QuantumRouting/mecqkdnetwork.h"

#include "Support/tostring.h"

#include <glog/logging.h>

namespace uiiit {
namespace qr {

std::vector<MecQkdAlgo> allMecQkdAlgos() {
  static const std::vector<MecQkdAlgo> myAlgos({
      MecQkdAlgo::Random,
      MecQkdAlgo::Spf,
      MecQkdAlgo::BestFit,
      MecQkdAlgo::RandomFeas,
      MecQkdAlgo::SpfFeas,
      MecQkdAlgo::BestFitFeas,
  });
  return myAlgos;
}

std::string toString(const MecQkdAlgo aAlgo) {
  switch (aAlgo) {
    case MecQkdAlgo::Random:
      return "random";
    case MecQkdAlgo::Spf:
      return "spf";
    case MecQkdAlgo::BestFit:
      return "bestfit";
    case MecQkdAlgo::RandomFeas:
      return "randomfeas";
    case MecQkdAlgo::SpfFeas:
      return "spffeas";
    case MecQkdAlgo::BestFitFeas:
      return "bestfitfeas";
    default:; /* fall-through */
  }
  return "unknown";
}

MecQkdAlgo mecQkdAlgofromString(const std::string& aAlgo) {
  if (aAlgo == "random") {
    return MecQkdAlgo::Random;
  } else if (aAlgo == "bestfit") {
    return MecQkdAlgo::BestFit;
  } else if (aAlgo == "spf") {
    return MecQkdAlgo::Spf;
  } else if (aAlgo == "randomfeas") {
    return MecQkdAlgo::RandomFeas;
  } else if (aAlgo == "bestfitfeas") {
    return MecQkdAlgo::BestFitFeas;
  } else if (aAlgo == "spffeas") {
    return MecQkdAlgo::SpfFeas;
  }
  throw std::runtime_error(
      "invalid edge QKD algorithm: " + aAlgo + " (valid options are: " +
      ::toString(allMecQkdAlgos(),
                 ",",
                 [](const auto& aAlgo) { return toString(aAlgo); }) +
      ")");
}

MecQkdNetwork::MecQkdNetwork(
    const std::vector<std::pair<unsigned long, unsigned long>>& aEdges,
    support::RealRvInterface&                                   aWeightRv,
    const bool aMakeBidirectional)
    : CapacityNetwork(aEdges, aWeightRv, aMakeBidirectional) {
  // noop
}

MecQkdNetwork::MecQkdNetwork(const WeightVector& aEdgeWeights)
    : CapacityNetwork(aEdgeWeights) {
  // noop
}

} // namespace qr
} // namespace uiiit
