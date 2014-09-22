package mif18.orm;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Timestamp;

public class Seance {
	private Timestamp debut,fin;
	private String film;
	private Cinema cinema;
	private Salle salle;
	public Seance(Timestamp debut,Timestamp fin,Salle salle,String film,Cinema cinema){
		this.debut=debut;
		this.fin=fin;
		this.salle=salle;
		this.film=film;
		this.cinema=cinema;
	}
	public Timestamp getDebut(){
		return debut;
	}
	public Salle getSalle(){
		return salle;
	}
	public Cinema getCinema(){
		return cinema;
	}
	public void save(Connection cnx) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("INSERT INTO seance(debut,fin,salle,film,cinema) VALUES(?,?,?,?,?)");
    	pstat.setTimestamp(1,debut);
    	pstat.setTimestamp(2,fin);
    	pstat.setString(3,salle.getNom());
    	pstat.setString(4,film);
    	pstat.setString(5,cinema.getNom());
    	pstat.executeUpdate();
    }
//    public void update(Connection cnx) throws SQLException {
//    	PreparedStatement pstat=cnx.prepareStatement("UPDATE Cinema SET nom=? ")
//    	pstat.executeUpdate();
//    }
//    public static Cinema getByNom(Connection cnx,String nom) throws SQLException {
//    	PreparedStatement pstat=cnx.prepareStatement("SELECT nom,adresse FROM cinema WHERE nom=?");
//    	pstat.setString(1,nom);
//    	ResultSet rs=pstat.executeQuery();
//    	if(rs.next()){
//    		return new Cinema(rs.getString(1),rs.getString(2));
//    	} else {
//    		return null;
//    	}
//    }
}
