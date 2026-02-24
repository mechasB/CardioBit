#pragma once
#include <cstdint>
#include "arm_math.h"

namespace CardioBit{
    static constexpr uint32_t BUFFER_SIZE = 200;

    class SharedData{
        public:
            // Raw buffer 
            static uint16_t adcRawBuffer[BUFFER_SIZE];
            // Signal prepared for filtering (float)
            float32_t ecgFloatBuffer[BUFFER_SIZE];
            static SharedData& getInstance();
        private:
            SharedData() = default;
    };
}