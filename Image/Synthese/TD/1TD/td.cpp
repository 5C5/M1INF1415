namespace std;
namespace CV;

class Maillage {

	Maillage::Maillage(const Vector<V> &nGeo, const Vector<int> &nTopo) : geom(nGeo), topo(nTopo) {}
	public :
		void translate(const V &t);
		void rotate(const Mat &m);
		void cube(const V &a, const V &b);
		void cylindre(const V &a, const V &B);	//intégrer les tableaux de normales

	protected :
		Vector<V> geom;
		Vector<int> topo;
}
		

static Maillage::translation(const V &t){
	for(int i = 0; i < geom.size(); i++){
		geom[i]+= t;
	}
}
static Maillage::rotation(const Mat &m){
	for(int i = 0; i < geom.size(); i ++){
		geom[i]*= m;
	}
}

static Maillage::cube(const V &a, const V &b){
	Vector<V> v;
	Vector<int> t;

	v.append(a);
	v.append(v(bx, ay, az));
	//Meme chose pour chacun des 8 sommets
	//Puis on ajoute les facettes :
	t.append(0);
	t.append(1);
	t.append(4);
	//(et ceci 12 fois)
	return Maillage(v, t);
}

