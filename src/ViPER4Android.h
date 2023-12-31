#pragma once

// Source: https://github.com/vipersaudio/viperfx_core_binary/blob/master/viperfx_intf.h
// Updated parameters source: https://github.com/vipersaudio/viper4android_fx/blob/master/android_4.x/src/com/vipercn/viper4android_v2/service/ViPER4AndroidService.java

extern "C" {
// Command code
#define COMMAND_CODE_GET 0x01
#define COMMAND_CODE_SET 0x02

// Param get
#define PARAM_GET_ENABLED 1
#define PARAM_GET_CONFIGURE 2
#define PARAM_GET_STREAMING 3
#define PARAM_GET_SAMPLING_RATE 4
#define PARAM_GET_CONVOLUTION_KERNEL_ID 5
#define PARAM_GET_DRIVER_VERSION_CODE 6
#define PARAM_GET_DRIVER_VERSION_NAME 7
#define PARAM_GET_DISABLE_REASON 8
#define PARAM_GET_DISABLE_REASON_MESSAGE 9
#define PARAM_GET_CONFIG 10
#define PARAM_GET_ARCHITECTURE 11

// Param set
#define PARAM_SET_UPDATE_STATUS 0x9002
#define PARAM_SET_RESET_STATUS 0x9003

#define PARAM_CONVOLUTION_ENABLE 65538
#define PARAM_CONVOLUTION_PREPARE_BUFFER 65540
#define PARAM_CONVOLUTION_SET_BUFFER 65541
#define PARAM_CONVOLUTION_COMMIT_BUFFER 65542
#define PARAM_CONVOLUTION_CROSS_CHANNEL 65543

#define PARAM_HEADPHONE_SURROUND_ENABLE 65544
#define PARAM_HEADPHONE_SURROUND_STRENGTH 65545

#define PARAM_DDC_ENABLE 65546
#define PARAM_DDC_COEFFICIENTS 65547

#define PARAM_SPECTRUM_EXTENSION_ENABLE 65548
#define PARAM_SPECTRUM_EXTENSION_BARK 65549 // Bark is a scale like dB
#define PARAM_SPECTRUM_EXTENSION_BARK_RECONSTRUCT 65550

#define PARAM_FIR_EQUALIZER_ENABLE 65551
#define PARAM_FIR_EQUALIZER_BAND_LEVEL 65552

#define PARAM_FIELD_SURROUND_ENABLE 65553
#define PARAM_FIELD_SURROUND_WIDENING 65554
#define PARAM_FIELD_SURROUND_MID_IMAGE 65555
#define PARAM_FIELD_SURROUND_DEPTH 65556

#define PARAM_DIFFERENTIAL_SURROUND_ENABLE 65557
#define PARAM_DIFFERENTIAL_SURROUND_DELAY 65558

#define PARAM_REVERBERATION_ENABLE 0x10017
#define PARAM_REVERBERATION_ROOM_SIZE 0x10018
#define PARAM_REVERBERATION_ROOM_WIDTH 0x10019
#define PARAM_REVERBERATION_ROOM_DAMPENING 0x1001A
#define PARAM_REVERBERATION_ROOM_WET_SIGNAL 0x1001B
#define PARAM_REVERBERATION_ROOM_DRY_SIGNAL 0x1001C

#define PARAM_AUTOMATIC_GAIN_CONTROL_ENABLE 65565
#define PARAM_AUTOMATIC_GAIN_CONTROL_RATIO 65566
#define PARAM_AUTOMATIC_GAIN_CONTROL_VOLUME 65567
#define PARAM_AUTOMATIC_GAIN_CONTROL_MAX_SCALER 65568

#define PARAM_DYNAMIC_SYSTEM_ENABLE 65569
#define PARAM_DYNAMIC_SYSTEM_X_COEFFICIENTS 65570
#define PARAM_DYNAMIC_SYSTEM_Y_COEFFICIENTS 65571
#define PARAM_DYNAMIC_SYSTEM_SIDE_GAIN 65572
#define PARAM_DYNAMIC_SYSTEM_STRENGTH 65573

#define PARAM_FIDELITY_BASS_ENABLE 65574
#define PARAM_FIDELITY_BASS_MODE 65575
#define PARAM_FIDELITY_BASS_FREQUENCY 65576
#define PARAM_FIDELITY_BASS_GAIN 65577

#define PARAM_FIDELITY_CLARITY_ENABLE 65578
#define PARAM_FIDELITY_CLARITY_MODE 65579
#define PARAM_FIDELITY_CLARITY_GAIN 65580

#define PARAM_CURE_CROSS_FEED_ENABLED 65581
#define PARAM_CURE_CROSS_FEED_STRENGTH 65582

#define PARAM_TUBE_SIMULATOR_ENABLED 65583

#define PARAM_ANALOGX_ENABLE 65584
#define PARAM_ANALOGX_MODE 65585

#define PARAM_GATE_OUTPUT_VOLUME 65586
#define PARAM_GATE_CHANNEL_PAN 65587
#define PARAM_GATE_LIMIT 65588

#define PARAM_SPEAKER_OPTIMIZATION 65603

#define PARAM_FET_COMPRESSOR_ENABLE 65610
#define PARAM_FET_COMPRESSOR_THRESHOLD 65611
#define PARAM_FET_COMPRESSOR_RATIO 65612
#define PARAM_FET_COMPRESSOR_KNEE 65613
#define PARAM_FET_COMPRESSOR_AUTO_KNEE 65614
#define PARAM_FET_COMPRESSOR_GAIN 65615
#define PARAM_FET_COMPRESSOR_AUTO_GAIN 65616
#define PARAM_FET_COMPRESSOR_ATTACK 65617
#define PARAM_FET_COMPRESSOR_AUTO_ATTACK 65618
#define PARAM_FET_COMPRESSOR_RELEASE 65619
#define PARAM_FET_COMPRESSOR_AUTO_RELEASE 65620
#define PARAM_FET_COMPRESSOR_KNEE_MULTI 65621
#define PARAM_FET_COMPRESSOR_MAX_ATTACK 65622
#define PARAM_FET_COMPRESSOR_MAX_RELEASE 65623
#define PARAM_FET_COMPRESSOR_CREST 65624
#define PARAM_FET_COMPRESSOR_ADAPT 65625
#define PARAM_FET_COMPRESSOR_NO_CLIP 65626

}
