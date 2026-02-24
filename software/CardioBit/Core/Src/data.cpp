#include "data.hpp"

namespace CardioBit::Data {
    uint16_t adcRawBuffer[BUFFER_SIZE];
    float32_t ecgFloatBuffer[BUFFER_SIZE];
    EcgResults currentResults = {0.0f, 0.0f};
}