/*!
 * @defgroup HSC SENSOR API
 * @{*/
#ifndef HSC_H_
#define HSC_H_

#define OUTPUT_MAX     (1<<13)
#define OUTPUT_MIN     (1<<2)
#define PRESSURE_MAX    100000.0
#define PRESSURE_MIN    200.0

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif
int hsc_get_data(float *pressure,float *temperature);
#ifdef __cplusplus
}
#endif 
#endif 
/** @}*/
