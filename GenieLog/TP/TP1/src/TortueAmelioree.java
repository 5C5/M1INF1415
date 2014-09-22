import java.awt.*;

import javax.swing.*;

import java.awt.event.*;
import java.util.*;
import java.io.*;


public class TortueAmelioree extends Tortue {

	private String nom;
	private static int numero = 0;
	private TortueBalle balle;
	
	private ArrayList <TortueAmelioree> listeTortue; 
	
	public TortueAmelioree (String s){
		
		nom = new String(s);
		balle = null;
		listeTortue = new ArrayList<TortueAmelioree>();
		
	}
	
	public TortueAmelioree (){
		
		numero ++;
		nom = new String("Franklin n°" + numero);
		listeTortue = new ArrayList<TortueAmelioree>();
	}

	public void setBalle(TortueBalle b){
		
		balle = b;
		balle.setPosition(this.getX(), this.getY());
	}
	
	public void passer(TortueAmelioree t){
		
		balle.setPossesseur(t);
		t.setBalle(balle);
		balle = null;
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
	
	public int distance(TortueAmelioree t){
		
		int distance = 0;
		if(!listeTortue.contains(t)){
			System.out.println("Erreur : tortue " + t.getNom() + "inconnue");
		}
		else {
			int i = this.getX();
			int j = this.getY();
			int k = t.getX();
			int l = t.getY();
			distance = (int)Math.round(Math.sqrt(Math.pow(i - k, 2) + Math.pow(j - l, 2)));
		}
		return distance;
	}
	
	public void avancer(int dist){
		
		super.avancer(dist);
		
		Iterator it = listeTortue.iterator();
		TortueAmelioree t;
		
		while(it.hasNext()){
			
			//System.out.println("Nombre de tortue connue par " + this.getNom() + " : " + listeTortue.size());
			
			//System.out.println("Test d'entre dans la boucle de la tortue "+ this.getNom());
			t = (TortueAmelioree)it.next();
			//System.out.println("Distance à " + t.getNom() + " est de " + this.distance(t));
			if(this.distance(t) < 15){
				
				if(balle != null){
					
					this.passer(t);
					System.out.println(this.getNom() + " passe à " + t.getNom() +"!");
					balle = null;
				}
			}
		}
		if(balle != null){
			
			balle.setPosition(this.getX(), this.getY());
		}
		
	}
}
