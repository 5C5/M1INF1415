import java.util.ArrayList;
import java.util.Iterator;


public class JeuDeBalle {

	public ArrayList<TortueAmelioree> equipe;
	public TortueBalle balle;
	
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
	}
	

}
