class vector3D
{
    private:
        double _x, _y, _z;

    public:
        vector3D(double x, double y, double z);
        ~vector3D() = default;

        // sqrt of x^2 + y^2 + z^2
        double norm() const;
};