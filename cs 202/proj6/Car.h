// Prim Wandeevong // CS 202 - Car.h // 10-17-19 //
#ifndef CAR_H
#define CAR_H

using namespace std;

class Car : public Vehicle 
{
    private:
        virtual void serialize(ostream& os) const;
        int m_throttle;

    protected:
    //yeet

    public:
        Car();
        Car(const float* lla);
        Car(const Car& obj);
        virtual ~Car();

        void setThrottle(const int throttle);
        const int getThrottle() const;

        virtual void Move(const float* lla);
        void drive(const int throttle);
        void operator=(const Car &other);

};

#endif