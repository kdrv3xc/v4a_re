#include "MinPhaseIIRCoeffs.h"
#include "../constants.h"
#include <cmath>

// Iscle: Verified with the latest version at 13/12/2022

static const float MIN_PHASE_IIR_COEFFS_FREQ_10BANDS[] = {
        31.0,
        62.0,
        125.0,
        250.0,
        500.0,
        1000.0,
        2000.0,
        4000.0,
        8000.0,
        16000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_15BANDS[] = {
        25.0,
        40.0,
        63.0,
        100.0,
        160.0,
        250.0,
        400.0,
        630.0,
        1000.0,
        1600.0,
        2500.0,
        4000.0,
        6300.0,
        10000.0,
        16000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_25BANDS[] = {
        20.0,
        31.5,
        40.0,
        50.0,
        80.0,
        100.0,
        125.0,
        160.0,
        250.0,
        315.0,
        400.0,
        500.0,
        800.0,
        1000.0,
        1250.0,
        1600.0,
        2500.0,
        3150.0,
        4000.0,
        5000.0,
        8000.0,
        10000.0,
        12500.0,
        16000.0,
        20000.0
};

static const float MIN_PHASE_IIR_COEFFS_FREQ_31BANDS[] = {
        20.0,
        25.0,
        31.5,
        40.0,
        50.0,
        63.0,
        80.0,
        100.0,
        125.0,
        160.0,
        200.0,
        250.0,
        315.0,
        400.0,
        500.0,
        630.0,
        800.0,
        1000.0,
        1250.0,
        1600.0,
        2000.0,
        2500.0,
        3150.0,
        4000.0,
        5000.0,
        6300.0,
        8000.0,
        10000.0,
        12500.0,
        16000.0,
        20000.0
};

MinPhaseIIRCoeffs::MinPhaseIIRCoeffs() {
    this->coeffs = nullptr;
    this->bands = 0;
}

MinPhaseIIRCoeffs::~MinPhaseIIRCoeffs() {
    delete[] this->coeffs;
}

void MinPhaseIIRCoeffs::Find_F1_F2(double param_2, double param_3, double *param_4, double *param_5) {
    double x = pow(2.0, param_3 / 2.0);
    *param_4 = param_2 / x;
    *param_5 = param_2 * x;
}

double *MinPhaseIIRCoeffs::GetCoefficients() {
    return this->coeffs;
}

float MinPhaseIIRCoeffs::GetIndexFrequency(uint32_t index) {
    switch (this->bands) {
        case 10:
            return MIN_PHASE_IIR_COEFFS_FREQ_10BANDS[index];
        case 15:
            return MIN_PHASE_IIR_COEFFS_FREQ_15BANDS[index];
        case 25:
            return MIN_PHASE_IIR_COEFFS_FREQ_25BANDS[index];
        case 31:
            return MIN_PHASE_IIR_COEFFS_FREQ_31BANDS[index];
        default:
            return 0.0;
    }
}

int MinPhaseIIRCoeffs::SolveRoot(double param_2, double param_3, double param_4, double *param_5) {
    double x = (param_4 - (param_3 * param_3) / (param_2 * 4.0)) / param_2;
    double y = param_3 / (param_2 + param_2);

    if (x >= 0.0) {
        return -1;
    }

    double z = sqrt(-x);
    double a = -y - z;
    double b = z - y;
    if (a > b) {
        *param_5 = b;
    } else {
        *param_5 = a;
    }

    return 0;
}

int MinPhaseIIRCoeffs::UpdateCoeffs(uint32_t bands, uint32_t samplingRate) {
    if (bands != 10 && bands != 15 && bands != 25 && bands != 31) {
        return 0;
    }

    this->bands = bands;

    delete[] this->coeffs;
    this->coeffs = new double[bands * 4](); // TODO: Check this array size, original type: float

    const float *bandFreqs;
    double tmp;

    switch (bands) {
        case 10:
            bandFreqs = MIN_PHASE_IIR_COEFFS_FREQ_10BANDS;
            tmp = 3.0 / 3.0;
            break;
        case 15:
            bandFreqs = MIN_PHASE_IIR_COEFFS_FREQ_15BANDS;
            tmp = 2.0 / 3.0;
            break;
        case 25:
            bandFreqs = MIN_PHASE_IIR_COEFFS_FREQ_25BANDS;
            tmp = 1.0 / 3.0;
            break;
        case 31:
            bandFreqs = MIN_PHASE_IIR_COEFFS_FREQ_31BANDS;
            tmp = 1.0 / 3.0;
            break;
    }

    for (uint32_t i = 0; i < bands; i++) {
        double ret1;
        double ret2;

        Find_F1_F2(bandFreqs[i], tmp, &ret2, &ret1);

        double x = (2.0 * M_PI * (double) bandFreqs[i]) / (double) samplingRate;
        double y = (2.0 * M_PI * ret2) / (double) samplingRate;

        double cosX = cos(x);
        double cosY = cos(y);
        double sinY = sin(y);

        double a = cosX * cosY;
        double b = cosX * cosX / 2.0;
        double c = sinY * sinY;

        double d = ((b - a) + 0.5) - c;
        double e = c + (((b + cosY * cosY) - a) - 0.5);
        double f = (((cosX * cosX) * 0.125 - cosX * cosY * 0.25) + 0.125) - c * 0.25;

        if (SolveRoot(d, e, f, &ret1) == 0) {
            this->coeffs[i * 4] = ret1 + ret1;
            this->coeffs[i * 4 + 1] = 0.5 - ret1;
            this->coeffs[i * 4 + 2] = (ret1 + 0.5) * cosX * 2.0;
        }
    }

    return 1;
}
