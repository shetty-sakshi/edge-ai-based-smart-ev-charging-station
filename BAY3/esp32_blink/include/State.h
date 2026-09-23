#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
// ---------------------------------------------------------------------
// Live bay state
// ---------------------------------------------------------------------
extern String bayStatus;
extern float voltage, current, power, energyWh, temperature;

extern unsigned long sessionStartMs;
extern float predictedArrivalProb;
extern int predictedDurationMin;
extern int lastHourOfDay;


extern String loadDecision;
extern int throttleLevel;
extern float predictionThreshold; //00 to 1
extern int peakTariffStartHr;
extern int peakTariffEndHr;
extern bool overloadActive;
extern int overloadCurrentA;
extern int maxStationLoadW;
extern int DUTY_CYCLE_WINDOW_MS;
extern bool manualOverrideActive;






#endif