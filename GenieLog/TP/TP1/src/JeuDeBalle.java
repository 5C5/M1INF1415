import java.util.ArrayList;
import java.util.Iterator;


public class JeuDeBalle implements Runnable{

	private boolean actif;
	private int terrainX;
	private int terrainY;
	private ArrayList<TortueAmelioree> equipe;
	private TortueBalle balle;
	
	public JeuDeBalle(int xMax, int yMax) {
		
		//intialisation des paramètres de jeu
		equipe = new ArrayList<TortueAmelioree>();
		actif = false;
		terrainX = xMax;
		terrainY = yMax;
		
		//Ajout de l'equipe de Tortue
		TortueAmelioree t;
		Iterator<TortueAmelioree> it;
		
		for(int i = 0; i < 6; i++){
			
			t = new TortueAmelioree();
			it = equipe.iterator();
			
			while(it.hasNext()){
				
				it.next().ajouterTortue(t);
				t.ajouterTortue(it.next());
			}
			equipe.add(t);
		}
		
		//ajout de la balle
		balle = new TortueBalle();
		//On donne la balle à la dernière tortue ajoutée
		equipe.get(-1).setBalle(balle);
	}
	
	public void run(){
		
		int nbre, xSaved, ySaved, dirSaved;
		while(actif){
			for(TortueAmelioree t : equipe){
				
				boolean correct = false;
				while(!correct){
					
					nbre = (int)(Math.random() * 5);
					xSaved = t.getX();
					ySaved = t.getY();
					dirSaved = t.getDir();
					
					switch(nbre){
						case 0 :
							t.avancer(50);
							break;
							
						case 1 :
							t.reculer(50);
							t.droite(180);
							break;
							
						case 2 :
							t.droite((int)Math.random() * 90);
							t.avancer(50);
							break;
							
						case 3 : 
							t.gauche((int)Math.random() * 90);
							t.avancer(50);
							break;
						
						case 4 :
							break;
					}
					if(t.getX()< 0 || t.getX() > this.terrainX || t.getY() < 0 || t.getY() > terrainY){
						
						t.setPosition(xSaved, ySaved);
						t.setDir(dirSaved);
					}
					else{
						correct = true;
					}
				}
				
			}
		}
	}
	
	public void lancer(){
		
		if (!actif){
			
			
		}
		else {
			actif = false;
		}
	}
	
}