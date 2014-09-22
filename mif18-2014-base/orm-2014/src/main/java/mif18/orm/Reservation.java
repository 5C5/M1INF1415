package mif18.orm;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Reservation {
	public static int insert_id=0;
	@Id
	private int id;
	private Seance seance;
	private int quantite;
	private Client client;
	public Reservation(int id,Seance seance,int quantite,Client client){
		
	}
	public Reservation(Seance seance,int quantite,Client client){
		this(insert_id++,seance,quantite,client);
	}
	public void setQuantite(int quantite){
		this.quantite=quantite;
	}
	public void save(Connection cnx) throws SQLException {
		PreparedStatement pstat=cnx.prepareStatement("INSERT INTO reservation(id,seance,salle,cinema,quantite,client) VALUES(?,?,?,?,?,?)");
		pstat.setInt(1,id);
		pstat.setTimestamp(2,seance.getDebut());
		pstat.setString(3,seance.getSalle().getNom());
		pstat.setString(4,seance.getCinema().getNom());
		pstat.executeUpdate();
	}
}