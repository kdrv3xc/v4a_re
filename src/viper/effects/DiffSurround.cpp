#include <cstring>
#include "DiffSurround.h"
#include "../constants.h"

DiffSurround::DiffSurround() : buffers({
    WaveBuffer(1, 0x1000),
    WaveBuffer(1, 0x1000)
}) {
    this->samplingRate = VIPER_DEFAULT_SAMPLING_RATE;
    this->delayTime = 0.0f;
    this->enable = false;
    Reset();
}

void DiffSurround::Process(float *samples, uint32_t size) {
    if (!this->enable) return;

    float *bufs[2];
    float *outbufs[2];

    bufs[0] = this->buffers[0].PushZerosGetBuffer(size);
    bufs[1] = this->buffers[1].PushZerosGetBuffer(size);

    for (uint32_t i = 0; i < size * 2; i++) {
        bufs[i % 2][i / 2] = samples[i];
    }

    outbufs[0] = this->buffers[0].GetBuffer();
    outbufs[1] = this->buffers[1].GetBuffer();

    for (uint32_t i = 0; i < size * 2; i++) {
        samples[i] = outbufs[i % 2][i / 2];
    }

    this->buffers[0].PopSamples(size, false);
    this->buffers[1].PopSamples(size, false);
}

void DiffSurround::Reset() {
    this->buffers[0].Reset();
    this->buffers[1].Reset();

    this->buffers[1].PushZeros((uint32_t) ((double) this->delayTime / 1000.0 * (double) this->samplingRate));
}

void DiffSurround::SetDelayTime(float delayTime) {
    if (this->delayTime != delayTime) {
        this->delayTime = delayTime;
        this->Reset();
    }
}

void DiffSurround::SetEnable(bool enable) {
    if (this->enable != enable) {
        if (!this->enable) {
            Reset();
        }
        this->enable = enable;
    }
}

void DiffSurround::SetSamplingRate(uint32_t samplingRate) {
    if (this->samplingRate != samplingRate) {
        this->samplingRate = samplingRate;
        this->Reset();
    }
}
