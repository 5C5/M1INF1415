package mif18.orm;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Salle {
	private String nom;
	private Cinema cinema;
	private int capacite;
	public Salle(String nom,int capacite){
		this.nom=nom;
		this.capacite=capacite;
	}
	public Salle(String nom,Cinema cinema,int capacite){
		this(nom,capacite);
		this.cinema=cinema;
	}
	public void setCapacite(int capacite){
		this.capacite=capacite;
	}
	public int getCapacite(){
		return capacite;
	}
	public void setNom(String nom){
		this.nom=nom;
	}
	public String getNom(){
		return nom;
	}
	public void setCinema(Connection cnx,String cinema) throws SQLException {
		this.cinema=Cinema.getByNom(cnx,cinema);
	}
	public Cinema getCinema(){
		return cinema;
	}
	public void save(Connection cnx) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("INSERT INTO salle(nom,cinema,capacite) VALUES(?,?,?)");
    	pstat.setString(1,nom);
    	pstat.setString(2,cinema.getNom());
    	pstat.setInt(3,capacite);
    	pstat.executeUpdate();
    }
    public void update(Connection cnx) throws SQLException {
//    	PreparedStatement pstat=cnx.prepareStatement("UPDATE Cinema SET nom=? ")
//    	pstat.executeUpdate();
    }
    public static Salle getByNom(Connection cnx,String nom) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("SELECT nom,cinema,capacite FROM salle WHERE nom=?");
    	pstat.setString(1,nom);
    	ResultSet rs=pstat.executeQuery();
    	if(rs.next()){
    		return new Salle(rs.getString(1),Cinema.getByNom(cnx,rs.getString(2)),rs.getInt(3));
    	} else {
    		return null;
    	}
    }
}