
class Calculator
{
protected:
    float num1{0};
    float num2{0};

public:
    Calculator():num1(0),num2(0){}

    float add(float num1, float num2);

    float sub(float num1, float num2);

};


class EnhanceCalc : public Calculator
{
private:
    int num1{0};
    int num2{0};

public:

    int modulos (int num1, int num2);
};
