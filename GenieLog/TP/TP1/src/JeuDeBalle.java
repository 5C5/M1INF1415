import java.util.ArrayList;
import java.util.Iterator;


public class JeuDeBalle {

	private boolean actif = false;
	
	private ArrayList<TortueAmelioree> equipe;
	private TortueBalle balle;
	
	public JeuDeBalle() {
		
		equipe = new ArrayList<TortueAmelioree>();
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
		balle = new TortueBalle();
		equipe.get(-1).setBalle(balle);
	}
	
	public void lancer(){
		
		if (!actif){
			
			int nbre;
			for(TortueAmelioree t : equipe){
				
				nbre = (int)(Math.random() * 5);
				switch(nbre){
					case 0 :
						t.avancer(50);
						
					case 1 :
						t.reculer(50);
						t.droite(180);
						
					case 2 :
						t.droite((int)Math.random() * 90);
						t.avancer(50);
						
					case 3 : 
						t.gauche((int)Math.random() * 90);
						t.avancer(50);
					
					case 4 :
					
				}
			}
		}
	}
	

}
