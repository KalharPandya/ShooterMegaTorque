#include <positionalnew.h>

bool forwardChecker();
bool BackwardChecker();
#include "./MegaTorque.h"

UniversalEncoder myEnc(18, 4, 1);
Motor m1(19,27,26);
positionalnew p1(&m1);
MegaTorque Mega(&p1);

int forwardLimitPin = 32;
int backwardLimitPin = 33;

double AggKp = 0.3, AggKi = 0, Aggkd = 0;
double SoftKp = 0.1, SoftKi = 0, Softkd = 0;
int MT_min = -255, MT_max = 255, MT_targetpulse = 0;

void initPID(){
    m1.setEncoder(&myEnc);
    // m1.setEncoder(2,3,-1);
    p1.setThreshold(500);
    p1.setOutputLimits(MT_min, MT_max);
    p1.setAggTunings(AggKp, AggKi, Aggkd);
    p1.setSoftTunings(SoftKp, SoftKi, Softkd);
    pinMode(forwardLimitPin, INPUT_PULLDOWN);
    pinMode(backwardLimitPin, INPUT_PULLDOWN);
}

void MTCompute(){
    Mega.compute();
}

bool forwardChecker()
{
    if (digitalRead(forwardLimitPin) == HIGH)
    {
        return true;
    }
    return false;
}
bool backwardChecker()
{
    if(digitalRead(backwardLimitPin)==HIGH){
        return true;
    }
    return false;
}

void load()
{
    while (!backwardChecker())
    {
        Mega.forward();
    }
    Mega.brakeMT();
}
void unload()
{
    while (!forwardChecker())
    {
        Mega.backward();
    }
    Mega.brakeMT();
}
