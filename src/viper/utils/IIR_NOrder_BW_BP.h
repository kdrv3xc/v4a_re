#pragma once

#include "IIR_1st.h"
#include <vector>

class IIR_NOrder_BW_BP {
public:
    explicit IIR_NOrder_BW_BP(uint32_t order);

    void Mute();

    void setBPF(float highCut, float lowCut, uint32_t samplingRate);

    std::vector<IIR_1st> lowpass;
    std::vector<IIR_1st> highpass;
    uint32_t order;
};

inline float do_filter_bplp(IIR_NOrder_BW_BP *filt, float sample) {
    for (uint32_t idx = 0; idx < filt->order; idx++) {
        sample = do_filter(&filt->lowpass[idx], sample);
    }
    return sample;
}

inline float do_filter_bphp(IIR_NOrder_BW_BP *filt, float sample) {
    for (uint32_t idx = 0; idx < filt->order; idx++) {
        sample = do_filter(&filt->highpass[idx], sample);
    }
    return sample;
}

inline float do_filter_bp(IIR_NOrder_BW_BP *filt, float sample) {
    return do_filter_bphp(filt, do_filter_bplp(filt, sample));
}
