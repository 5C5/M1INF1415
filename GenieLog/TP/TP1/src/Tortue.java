// package logo;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;


/*************************************************************************

version 2.1
	@date 25/09/2001

**************************************************************************/

/** La classe Tortue qui se deplace en coordonnees polaires
**/

public class Tortue
{
	// Classe interne : segment avec couleur
	protected class Segment {
		public Point ptStart, ptEnd;
		public Color color;
		
		public Segment() {
			ptStart = new Point(0,0);
			ptEnd = new Point(0,0);
		}
		
		public void drawSegment(Graphics graph) {
			if (graph==null)
				return;

			graph.setColor(color);
			graph.drawLine(ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
		}	
	}

	// Attributs statiques	
	protected static final int rp=10, rb=5; // Taille de la pointe et de la base de la fleche
	protected static final double ratioDegRad = 0.0174533; // Rapport radians/degres (pour la conversion)
	
	// Attributs
	protected ArrayList<Segment> listSegments; // Trace de la tortue
	
	protected int x, y;	// Coordonnees de la tortue
	protected int dir;	// Direction de la tortue (angle en degres)
	protected boolean crayon; // par defaut on suppose qu'on dessine
	protected int coul;
	
	// Methodes
	public void setColor(int n) {coul = n;}
	public int getColor() {return coul;}

	public Tortue() { // FeuilleDessin f) {
		// feuille = f;
		// feuille.addTortue(this);	
		listSegments = new ArrayList<Segment>();
		reset();
	}

	public void reset() {
		// on initialise la position de la tortue
		x = 0;
		y = 0;
		dir = -90;
		coul = 5;
		crayon = true;
		listSegments.clear();
  	}

	public void setPosition(int newX, int newY) {
		x = newX;
		y = newY;
	}
	
	
	public void drawTurtle (Graphics graph) {
		if (graph==null)
			return;
		
		// Dessine les segments
		for(Iterator it = listSegments.iterator();it.hasNext();) {
			Segment seg = (Segment) it.next();
			seg.drawSegment(graph);
		}

		//Calcule les 3 coins du triangle a partir de
		// la position de la tortue p
		Point p = new Point(x,y);
		Polygon arrow = new Polygon();

		//Calcule des deux bases
		//Angle de la droite
		double theta=ratioDegRad*(-dir);
		//Demi angle au sommet du triangle
		double alpha=Math.atan( (float)rb / (float)rp );
		//Rayon de la fleche
		double r=Math.sqrt( rp*rp + rb*rb );
		//Sens de la fleche

		//Pointe
		Point p2=new Point((int) Math.round(p.x+r*Math.cos(theta)),
						 (int) Math.round(p.y-r*Math.sin(theta)));
		arrow.addPoint(p2.x,p2.y);
		arrow.addPoint((int) Math.round( p2.x-r*Math.cos(theta + alpha) ),
		  (int) Math.round( p2.y+r*Math.sin(theta + alpha) ));

		//Base2
		arrow.addPoint((int) Math.round( p2.x-r*Math.cos(theta - alpha) ),
		  (int) Math.round( p2.y+r*Math.sin(theta - alpha) ));

		arrow.addPoint(p2.x,p2.y);
		graph.setColor(this.decodeColor(coul));
		graph.fillPolygon(arrow);
    }

	protected Color decodeColor(int c) {
		switch(c) {
			case 0: return(Color.black);
			case 1: return(Color.blue);
			case 2: return(Color.cyan);
			case 3: return(Color.darkGray);
			case 4: return(Color.red);
			case 5: return(Color.green);
			case 6: return(Color.lightGray);
			case 7: return(Color.magenta);
			case 8: return(Color.orange);
			case 9: return(Color.gray);
			case 10: return(Color.pink);
			case 11: return(Color.yellow);
			default : return(Color.black);
		}
	}

	/** les procedures de base de fonctionnement de la tortue */

	// avancer de n pas
	public void avancer(int dist) {
		int newX = (int) Math.round(x+dist*Math.cos(ratioDegRad*dir));
		int newY = (int) Math.round(y+dist*Math.sin(ratioDegRad*dir));
		
		if (crayon==true) {
			Segment seg = new Segment();
			
			seg.ptStart.x = x;
			seg.ptStart.y = y;
			seg.ptEnd.x = newX;
			seg.ptEnd.y = newY;
			seg.color = decodeColor(coul);
	
			listSegments.add(seg);
		}

		x = newX;
		y = newY;
	}
	
	public void reculer(int n){
		
		avancer(n * -1);
	}

	// aller a droite
	public void droite(int ang) {
		dir = (dir + ang) % 360;
	}

	// aller a gauche
	public void gauche(int ang) {
		dir = (dir - ang) % 360;
	}

	// baisser le crayon pour dessiner
	public void baisserCrayon() {
		crayon = true;
	}

	// lever le crayon pour ne plus dessiner
	public void leverCrayon() {
		crayon = false;
	}

	// pour changer de couleur de dessin
	public void couleur(int n) {
		coul = n % 12;
	}

	public void couleurSuivante() {
	 	couleur(coul+1);
	}

	/** quelques classiques */

	public void carre() {
		for (int i=0;i<4;i++) {
			avancer(100);
			droite(90);
		}
	}

	public void poly(int n, int a) {
		for (int j=0;j<a;j++) {
			avancer(n);
			droite(360/a);
		}
	}
	
	public void maison() {
		
		for (int i = 1; i < 3; i ++){
			gauche(45 * i);
			avancer(71);
		}
		gauche(135);
		carre();
	}
	
	public void etoile(int n, int t){
		
		for(int i = 0; i < n; i ++){
			avancer(t);
			reculer(t);
			droite(360/n);
		}
	}

	public void spiral(int n, int k, int a) {
		for (int i = 0; i < k; i++) {
			couleur(coul+1);
			avancer(n);
			droite(360/a);
			n = n+1;
		}
	}
}
