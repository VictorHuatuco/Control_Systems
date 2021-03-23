
#ifndef ADC_H
#define ADC_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types Definitions
*/

/**
 *  result size of an A/D conversion
 */

typedef uint16_t adc_result_t;

/**
 *  result type of a Double ADC conversion
 */
typedef struct
{
    adc_result_t adcResult1;
    adc_result_t adcResult2;
} adc_sync_double_result_t;


typedef enum
{
    channel_AN0 =  0x0,
    channel_Temp =  0x1D,
    channel_DAC =  0x1E,
    channel_FVR =  0x1F
} adc_channel_t;


void ADC_Initialize(void);


void ADC_SelectChannel(adc_channel_t channel);


void ADC_StartConversion(void);


 
bool ADC_IsConversionDone(void);


adc_result_t ADC_GetConversionResult(void);


adc_result_t ADC_GetConversion(adc_channel_t channel);


void ADC_TemperatureAcquisitionDelay(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//ADC_H
/**
 End of File
*/

