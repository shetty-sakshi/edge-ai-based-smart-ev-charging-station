#include "State.h"


String bayStatus = "FREE";
float voltage = 0.0, current = 0.0, power = 0.0, energyWh = 0.0, temperature = 0.0;

unsigned long sessionStartMs = 0;

//edge_ai variables
float predictedArrivalProb = 0.0;
int predictedDurationMin = 0.0;

int lastHourOfDay = 12;



String loadDecision = "Allow";
int throttleLevel = 100;
float predictionThreshold = 0.5 ; //00 to 1
int peakTariffStartHr = 18;
int peakTariffEndHr = 21;
bool overloadActive = false;
int overloadCurrentA = 16;
int maxStationLoadW = 3000;
int DUTY_CYCLE_WINDOW_MS = 2000;
bool manualOverrideActive = 0;

