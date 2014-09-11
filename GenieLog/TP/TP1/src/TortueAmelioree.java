import java.awt.*;

import javax.swing.*;

import java.awt.event.*;
import java.util.*;
import java.io.*;


public class TortueAmelioree extends Tortue {

	private String nom;
	private static int numero = 0;
	
	private ArrayList <TortueAmelioree> listeTortue; 
	
	public TortueAmelioree (String s){
		
		nom = new String(s);
		listeTortue = new ArrayList<TortueAmelioree>();
		
	}
	public TortueAmelioree (){
		
		numero ++;
		nom = new String("Franklin n°" + numero);
		listeTortue = new ArrayList<TortueAmelioree>();
	}
	
	public int getX(){
		
		return this.x;
	}
	public int getY(){
		
		return this.y;
	}
	
	public String getNom(){
		
		return nom;
	}
	
	public void afficherNom(){
		
		System.out.println("Je m'appelle " + nom);
	}
	
	public void ajouterTortue(TortueAmelioree t){
		
		listeTortue.add(t);
	}
	
	public void enleverTortue(Tortue t){
		
		listeTortue.remove(t);
	}
	
	public double distance(TortueAmelioree t){
		
		double distance = 0;
		if(!listeTortue.contains(t)){
			System.out.println("Erreur : tortue " + t.getNom() + "inconnue");
		}
		else {
			double i = this.getX();
			double j = this.getY();
			double k = t.getX();
			double l = t.getY();
			distance = Math.sqrt(Math.pow(i - j, 2) + Math.pow(k - l, 2));
			//System.out.println("La distance entre les deux tortues est " + distance);
		}
		return distance;
	}
	
	public void avancer(int dist){
		
		super.avancer(dist);
		
		Iterator it = listeTortue.iterator();
		
		while(it.hasNext()){
			
			TortueAmelioree t = (TortueAmelioree)it.next();
			
			if(this.distance(t) < 15){
				
				System.out.println("Salut, " + t.getNom());
				t.reculer(50);
			}
		}
	}
}
