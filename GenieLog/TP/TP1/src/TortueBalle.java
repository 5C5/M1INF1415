import java.awt.Graphics;
import java.awt.Polygon;
import java.util.Iterator;

//import Tortue.Segment;


public class TortueBalle extends Tortue {

	public TortueBalle() {
		// TODO Stub du constructeur généré automatiquement
	}
	
	public void drawTurtle(Graphics graph){
		
		for(Iterator it = super.listSegments.iterator();it.hasNext();) {
			Segment seg = (Segment) it.next();
			seg.drawSegment(graph);
		}
		graph.fillOval(this.x -5, this.y -5, 10, 10);
		
		
	}

}
