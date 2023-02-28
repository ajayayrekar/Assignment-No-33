/*5. Create a base class called Photon. Use this class to store double type value of
wavelength that could be used to calculate photon energy. Create class
calculate_photonEnergy which will photon energy.
Using these classes, calculate photon energy.*/

#include <iostream>
#include <cmath>
using namespace std;

class Photon {
protected:
    double wavelength;

public:
    Photon(double w) : wavelength(w) {}

    double get_wavelength() {
        return wavelength;
    }
};

class CalculatePhotonEnergy : public Photon {
public:
    CalculatePhotonEnergy(double w) : Photon(w) {}

    double calculate_energy() {
        const double h = 6.626e-34; // Planck's constant
        const double c = 2.998e8; // Speed of light

        double frequency = c / wavelength;
        double energy = h * frequency;
        return energy;
    }
};

int main() {
    double wavelength;
    cout << "Enter wavelength (in meters): ";
    cin >> wavelength;

    CalculatePhotonEnergy photon(wavelength);
    double energy = photon.calculate_energy();

    cout << "Photon energy: " << energy << " Joules" << endl;

    return 0;
}
