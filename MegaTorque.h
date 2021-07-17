class MegaTorque
{

public:
    positionalnew *mt;
    bool break_enable = false;
    MegaTorque(positionalnew *_mt)
    {
        mt = _mt;
    }

    void compute()
    {
        if (break_enable){
            mt->compute();
        }           
    }
    void brakeMT(){
        break_enable = true;
        mt->mtr->reset();
    }
    void noBreak(){
        break_enable = false;
    }
    void forward(){
        noBreak();
        mt->mtr->setPWM(255);
        
    }
    void backward(){
        noBreak();
        mt->mtr->setPWM(-255);
    }

};