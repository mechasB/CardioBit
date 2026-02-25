#pragma once
#include "data.hpp"

namespace CardioBit {

class LowPassFilter {
public:
    static constexpr uint32_t TAP_NUM = 31;
    
    LowPassFilter();
    void process(float32_t* input, float32_t* output, uint32_t blockSize);

private:
    arm_fir_instance_f32 firInstance;
    float32_t state[TAP_NUM + 200]; 
    
    static const float32_t coeffs[TAP_NUM];
};

} // namespace CardioBit