/*
 * File:   PID.c
 * Author: Victor Huatuco
 *
 * Created on 18 de febrero de 2021, 05:43 AM
 */


#include <xc.h>
#include "Configuracion.h"
#include "PID.h"


float PID(float pid_in) {  //pid_in es el valor del sensor del loop convertida a la magnitud de la variable
    error = set_point - pid_in;
    up = kp*error;
    ui = ui_ + (ki * t_muestreo*error);
    ud = kd * (error - error_)/t_muestreo;
    ut = up + ui + ud; // es la salida del PID
    if (ut > max) ut=max;
    if (ut > min) ut=min;
    ui_ = ui;
    error_ = error;
    return ut;
}
