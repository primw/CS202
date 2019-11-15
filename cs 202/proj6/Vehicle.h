// Prim Wandeevong // CS 202 - Vehicle.h // 10-17-19 //
#ifndef VEHICLE_H
#define VEHICLE_H
using namespace std;

class Vehicle
{
    protected:
        float m_lla[3];

    private:
        virtual void serialize(ostream & os) const;

    public:
        Vehicle();
        Vehicle(const float* m_lla);    
        Vehicle(const Vehicle &obj);
        virtual ~Vehicle();
        void SetLLA(const float *lla);
        const float *getLLA() const;
        friend std::ostream & operator<<(ostream & os, const Vehicle & vehicle);
        void operator=(const Vehicle& other);
        virtual void Move(const float* lla) = 0;

};

#endif