package mif18.orm;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.persistence.Entity;
import javax.persistence.Id;

/**
 * Created by ecoquery on 18/09/2014.
 */
@Entity
public class Cinema {

    @Id
    private String nom;
    private String adresse;

    public Cinema(String nom) {
        this.nom = nom;
    }
    public Cinema(String nom,String adresse){
    		this.nom=nom;
    		this.adresse=adresse;
    }

    protected Cinema() {}

    public String getAdresse() {
        return adresse;
    }

    public void setAdresse(String adresse) {
        this.adresse = adresse;
    }
    public String getNom(){
    	return nom;
    }
    public void setNom(String nom){
    	this.nom=nom;
    }
    public void save(Connection cnx) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("INSERT INTO cinema(nom,adresse) VALUES(?,?)");
    	pstat.setString(1,nom);
    	pstat.setString(2,adresse);
    	pstat.executeUpdate();
    }
    public void update(Connection cnx) throws SQLException {
//    	PreparedStatement pstat=cnx.prepareStatement("UPDATE Cinema SET nom=? ")
//    	pstat.executeUpdate();
    }
    public static Cinema getByNom(Connection cnx,String nom) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("SELECT nom,adresse FROM cinema WHERE nom=?");
    	pstat.setString(1,nom);
    	ResultSet rs=pstat.executeQuery();
    	if(rs.next()){
    		return new Cinema(rs.getString(1),rs.getString(2));
    	} else {
    		return null;
    	}
    }
}
