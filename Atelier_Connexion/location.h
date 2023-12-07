#ifndef LOCATION_H
#define LOCATION_H


class Location
{
    float idl;
    float longitude;
    float latitude;

public:
    Location();
    bool ajouter_loc(int colisId);

};

#endif // LOCATION_H
