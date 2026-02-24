#pragma once
//Includes
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include <cstdint>
#include "arm_math.h"

namespace CardioBit {

static constexpr uint32_t BUFFER_SIZE = 200;

struct EcgResults {
    float32_t bpm;
    float32_t heartRateVariability;
};

namespace Data {
    extern uint16_t adcRawBuffer[BUFFER_SIZE];
    extern float32_t ecgFloatBuffer[BUFFER_SIZE];
    extern EcgResults currentResults;
}

} // namespace CardioBit