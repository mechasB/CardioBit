#include "data.hpp"

namespace CardioBit {
SharedData& SharedData::getInstance() {
    static SharedData instance;
    return instance;
 }
}