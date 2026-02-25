#include "fir_filter.hpp"

namespace CardioBit {

const float32_t LowPassFilter::coeffs[TAP_NUM] = {
    -0.0018f, -0.0021f, -0.0016f, 0.0004f, 0.0051f, 0.0125f, 0.0221f, 0.0331f,
     0.0441f, 0.0538f, 0.0607f, 0.0642f, 0.0638f, 0.0595f, 0.0519f, 0.0419f,
     0.0419f, 0.0519f, 0.0595f, 0.0638f, 0.0642f, 0.0607f, 0.0538f, 0.0441f,
     0.0331f, 0.0221f, 0.0125f, 0.0051f, 0.0004f, -0.0016f, -0.0021f
};

LowPassFilter::LowPassFilter() {
    arm_fir_init_f32(&firInstance, TAP_NUM, (float32_t*)&coeffs[0], &state[0], 200);
}

void LowPassFilter::process(float32_t* input, float32_t* output, uint32_t blockSize) {
    arm_fir_f32(&firInstance, input, output, blockSize);
}

} // namespace CardioBit