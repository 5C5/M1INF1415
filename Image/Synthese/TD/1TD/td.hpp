namespace std;
namespace CV;


#include <QVector3D>
#include <QVector2D>

class Maillage {

    Maillage::Maillage(const Vector<QVector3D> &nGeo, const Vector<int> &nTopo) : geom(nGeo), topo(nTopo) {}

	protected :
		Vector<V> geom;
		Vector<Vector3D>
        Vector<int> topo;

    public:
        Maillage();
        ~Maillage();
        void zero();
        void translate(const V &t);
        void rotate(const Mat &m);
        void cube(const V &a, const V &b);
        void cylindre(const V &a, const V &B);

        void loadFromOBJ(const QString&);
        void writeIntoOBJ(const QString&);

        //void box(qreal, qreal, qreal);
        void cone(const QVector3D&, qreal, const QVector3D&);
        void cone(const QVector3D&, qreal, qreal);
        void cylinder(const QVector3D&, qreal, qreal);
        void sphere(const QVector3D&, qreal);
        void torus(const QVector3D&, qreal, qreal);
}
