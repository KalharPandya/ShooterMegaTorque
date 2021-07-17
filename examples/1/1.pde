#include <ShooterMegaTorque.h>
void setup(){
    Serial.begin(115200);
    initPID();
    Mega.forward();
    delay(200);
    Mega.breakMT();
}

void loop(){
    MTCompute();
    Serial.print(forwardChecker());
    Serial.println(backwardChecker());
}