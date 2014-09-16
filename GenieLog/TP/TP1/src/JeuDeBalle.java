import java.util.ArrayList;


public class JeuDeBalle {

	public ArrayList<TortueAmelioree> equipe;
	public TortueBalle balle;
	
	public JeuDeBalle() {
		
		equipe = new ArrayList<TortueAmelioree>();
		Iterator<TortueAmelioree> it;
		for(int i = 0; i < 6; i++){
			
			equipe.add(new TortueAmelioree());
			it = equipe.iterator();
		}
	}

}
