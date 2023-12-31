#pragma once

#include <cstdint>
#include <vector>

class WaveBuffer {
public:
    WaveBuffer(uint32_t channels, uint32_t length);

    void Reset();
    uint32_t GetBufferOffset();
    uint32_t GetBufferSize();
    float *GetBuffer();
    uint32_t PopSamples(uint32_t size, bool resetIndex);
    uint32_t PopSamples(float *dest, uint32_t size, bool resetIndex);
    int PushSamples(float *source, uint32_t size);
    int PushZeros(uint32_t size);
    float *PushZerosGetBuffer(uint32_t size);
    void SetBufferOffset(uint32_t offset);

private:
    std::vector<float> buffer;
    uint32_t index;
    uint32_t channels;
};


