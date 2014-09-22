package mif18.orm;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Client {
	private static int insert_num_client=0;
	@Id
	private int num_client;
	private String nom;
	public Client(String nom){
		this.nom=nom;
		this.num_client=insert_num_client++;
	}
	public Client(int num_client,String nom){
		this.num_client=num_client;
		this.nom=nom;
	}
	public void setNom(String nom){
		this.nom=nom;
	}
	public String getNom(){
		return nom;
	}
	public void save(Connection cnx) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("INSERT INTO client(num_client,nom) VALUES(?,?)");
    	pstat.setInt(1,num_client);
    	pstat.setString(2,nom);
    	pstat.executeUpdate();
    }
	public void update(Connection cnx) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("UPDATE client SET nom=? WHERE num_client=?");
    	pstat.setString(1,nom);
    	pstat.setInt(2,num_client);
    	pstat.executeUpdate();
    }
    public static Client getByNum_client(Connection cnx,int num_client) throws SQLException {
    	PreparedStatement pstat=cnx.prepareStatement("SELECT nom FROM nom WHERE num_client=?");
    	pstat.setInt(1,num_client);
    	ResultSet rs=pstat.executeQuery();
    	if(rs.next()){
    		return new Client(num_client,rs.getString(1));
    	} else {
    		return null;
    	}
    }
}